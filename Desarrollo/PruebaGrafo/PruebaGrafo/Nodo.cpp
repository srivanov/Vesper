//
//  Nodo.cpp
//  PruebaGrafo
//
//  Created by Julia Martínez Valera on 27/1/17.
//  Copyright © 2017 Julia Martínez Valera. All rights reserved.
//

#include "Nodo.hpp"

Nodo::Nodo(vector2d _pos, int ID){
    this->ID = ID;
    this->posicion = _pos;
    pase = false;
}
Nodo::~Nodo(){
    conecta_con.clear();
    for (int i=0; i<aristas.size(); i++)
        delete aristas[i];
    aristas.clear();
}

void Nodo::conectar(Nodo * a){
    //it = conecta_con.find(a->getID());
    //if(it!=conecta_con.end()) return;
    for (int i=0; i<conecta_con.size(); i++) {
        if (conecta_con[i]->getID() == a->getID()) return;
    }
    //conecta_con.insert(std::pair<int, Nodo*>(a->getID(),a));
    conecta_con.push_back(a);
    anyadirArista(this->posicion, a->posicion);
    a->conectar(this);
};

void Nodo::anyadirArista(vector2d posA, vector2d posB){
    aristas.push_back(new arista(posA,posB));
}
