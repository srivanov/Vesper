//
//  Alarm.cpp
//  Arquitectura
//
//  Created by Gaspar Rodriguez Valero on 16/3/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#define TIEMPOALARMA 5.0f
#define RADIOALARMA -1

#include "Alarm.hpp"

void Alarm::gestorTiempo(){
    if(activado){
        if(_time.tTranscurrido(TIEMPOALARMA)){
            activado = false;
            printf("| se ha desactivado |");
            setTexture("3d/alarmita.jpg");
        }
    }
}

Alarm::Alarm(){
    rota = NPCKnows = activado = false;
}
Alarm::~Alarm(){}
void Alarm::update(){
    
    gestorTiempo();
    
    
    if(LevelBlackBoard::instance()->exist_record(m_ID, P_ALARMA)){
        if (LevelBlackBoard::instance()->getRecord(m_ID, P_ALARMA)->romper) rota=true;
        else if(rota)NPCKnows=true;
        else if(estaActivado())
            activar();
        
    }
    if(!NPCKnows){
        LevelBlackBoard::instance()->AnswerRecord(P_ALARMA, m_ID, getPosition());
    }
    
    GameObject::update();
}

void Alarm::activar(){
    activado = true;
    
    _time.start();
    setTexture("3d/rojo.png");
    if(trigger_system::instance()->ExistTrigger(P_ALARMA, m_ID))
        trigger_system::instance()->add_trigger(P_ALARMA, m_ID,getPosition(), RADIOALARMA, TIEMPOALARMA);
    
}

bool Alarm::estaActivado(){
    return activado;
}
