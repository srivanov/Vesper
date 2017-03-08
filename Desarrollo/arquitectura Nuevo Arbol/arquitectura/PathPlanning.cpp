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
}

std::vector<dvector3D> PathPlanning::obtenerCamino(dvector3D initialPosition,dvector3D finalPosition){
    dvector2D Pinicial(initialPosition.x,initialPosition.y);
    dvector2D Pfinal(finalPosition.x,finalPosition.y);
    BolsaNodos = new NodeOpenBag(grafo->getInitialNode(Pinicial));
    aux = Pinicial;
    final_camino = grafo->getFinalNode(Pfinal);
    
    while(Pathbuilding());
    
    BolsaNodos->add_node(final_camino);
    /*
    
    for (int i=0; i<BolsaNodos->getNodes().size(); i++) {
        cout << BolsaNodos->getNodes()[i]->getID() << "-" ;
    }
    cout << endl;
     */
    return BolsaNodos->getCamino();
}
std::vector<dvector3D> PathPlanning::obtenerCamino(dvector2D initialPosition,dvector2D finalPosition){
    BolsaNodos = new NodeOpenBag(grafo->getInitialNode(initialPosition));
    aux = initialPosition;
    final_camino = grafo->getFinalNode(finalPosition);
    
    while(Pathbuilding());
    
    BolsaNodos->add_node(final_camino);
    /*
     
     for (int i=0; i<BolsaNodos->getNodes().size(); i++) {
     cout << BolsaNodos->getNodes()[i]->getID() << "-" ;
     }
     cout << endl;
     */
    return BolsaNodos->getCamino();
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
    
    if (final_camino == resultante)
        return false;
    
    
    BolsaNodos->add_node(resultante);
    
    NodeOpenBag * BolsaNodosAux = new NodeOpenBag(grafo->getInitialNode(aux));
    BolsaNodosAux->setDescartes(BolsaNodos->getDescartes());
    GraphNode * AUX = final_camino;
    final_camino = BolsaNodos->lastNode();
    while (Revalorar(BolsaNodosAux));
    final_camino = AUX;
    
    //cout << "PESO AUX: " << BolsaNodosAux->peso << " | PESO : " << BolsaNodos->peso << endl;
    
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

void NodeOpenBag::add_node(GraphNode* nodo){
    camino.push_back(nodo);
}
GraphNode * NodeOpenBag::lastNode(){
    return camino[camino.size()-1];
}
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
    for (int i=0; i<camino.size(); i++) {
        descartes.push_back(camino[i]);
    }
    camino.clear();
    camino = AUX->getNodes();
    for (int i=0; i<descartes.size(); i++) {
        for (int j=0; j<camino.size(); j++) {
            if(descartes[i]->getID()==camino[j]->getID())
                descartes.erase(descartes.begin()+i);
        }
    }
    
}
void NodeOpenBag::setDescartes(std::vector<GraphNode *> discards){
    descartes=discards;
}
