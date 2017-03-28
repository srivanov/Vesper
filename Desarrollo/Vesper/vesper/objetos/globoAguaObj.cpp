//
//  globoAguaObj.cpp
//  arquitectura
//
//  Created by Nerea Castellanos Rodríguez on 22/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "globoAguaObj.hpp"

globoAguaObj::globoAguaObj(){
    
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
    setType(tGLOBOAGUA);
}

globoAguaObj::~globoAguaObj(){
    
}

void globoAguaObj::update(){
    GameObject::update();
}

void globoAguaObj::contacto(GameObject *g){
	if(g != NULL){
		if(*g->getType() == tPLAYER){
			muero = true;
		}
	}
}

bool const* globoAguaObj::getmuero(){
    return &muero;
}

void globoAguaObj::contactoEnd(GameObject *g){
    
}
