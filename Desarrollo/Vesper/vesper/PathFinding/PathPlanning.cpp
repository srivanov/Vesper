//
//  PathPlanning.cpp
//  PathPlanning
//
//  Created by Gaspar Rodriguez Valero on 2/2/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//



#include "PathPlanning.hpp"
#include "../mundoBox2D.hpp"


PathPlanning::PathPlanning(){}

PathPlanning::~PathPlanning(){
    if(m_grafo)
        delete m_grafo;
    if(BolsaNodos)
        delete BolsaNodos;
}

PathPlanning * PathPlanning::instance(){
    static PathPlanning pinstance;
    return &pinstance;
}
void PathPlanning::init(Graph * grafo){
    m_grafo = grafo;
}

void PathPlanning::inicializarBolsaNodos(){
    construirbolsa();
    vaciarBolsa();
}
void PathPlanning::vaciarBolsa(){
    if(BolsaNodos)
        BolsaNodos->clean();
    
}
void PathPlanning::construirbolsa(){
    if(BolsaNodos) return;
    BolsaNodos = new NodeOpenBag;
}

bool PathPlanning::NeedCalculo(dvector3D *initialPosition,dvector3D * finalPosition){
    
    dvector3D pos = *BolsaNodos->lastNode()->getPosition();
    float DistanciaPrimerNodo = EasyMath::EucCalcularDistancia(pos, *initialPosition);
    float DistanciaObjetivo = EasyMath::EucCalcularDistancia(*initialPosition, *finalPosition);
    if(DistanciaPrimerNodo>DistanciaObjetivo) return false;
    return true;
}
std::vector<dvector3D> PathPlanning::obtenerCamino(dvector3D *initialPosition,dvector3D * finalPosition){
    
    bool HayMuro = mundoBox2D::Instance()->raycastContact(*initialPosition, *finalPosition);
    
    // CREA VARIABLE QUE CONTENDRA EL CAMINO
    std::vector<dvector3D> camino;
    
    // SI NO HAY OBSTACULOS ENTRE EL INICIO Y LA POSICION FINAL
    if(HayMuro){
    
    // INICIALIZAR BOLSA DE NODOS
    inicializarBolsaNodos();
    // AÑADE NODO INICIAL
    BolsaNodos->add_node(m_grafo->getNearNode(initialPosition));
    
    //GUARDA LA POSICION INICIAL EN LA VARIABLE AUX
    aux = initialPosition;
    
    //BUSCA NODO FINAL
    final_camino = m_grafo->getNearNode(finalPosition);
    
    
    //VALORA SI ES NECESARIO USAR PATHFINDING
        if(NeedCalculo(initialPosition,finalPosition)){
            try {
                while(Pathbuilding());
            } catch (N_Errores e) {
                std::string ERROR = " ### ERROR ### ";
                if(e==no_way)   ERROR+= " NO ENCONTRO CAMINO";
                if(e==fail)     ERROR+= " FALLO AL CALCULAR";
                std::cout << ERROR << " ### ERROR ### " << std::endl;
            
            }
                // AÑADE NODO FINAL
                BolsaNodos->add_node(final_camino);
            
                final_camino = nullptr;
            
                // AÑADO TODOS LOS NODOS DE LA BOLSA AL CAMINO
                camino = BolsaNodos->getCamino();
        
        
            //DEBUG MOSTRAR CAMINO
        /*
            for (int i=0; i<BolsaNodos->getNodes().size(); i++) {
                cout << BolsaNodos->getNodes()[i]->getID() << "-" ;
            }
            cout << endl;
        */
        
            }
    }
    
    // AÑADIR POSICION FINAL
    camino.push_back(finalPosition);
    return camino;
}

bool PathPlanning::CalcularSiguienteNodo(NodeOpenBag* bolsa){
    
    if(bolsa->getNodes().empty())
        throw fail;
    std::vector<conexos*> conexos = bolsa->lastNode()->getConexos();
    
    
    
    float F, heuristica, BestF = -1;
    int select_conexo = 0, choosenOne = 0;
    for (int i=0; i<conexos.size(); i++) {
        
        if (bolsa->HasNode(conexos[i]->ID)) continue;
        heuristica = EasyMath::EucCalcularDistancia(*final_camino->getPosition(), *conexos[i]->posicion);
        F = heuristica + conexos[i]->peso;
        if(BestF!=-1 && BestF<F) continue;
        choosenOne = i;
        BestF = F;
        select_conexo = conexos[i]->ID;
    }
    
    if (select_conexo == 0){
        bolsa->disable_node(bolsa->lastNode()->getID());
        return true;
    }
    
    
    bolsa->peso += conexos[choosenOne]->peso;
    GraphNode * resultante = m_grafo->getNode(select_conexo);
    
    if (final_camino == resultante)
        return false;
    
    
    bolsa->add_node(resultante);
    return true;
}

bool PathPlanning::EvaluarCamino(){
    /*
    NodeOpenBag BolsaNodosAux;
    
    BolsaNodosAux.add_node(m_grafo->getInitialNode(aux));
    
    BolsaNodosAux.PassDescartes(BolsaNodos);
    
    GraphNode * AUX = final_camino;
    final_camino = BolsaNodos->lastNode();
    while (CalcularSiguienteNodo(&BolsaNodosAux));
    final_camino = AUX;
    */
    
    return true;
    
}

bool PathPlanning::Pathbuilding(){
    
    if(!CalcularSiguienteNodo(BolsaNodos)) return false;
    EvaluarCamino();
        
    return true;
}



void NodeOpenBag::add_node(GraphNode* nodo){
    camino.push_back(nodo);
}
GraphNode * NodeOpenBag::lastNode(){
    return camino[camino.size()-1];
}
NodeOpenBag::NodeOpenBag(){
    peso = 0.f;
}

void NodeOpenBag::clean(){
    camino.clear();
    descartes.clear();
    peso = 0.f;
}

NodeOpenBag::~NodeOpenBag(){
    camino.clear();
}


std::vector<dvector3D> NodeOpenBag::getCamino(){
    std::vector<dvector3D> posCamino;
    for (int i=0; i<camino.size(); i++) {
        posCamino.push_back(*camino[i]->getPosition());
    }
    return posCamino;
}

bool NodeOpenBag::HasNode(int& ID){
    for (int i=0; i<camino.size(); i++) {
        if (camino[i]->getID()==ID)
            return true;
    }
    for (int i=0; i<descartes.size(); i++) {
        if (descartes[i]->getID()==ID)
            return true;
    }
    return false;
}

void NodeOpenBag::disable_node(int ID){
    for (int i=0; i<camino.size(); i++) {
        if(camino[i]->getID()==ID){
            descartes.push_back(camino[i]);
            camino.erase(camino.begin()+i);
            return;
        }
    }
}
void NodeOpenBag::setDescartes(std::vector<GraphNode *> discards){
    descartes=discards;
}

