//
//  PathPlanning.cpp
//  PathPlanning
//
//  Created by Gaspar Rodriguez Valero on 2/2/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#include "PathPlanning.hpp"

PathPlanning::PathPlanning(Graph* grafo){
    this->grafo = new Graph(grafo);
}

PathPlanning::PathPlanning(Graph* grafo,dvector2D initialPosition,dvector2D finalPosition){
    this->grafo = new Graph(grafo);
    obtenerCamino(initialPosition, finalPosition);
}

PathPlanning::~PathPlanning(){
    delete grafo;
    delete BolsaNodos;
    final_camino = nullptr;
    delete final_camino;
}

std::vector<dvector3D> PathPlanning::obtenerCamino(dvector2D initialPosition,dvector2D finalPosition){
    BolsaNodos = new NodeOpenBag(grafo->getInitialNode(initialPosition));
    aux = initialPosition;
    final_camino = grafo->getFinalNode(finalPosition);
    
    while(Pathbuilding());
    
    //while (Pathbuilding2(BolsaNodos, final_camino,true));
    
    // CODIGO DEBUG
    
    for (int i=0; i<BolsaNodos->getNodes().size(); i++) {
        cout << BolsaNodos->getNodes()[i]->getID() << "-" ;
    }
    cout << endl;
    
    return BolsaNodos->getCamino();
}

bool PathPlanning::Pathbuilding2(NodeOpenBag * bolsaNodos, GraphNode * Nfinal,bool reiterativo){
    
    std::vector<conexos*> conexos = BolsaNodos->lastNode()->getConexos();
    float F, heuristica, BestF = -1;
    int select_conexo = 0;
    int choosenOne = 0;
    for (int i=0; i<conexos.size(); i++) {
        
        if (BolsaNodos->HasNode(conexos[i]->ID)) continue;
        
        heuristica = EasyMath::EucCalcularDistancia(final_camino->getPosition(), conexos[i]->posicion);
        F = heuristica + conexos[i]->peso;
        
        if(BestF!=-1 && BestF<F) continue;
        
        choosenOne = i;
        BestF = F;
        select_conexo = conexos[i]->ID;
    }
    
    BolsaNodos->peso += conexos[choosenOne]->peso;
    GraphNode * resultante = grafo->getNode(select_conexo);
    BolsaNodos->add_node(resultante);
    
    if (final_camino == resultante)
        return false;
    
    if(reiterativo){
        
        NodeOpenBag * BolsaNodosAux = new NodeOpenBag(bolsaNodos->firstNode());
        BolsaNodosAux->setDescartes(BolsaNodos->getDescartes());
        GraphNode * AUX = Nfinal;
        final_camino = BolsaNodos->lastNode();
        while (Pathbuilding2(BolsaNodosAux, final_camino,false));
        final_camino = AUX;
        AUX = nullptr;
    
        if(BolsaNodosAux->peso<BolsaNodos->peso)
            BolsaNodos->rebuild(BolsaNodosAux);
        
        /*
        cout << "PESO AUX: " << BolsaNodosAux->peso << " | PESO : " << BolsaNodos->peso << endl;
        */
        
        delete BolsaNodosAux;
    }
    
    
    return true;
}

bool PathPlanning::Pathbuilding(){
    std::vector<conexos*> conexos = BolsaNodos->lastNode()->getConexos();
    float F, heuristica, BestF = -1;
    int select_conexo = 0;
    int choosenOne = 0;
    for (int i=0; i<conexos.size(); i++) {
        
        if (BolsaNodos->HasNode(conexos[i]->ID)) continue;
        
        heuristica = EasyMath::EucCalcularDistancia(final_camino->getPosition(), conexos[i]->posicion);
        F = heuristica + conexos[i]->peso;
        
        if(BestF!=-1 && BestF<F) continue;
        
        choosenOne = i;
        BestF = F;
        select_conexo = conexos[i]->ID;
    }
    BolsaNodos->peso += conexos[choosenOne]->peso;
    GraphNode * resultante = grafo->getNode(select_conexo);
    BolsaNodos->add_node(resultante);
    
    if (final_camino == resultante)
        return false;
    
    
    
    
    NodeOpenBag * BolsaNodosAux = new NodeOpenBag(grafo->getInitialNode(aux));
    BolsaNodosAux->setDescartes(BolsaNodos->getDescartes());
    GraphNode * AUX = final_camino;
    final_camino = BolsaNodos->lastNode();
    while (Revalorar(BolsaNodosAux));
    final_camino = AUX;
    AUX = nullptr;
    
    cout << "PESO AUX: " << BolsaNodosAux->peso << " | PESO : " << BolsaNodos->peso << endl;
    
    if(BolsaNodosAux->peso<BolsaNodos->peso)
        BolsaNodos->rebuild(BolsaNodosAux);
    
    delete BolsaNodosAux;
    
    
    return true;
    
}

bool PathPlanning::Revalorar(NodeOpenBag* BolsaNodosAux){
    std::vector<conexos*> conexos = BolsaNodosAux->lastNode()->getConexos();
    
    float F, heuristica, BestF = -1;
    int select_conexo = 0;
    int choosenOne = 0;
    for (int i=0; i<conexos.size(); i++) {
        
        if (BolsaNodosAux->HasNode(conexos[i]->ID)) continue;
        
        heuristica = EasyMath::EucCalcularDistancia(final_camino->getPosition(), conexos[i]->posicion);
        F = heuristica + conexos[i]->peso;
        
        if(BestF!=-1 && BestF<F) continue;
        
        choosenOne = i;
        BestF = F;
        select_conexo = conexos[i]->ID;
        
    }
    BolsaNodosAux->peso += conexos[choosenOne]->peso;
    GraphNode * resultante = grafo->getNode(select_conexo);
    BolsaNodosAux->add_node(resultante);
    
    if (final_camino == resultante)
        return false;
    return true;
}

void NodeOpenBag::add_node(GraphNode* nodo){camino.push_back(nodo);}


NodeOpenBag::NodeOpenBag(GraphNode* initialNode){
    camino.push_back(initialNode);
    peso = 0.f;
}

NodeOpenBag::~NodeOpenBag(){
    camino.clear();
}
std::vector<dvector3D> NodeOpenBag::getCamino(){
    std::vector<dvector3D> posCamino;
    dvector3D aux(0,0,0);
    for (int i=0; i<camino.size(); i++) {
        aux = camino[i]->getPosition();
        posCamino.push_back(aux);
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
    for (int i=0; i<camino.size(); i++)
        descartes.push_back(camino[i]);
    
    camino.clear();
    camino = AUX->getNodes();
    for (int i=0; i<descartes.size(); i++)
        for (int j=0; j<camino.size(); j++)
            if(descartes[i]->getID()==camino[j]->getID())
                descartes.erase(descartes.begin()+i);
    
    
    this->peso = AUX->peso;
}
void NodeOpenBag::setDescartes(std::vector<GraphNode *> discards){
    descartes=discards;
}
