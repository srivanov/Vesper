//
//  rehen.cpp
//  arquitectura
//
//  Created by Nerea Castellanos Rodríguez on 22/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "rehen.hpp"

rehen::rehen(){
    
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
    
    muero = false;
    fisica->crearBodyDinamico(dim, pos);
    aux = NULL;
    setType(tREHEN);

}

rehen::~rehen(){
    
}

void rehen::update(){
    GameObject::update();
}

void rehen::render(){
    GameObject::render();
}

bool const* rehen::getmuero(){
    return &muero;
}

void rehen::contacto(GameObject *g){
	if(g != NULL){
		
	}
}

void rehen::contactoEnd(GameObject *g){
    obj_colisionado = NULL;
}
