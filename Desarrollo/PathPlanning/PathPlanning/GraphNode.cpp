//
//  GraphNode.cpp
//  PathPlanning
//
//  Created by Gaspar Rodriguez Valero on 1/2/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#include "GraphNode.hpp"

GraphNode::~GraphNode(){
    for (int i=0; i<conecta_con.size(); i++) {
        delete conecta_con[i];
    }
    conecta_con.clear();
}
GraphNode::GraphNode(int ID, dvector2D& posicion){
    this->ID = ID;
    this->posicion = posicion;
}

conexos::conexos(int ID, float peso, dvector2D posicion){
    this->ID = ID; this->peso = peso; this->posicion = posicion;
}
conexos::~conexos(){}
bool GraphNode::conectar(GraphNode * Nodo){
    if(Nodo->getID()==this->ID) return false;
    for (int i=0; i<conecta_con.size(); i++)
        if(Nodo->getID()==conecta_con[i]->ID) return false;
    
    float peso = EasyMath::EucCalcularDistancia(this->posicion , Nodo->posicion);
    
    conecta_con.push_back(new conexos(Nodo->getID(),peso,Nodo->getPosition()));
    Nodo->conectar(this);
    return true;
}
