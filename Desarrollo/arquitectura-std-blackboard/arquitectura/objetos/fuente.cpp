//
//  fuente.cpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 11/1/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "fuente.hpp"
#include "BlackBoards.hpp"

fuente::fuente(int & ID){
    this->ID = ID;
    this->rota = false;
    this->NPCKnows = false;
    
    component* aux = new class render();
    this->insertComponent((char*)"render", aux);
    aux = new transform3D();
    this->insertComponent((char*)"transform3D", aux);
    
    
    std::map<char*,component*>::iterator iter = this->getIteradorBegin();
    while(iter != this->getIteradorEnd()){
        iter->second->setFather(this);
        iter++;
    }
    setRenderizable(true);
    
    
    posi = new dvector3D();
    aux = NULL;
    delete aux;
}
fuente::~fuente(){
    delete posi;
}
void fuente::update(){
    TypeRecords fuente = R_FUENTE;
    posi->x = getPosicion()[0]; posi->y = getPosicion()[1]; posi->z = getPosicion()[2];
    while(World_BlackBoard::instance()->hasAnswer(fuente, ID)){
        if(World_BlackBoard::instance()->getAnswer(fuente, ID)->_idResponse<0){
            rota = true;
        }else if(rota) NPCKnows = true;
        World_BlackBoard::instance()->removeRecord(fuente, ID);
    }
    if(World_BlackBoard::instance()->countType(fuente)>0 && !NPCKnows){
        World_BlackBoard::instance()->AnswerRecord(fuente, ID, posi);
    }
}
