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
    
    
    while(LevelBlackBoard::instance()->exist_record(m_ID, P_SED)){
        if(rota) {
            NPCKnows = true;
        }
        LevelBlackBoard::instance()->RemoveRecord(m_ID, P_SED);
    }
    if (!NPCKnows)
        LevelBlackBoard::instance()->AnswerRecord(P_SED, m_ID, getPosition());
    /*
    if(rota){
            }*/
}

Fuente::~Fuente(){
    LevelBlackBoard::instance()->RemoveRecord(m_ID, P_SED);
}
Fuente::Fuente(){
    rota = NPCKnows = false;
    addNodo("3d/fuenteprueba.obj");
    //setTexture("3d/Fuente_Diffuse.png");
}
