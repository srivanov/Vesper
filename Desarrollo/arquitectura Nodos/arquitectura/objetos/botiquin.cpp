//
//  botiquin.cpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 11/1/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "botiquin.hpp"

#define NUMERO_USOS 3

botiquin::botiquin(int &ID){
    this->ID = ID;
    this->gastado = false;
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
    usos = NUMERO_USOS;
    aux = NULL;
	setType(tBOTIQUIN);
}
botiquin::~botiquin(){

}
void botiquin::update(){
    
    
    while (LevelBlackBoard::instance()->exist_record(ID, P_VIDA)) {
        LevelBlackBoard::instance()->RemoveRecord(ID, P_VIDA);
        if (usos>0) usos--;
        else gastado = true;
    }
    LevelBlackBoard::instance()->AnswerRecord(P_VIDA, ID, getPosicion());
}


void botiquin::contacto(GameObject *g){
    if(*g->getType() == tPLAYER){
//        muero = true;
    }
}

bool const* botiquin::getmuero(){
    return &muero;
}

void botiquin::contactoEnd(GameObject *g){
    
}
