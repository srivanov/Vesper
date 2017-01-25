//
//  botiquin.cpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 11/1/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "botiquin.hpp"
#include "BlackBoards.hpp"

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
    
    fisica->crearBodyDinamico(dim, pos);
    
    muero = false;
    usos = NUMERO_USOS;
    aux = NULL;
	setType(tBOTIQUIN);
}
botiquin::~botiquin(){

}
void botiquin::update(){
    TypeRecords botiquin = R_BOTIQUIN;
    while (World_BlackBoard::instance()->hasAnswer(botiquin, &ID)) {
        World_BlackBoard::instance()->removeRecord(botiquin, &ID);
        if (usos>0) usos--;
        else gastado = true;
    }
    if(World_BlackBoard::instance()->countType(botiquin)>0 && !gastado){
        World_BlackBoard::instance()->AnswerRecord(botiquin, &ID, getPosicion());
    }
}


void botiquin::contacto(GameObject *g){
    if(*g->getType() == tPLAYER){
        muero = true;
    }
}

bool const* botiquin::getmuero(){
    return &muero;
}
