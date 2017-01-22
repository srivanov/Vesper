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
    
    //TO DO: anyadir componente de fisicas
    
    std::map<char*,component*>::iterator iter = this->getIteradorBegin();
    while(iter != this->getIteradorEnd()){
        iter->second->setFather(this);
        iter++;
    }
    setRenderizable(true);
 
    aux = NULL;
}
fuente::~fuente(){

}
void fuente::update(){
    TypeRecords fuente = R_FUENTE;
    while(World_BlackBoard::instance()->hasAnswer(fuente, &ID)){
        if(World_BlackBoard::instance()->getAnswer(fuente, &ID)->_idResponse<0){
            rota = true;
        }else if(rota) NPCKnows = true;
        World_BlackBoard::instance()->removeRecord(fuente, &ID);
    }
    if(World_BlackBoard::instance()->countType(fuente)>0 && !NPCKnows){
        World_BlackBoard::instance()->AnswerRecord(fuente, &ID, getPosicion());
    }
}
