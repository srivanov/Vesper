/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   trigger_system.cpp
 * Author: Gaspar
 * 
 * Created on 24 de diciembre de 2016, 19:42
 */

#include "trigger_system.hpp"

triggers::triggers(const Prioridades& type, unsigned int idTrigger, int idSource, dvector3D pos, float radio, float duration){
    _type = type;
    _idTrigger = idTrigger;
    _idSource = idSource;
    _pos = pos;
    _radio = radio;
    _duration = duration;
    t.start();
}
triggers::~triggers(){}
trigger_system::trigger_system() {IDcont=0;}

void trigger_system::add_trigger(const Prioridades& type, int id, dvector3D pos, float radio, int duration){
    triggers * _trigger = new triggers(type,IDcont,id,pos,radio,duration);
    TRIGGER_VECTOR.push_back(_trigger);
    IDcont++;
}
void trigger_system::update(){
    
    for(int i=0;i<TRIGGER_VECTOR.size();i++){
        for (int j=0; j<AGENTS.size(); j++) {
            triggers * trg = TRIGGER_VECTOR[i];
            NpcBook * agente = AGENTS[j];
            if (trg->_radio==-1) {
                agente->notify(trg->_idTrigger, trg->_type, &trg->_pos);
                continue;
            }
            if(EasyMath::EucCalcularDistancia(*AGENTS[j]->getPosition(), trg->_pos)>trg->_radio)
                    continue;
            else
                agente->notify(trg->_idTrigger,trg->_type, &trg->_pos);
        }
    }
    update_trigger();
}
void trigger_system::update_trigger(){
    for (int i=0; i<TRIGGER_VECTOR.size(); i++) {
        triggers * trg = TRIGGER_VECTOR[i];
        if( trg->t.tTranscurrido(trg->_duration) ){
            delete TRIGGER_VECTOR[i];
            TRIGGER_VECTOR.erase(TRIGGER_VECTOR.begin()+i);
            i=-1;
        }
    }
    
}

trigger_system::~trigger_system() {}

trigger_system * trigger_system::instance(){
    static trigger_system t;
    return &t;
}

void trigger_system::subs(NpcBook* npc){AGENTS.push_back(npc);}

bool trigger_system::ExistTrigger(const Prioridades& type, int& ID){
    for (int i=0; i<TRIGGER_VECTOR.size(); i++) {
        if(TRIGGER_VECTOR[i]->_type==type && TRIGGER_VECTOR[i]->_idSource==ID)
            return false;
    }
    return true;
}
