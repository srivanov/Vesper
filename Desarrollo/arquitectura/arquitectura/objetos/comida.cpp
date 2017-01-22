//
//  comida.cpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 11/1/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "comida.hpp"
#include "BlackBoards.hpp"

#define TIEMPO_COMESTIBLE 10

comida::comida(int & ID){
    this->ID = ID;
    this->consumido = false;
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
comida::~comida(){

}
void comida::gestorTiempo(){
    if(time(NULL)>_time){
        consumido = false;
    }
}
void comida::update(){
    gestorTiempo();
    TypeRecords comida = R_COMIDA;
    if (World_BlackBoard::instance()->hasAnswer(comida, &ID) && !consumido) {
        World_BlackBoard::instance()->removeRecord(comida, &ID);
        consumido = true;
        _time = time(NULL) + TIEMPO_COMESTIBLE;
    }else if(World_BlackBoard::instance()->countType(comida)>0 && !consumido){
        World_BlackBoard::instance()->AnswerRecord(comida, &ID, getPosicion());
    }
}
