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
    final_camino = grafo->getFinalNode(finalPosition);
    cout << BolsaNodos->lastNode()->getID() << "-";
    while(Pathbuilding());
    
    BolsaNodos->add_node(final_camino);
    cout << BolsaNodos->lastNode()->getID() << endl;
    return BolsaNodos->getCamino();
}


bool PathPlanning::Pathbuilding(){
    std::vector<conexos*> conexos = BolsaNodos->lastNode()->getConexos();
    float F, heuristica, BestF = -1;
    int select_conexo = 0;
    for (int i=0; i<conexos.size(); i++) {
        
        if (BolsaNodos->HasNode(conexos[i]->ID)) continue;
        heuristica = EasyMath::EcuCalcularDistancia(final_camino->getPosition(), conexos[i]->posicion);
        F = heuristica + conexos[i]->peso;
        if(BestF!=-1 && BestF<F) continue;
        
        BestF = F;
        select_conexo = conexos[i]->ID;
    }
    GraphNode * resultante = grafo->getNode(select_conexo);
    if (final_camino == resultante)
        return false;
    
    cout << resultante->getID() << "-";
    BolsaNodos->add_node(resultante);
    return true;
    
}

void PathPlanning::Revalorar(){
    /*
     RECALCULAR EL CAMINO VALORANDO QUE CADA NODO DEL MISMO ES UN NODO FINAL Y VERIFICANDO SI HAY MEJOR FORMA DE ALCANZARLO
     */
}

void NodeOpenBag::add_node(GraphNode* nodo){
    camino.push_back(nodo);
}
GraphNode * NodeOpenBag::lastNode(){
    return camino[camino.size()-1];
}
NodeOpenBag::NodeOpenBag(GraphNode* initialNode){
    camino.push_back(initialNode);
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
    return false;
}
