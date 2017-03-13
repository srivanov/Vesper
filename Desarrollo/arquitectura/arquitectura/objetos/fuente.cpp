//
//  fuente.cpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 11/1/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "fuente.hpp"
#include "BlackBoards.hpp"

fuente::fuente(){
    this->rota = false;
    this->NPCKnows = false;
    
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
    
    fisica->crearBodyEstatico(dim, pos, 90.0f);
 
    muero = false;
    aux = NULL;
	setType(tFUENTE);
}

fuente::~fuente(){

}

void fuente::update(){
	GameObject::update();
    TypeRecords fuente = R_FUENTE;
    while(World_BlackBoard::instance()->hasAnswer(fuente, ID)){
        if(World_BlackBoard::instance()->getAnswer(fuente, ID)->_idResponse<0){
            rota = true;
        }else if(rota) NPCKnows = true;
        World_BlackBoard::instance()->removeRecord(fuente, ID);
    }
    if(World_BlackBoard::instance()->countType(fuente)>0 && !NPCKnows){
        World_BlackBoard::instance()->AnswerRecord(fuente, ID, getPosicion());
    }
}

void fuente::contacto(GameObject *g){
	if(g != NULL){
		if(*g->getType() == tPLAYER){
//	        muero = true;
		}
	}
}

bool const* fuente::getmuero(){
    return &muero;
}

void fuente::contactoEnd(GameObject *g){
    
}

void fuente::muere(){
    muero = true;
}
