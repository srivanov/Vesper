//
//  palaObj.cpp
//  arquitectura
//
//  Created by Stoycho Ivanov Atanasov on 22/1/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "palaObj.hpp"

palaObj::palaObj(){
	
	//TO DO: Eliminar clase pala
	
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
	setType(tPALA);
}

palaObj::~palaObj(){
	
}

void palaObj::update(){
	GameObject::update();
}

void palaObj::contacto(GameObject *g){
	if(g != NULL){
		if(*g->getType() == tPLAYER){
			muero = true;
		}
	}
}

bool const* palaObj::getmuero(){
    return &muero;
}

void palaObj::contactoEnd(GameObject *g){
    
}
