//
//  PathPlanning.cpp
//  PathPlanning
//
//  Created by Gaspar Rodriguez Valero on 2/2/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//



#include "PathPlanning.hpp"



PathPlanning::PathPlanning(){
    //this->grafo = new Graph(grafo);
}

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
    
    dvector3D prueba = *BolsaNodos->lastNode()->getPosition();
    float DistanciaPrimerNodo = EasyMath::EucCalcularDistancia(*BolsaNodos->lastNode()->getPosition(), *initialPosition);
    float DistanciaObjetivo = EasyMath::EucCalcularDistancia(*initialPosition, *finalPosition);
    if(DistanciaPrimerNodo>DistanciaObjetivo) return false;
    return true;
}
std::vector<dvector3D*> PathPlanning::obtenerCamino(dvector3D *initialPosition,dvector3D * finalPosition){
    
    // INICIALIZAR BOLSA DE NODOS
    inicializarBolsaNodos();
    // AÑADE NODO INICIAL
    BolsaNodos->add_node(m_grafo->getInitialNode(initialPosition));
    
    //GUARDA LA POSICION INICIAL EN LA VARIABLE AUX
    aux = initialPosition;
    
    //BUSCA NODO FINAL
    final_camino = m_grafo->getFinalNode(finalPosition);
    
    // CREA VARIABLE QUE CONTENDRA EL CAMINO
    std::vector<dvector3D*> camino;
    
    //VALORA SI ES NECESARIO USAR PATHFINDING
    if(NeedCalculo(initialPosition,finalPosition)){
    
            while(Pathbuilding());
        
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
    
    
    
    // AÑADIR POSICION FINAL
    camino.push_back(finalPosition);
    return camino;
}

bool PathPlanning::CalcularSiguienteNodo(NodeOpenBag* bolsa){
    
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
    
    if (select_conexo == 0) throw 0;
    
    bolsa->peso += conexos[choosenOne]->peso;
    GraphNode * resultante = m_grafo->getNode(select_conexo);
    
    if (final_camino == resultante)
        return false;
    
    
    bolsa->add_node(resultante);
    return true;
}

bool PathPlanning::EvaluarCamino(){
    NodeOpenBag BolsaNodosAux;
    
    BolsaNodosAux.add_node(m_grafo->getInitialNode(aux));
    
    BolsaNodosAux.PassDescartes(BolsaNodos);
    
    GraphNode * AUX = final_camino;
    final_camino = BolsaNodos->lastNode();
    while (CalcularSiguienteNodo(&BolsaNodosAux));
    final_camino = AUX;
    
    
    //if(BolsaNodosAux.peso<BolsaNodos->peso)
        //BolsaNodos->rebuild(&BolsaNodosAux);
    
    
    
    return true;
    
}

bool PathPlanning::Pathbuilding(){
    
    try {
        if(!CalcularSiguienteNodo(BolsaNodos)) return false;
        EvaluarCamino();
        
    } catch (int e) {
        if(e==no_way)
            return false;
    }
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

void NodeOpenBag::PassDescartes(NodeOpenBag * bolsaAux){
    this->setDescartes(bolsaAux->getDescartes());
}

std::vector<dvector3D*> NodeOpenBag::getCamino(){
    std::vector<dvector3D*> posCamino;
    for (int i=0; i<camino.size(); i++) {
        posCamino.push_back(camino[i]->getPosition());
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
void NodeOpenBag::rebuild(NodeOpenBag * AUX){
    
    camino.swap(descartes);
    AUX->getNodes().swap(camino);
    
    size_t Tdescartes = descartes.size();
    size_t Tcamino = camino.size();
    
    vector<int> recoverNodos;
    
    for (size_t i = 0 ; i < Tdescartes ; i++) {
        int IDdescarte = descartes[i]->getID();
        for (size_t j = 0 ; j < Tcamino ; j++) {
            if(camino[j]->getID()==IDdescarte)
                recoverNodos.push_back(IDdescarte);
        }
    }
    
    for (int i = 0; i < descartes.size(); i++) {
        if(recoverNodos.empty()) return;
        if(descartes[i]->getID()==recoverNodos[0]){
            descartes.erase(descartes.begin()+i);
            i--;
        }
    }
    
    
}
void NodeOpenBag::setDescartes(std::vector<GraphNode *> discards){
    descartes=discards;
}
