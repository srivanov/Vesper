//
//  Comida.cpp
//  Arquitectura
//
//  Created by Gaspar Rodriguez Valero on 16/3/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#include "Comida.hpp"

#define TIEMPO 5.f

Comida::Comida(){
    addNodo("3d/comida_entera.obj");
//    setTexture("3d/comida_gastada_Diffuse.png");
    consumido = false;
}
Comida::~Comida(){}

void Comida::gestorTiempo(){
    
    if(time.tTranscurrido(TIEMPO)){
        consumido = false;
    }
}

void Comida::update() {
    gestorTiempo();
    
    if (LevelBlackBoard::instance()->exist_record(m_ID, P_HAMBRE) && !consumido) {
        LevelBlackBoard::instance()->RemoveRecord(m_ID, P_HAMBRE);
        consumido = true;
        time.start();
        return;
    }
    if(!consumido)
        LevelBlackBoard::instance()->AnswerRecord(P_HAMBRE, m_ID, getPosition());
    
}
