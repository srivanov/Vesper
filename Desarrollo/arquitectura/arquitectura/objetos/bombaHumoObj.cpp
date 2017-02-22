//
//  bombaHumoObj.cpp
//  arquitectura
//
//  Created by Nerea Castellanos Rodríguez on 22/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "bombaHumoObj.hpp"

bombaHumoObj::bombaHumoObj(){
    
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
    setType(tBOMBAHUMO);
}

bombaHumoObj::~bombaHumoObj(){
    
}

void bombaHumoObj::update(){
    GameObject::update();
}

void bombaHumoObj::contacto(GameObject *g){
    if(*g->getType() == tPLAYER){
        muero = true;
    }
}

bool const* bombaHumoObj::getmuero(){
    return &muero;
}

void bombaHumoObj::contactoEnd(GameObject *g){
    
}
