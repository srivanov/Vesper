//
//  Fuente.cpp
//  Arquitectura
//
//  Created by Gaspar Rodriguez Valero on 16/3/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#include "Fuente.hpp"

void Fuente::update(){
    GameObject::update();
    
    /*
    while(LevelBlackBoard::instance()->exist_record(ID, P_SED)){
        if(LevelBlackBoard::instance()->getRecord(ID, P_SED)->romper){
            rota = true;
        }else if(rota) NPCKnows = true;
        LevelBlackBoard::instance()->RemoveRecord(ID, P_SED);
    }
    if (!NPCKnows)
        LevelBlackBoard::instance()->AnswerRecord(P_SED, ID, getPosicion());
     */
}

Fuente::~Fuente(){
    
}
Fuente::Fuente(){
    
}
