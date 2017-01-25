//
//  llaveObj.cpp
//  arquitectura
//
//  Created by Nerea Castellanos Rodríguez on 23/1/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "llaveObj.hpp"

llaveObj::llaveObj(){
	
	//TO DO: Eliminar clase llave
	
    component* aux = new class render();
    this->insertComponent((char*)"render", aux);
    aux = new transform3D();
    this->insertComponent((char*)"transform3D", aux);
    aux = new physics();
    this->insertComponent((char*)"physics", aux);
    
    std::map<char*,component*>::iterator iter = this->getIteradorBegin();
    while(iter != this->getIteradorEnd()){
        iter->second->setFather(this);
        iter++;
    }
    setRenderizable(true);
    
    physics* fisica = (physics*)findComponent("physics");
    
    dvector3D dim(1,1,1);
    dvector3D pos(0,0,0);
    
    fisica->crearBodyEstatico(dim, pos, 90.f);
    
    muero = false;
    aux = NULL;
	setType(tLLAVE);
}

llaveObj::~llaveObj(){
    
}

void llaveObj::update(){
    GameObject::update();
}

void llaveObj::contacto(GameObject *g){
    if(*g->getType() == tPLAYER){
        muero = true;
    }
}

bool const* llaveObj::getmuero(){
    return &muero;
}

