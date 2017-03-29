//
//  Botiquin.cpp
//  Arquitectura
//
//  Created by Gaspar Rodriguez Valero on 16/3/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#include "Botiquin.hpp"

#define NUMERO_USOS 3

Botiquin::Botiquin(){addNodo("3d/muro.3ds");setTexture("3d/botiquin.jpg");}
Botiquin::~Botiquin(){}

void Botiquin::update(){
    
    while (LevelBlackBoard::instance()->exist_record(m_ID, P_VIDA)) {
        LevelBlackBoard::instance()->RemoveRecord(m_ID, P_VIDA);
        if (usos>0) usos--;
        else gastado = true;
    }
    if(!gastado)
        LevelBlackBoard::instance()->AnswerRecord(P_VIDA,m_ID, getPosition());
    
}
