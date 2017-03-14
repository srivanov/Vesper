//
//  fuente.cpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 11/1/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "fuente.hpp"

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
    
    while(LevelBlackBoard::instance()->exist_record(ID, P_SED)){
        if(LevelBlackBoard::instance()->getRecord(ID, P_SED)->romper){
            rota = true;
        }else if(rota) NPCKnows = true;
        LevelBlackBoard::instance()->RemoveRecord(ID, P_SED);
    }
    if (!NPCKnows)
        LevelBlackBoard::instance()->AnswerRecord(P_SED, ID, getPosicion());
}

void fuente::contacto(GameObject *g){
    if(g != NULL){
		
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
