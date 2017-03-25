//
//  Comida.cpp
//  Arquitectura
//
//  Created by Gaspar Rodriguez Valero on 16/3/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#include "Comida.hpp"

Comida::Comida(){
    
}
Comida::~Comida(){}

void Comida::gestorTiempo(){
    /*
    if(time(NULL)>_time){
        consumido = false;
    }
     */
}

void Comida::update() {
    gestorTiempo();
    /*
    if (LevelBlackBoard::instance()->exist_record(ID, P_HAMBRE) && !consumido) {
        LevelBlackBoard::instance()->RemoveRecord(ID, P_HAMBRE);
        consumido = true;
        _time = time(NULL) + TIEMPO_COMESTIBLE;
        return;
    }
    if(!consumido)
        LevelBlackBoard::instance()->AnswerRecord(P_HAMBRE, ID, getPosicion());
     */
}
