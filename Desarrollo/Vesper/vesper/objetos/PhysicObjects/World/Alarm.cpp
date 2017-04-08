//
//  Alarm.cpp
//  Arquitectura
//
//  Created by Gaspar Rodriguez Valero on 16/3/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#define TIEMPOALARMA 5.0f
#define RADIOALARMA -1

#include "../Actores/Enemy.hpp"
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
    addNodo("3d/muro.3ds");
    setTexture("3d/alarmita.jpg");
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
    gestor_eventos * gestor = gestor_eventos::instance();
    setTexture("3d/rojo.png");
    if(!gestor->existeEvento(P_ALARMA, m_ID)){
        gestor->addEvento(m_ID, P_ALARMA, *getPosition());
        gestor->addEvento(m_ID, P_ALERTA, *getPosition());
    }
    
}

bool Alarm::estaActivado(){
    return activado;
}

void Alarm::contacto(PhysicObject *g){
    if(g->getObjectType() == ENEMIGOS){
        if(static_cast<Enemy*>(g)->activarAlarma())
            activar();
    }
}
