//
//  Graph.cpp
//  PathPlanning
//
//  Created by Gaspar Rodriguez Valero on 1/2/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#include "Graph.hpp"
#include "../mundoBox2D.hpp"

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

GraphNode * Graph::getNearNode(dvector3D * pos){
    
    float distanciaLimite = -1.f;
    size_t AllNodo = Grafo.size(), ContNodo = 0;
    
reset:
    
    float MenorDistancia = -1.f, NuevaDistancia;
    it = Grafo.begin();
    int IDfinal;
    while (it!=Grafo.end()) {
        
        NuevaDistancia = EasyMath::EucCalcularDistancia(*pos,*it->second->getPosition() );
        
        
        if( (MenorDistancia!=-1.f && MenorDistancia < NuevaDistancia)
           || (distanciaLimite!=-1.f && NuevaDistancia <= distanciaLimite)) {
            it++; continue;
        }
        
        MenorDistancia = NuevaDistancia;
        IDfinal = it->first;
        it++;
    }
    
    it = Grafo.find(IDfinal);
    
    if(ContNodo < AllNodo){
        
        if(mundoBox2D::Instance()->raycastContact(*pos, *it->second->getPosition())){
            ContNodo++;
            distanciaLimite = MenorDistancia;
            goto reset;
        }
    }else if(ContNodo == AllNodo && distanciaLimite != -1.f){
        distanciaLimite = -1.f;
        goto reset;
    }
    
    return it->second;
}
