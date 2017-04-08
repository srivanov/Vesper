//
//  Graph.cpp
//  PathPlanning
//
//  Created by Gaspar Rodriguez Valero on 1/2/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#include "Graph.hpp"

//CONSTRUCTORES Y DESTRUCTORES

Graph::Graph(){}
Graph::Graph(std::vector<GraphNode*>& NodeVector){
    for (int i=0; i<NodeVector.size(); i++) {
        Grafo.insert(std::pair<int, GraphNode*>(NodeVector[i]->getID(),NodeVector[i]));
    }
}
Graph::Graph(std::map<int,GraphNode*>& NodeMap){
    this->Grafo = NodeMap;
}

Graph::Graph(const Graph* grafo){
    this->Grafo = grafo->Grafo;
}

Graph::~Graph(){
    it = Grafo.begin();
    while (it!=Grafo.end()) {
        delete it->second;
        it++;
    }
}
// FUNCIONES

bool Graph::add_node(int id, GraphNode * Nodo){
    it = Grafo.find(id);
    if(it==Grafo.end()) return false;
    Grafo.insert(std::pair<int, GraphNode*>(id,Nodo));
    return true;
}

GraphNode * Graph::getNode(int ID){
    it = Grafo.find(ID);
    return it->second;
}

GraphNode * Graph::getInitialNode(dvector3D * initialPosition){
    it = Grafo.begin();
    float MenorDistancia = -1.f, NuevaDistancia;
    int IDfinal;
    while (it!=Grafo.end()) {
        NuevaDistancia = EasyMath::EucCalcularDistancia(*initialPosition,*it->second->getPosition() );
        if(MenorDistancia!=-1.f && MenorDistancia<NuevaDistancia) {
            it++; continue;
        }
        MenorDistancia = NuevaDistancia;
        IDfinal = it->first;
        it++;
    }
    it = Grafo.find(IDfinal);
    return it->second;
}
GraphNode * Graph::getFinalNode(dvector3D * finalPosition){
    it = Grafo.begin();
    float MenorDistancia = -1.f, NuevaDistancia;
    int IDfinal;
    while (it!=Grafo.end()) {
        NuevaDistancia = EasyMath::CalcularDistancia(finalPosition,it->second->getPosition() );
        if(MenorDistancia!=-1.f && MenorDistancia<NuevaDistancia){
            it++;
            continue;
        }
        MenorDistancia = NuevaDistancia;
        IDfinal = it->first;
        it++;
    }
    it = Grafo.find(IDfinal);
    return it->second;
}
