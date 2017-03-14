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

triggers::triggers(const Prioridades& type, unsigned int idTrigger, int idSource, dvector3D* pos, float radio, float duration){
    _type = type;
    _idTrigger = idTrigger;
    _idSource = idSource;
    _pos = pos;
    _radio = radio;
    _duration = time(NULL)+duration;
}
triggers::~triggers(){}
trigger_system * trigger_system::_TSinstance = 0;
trigger_system::trigger_system() {IDcont=0;}

void trigger_system::add_trigger(const Prioridades& type, int id, dvector3D * pos, float radio, int duration){
    triggers * _trigger = new triggers(type,IDcont,id,pos,radio,duration);
    TRIGGER_VECTOR.push_back(_trigger);
    IDcont++;
}
void trigger_system::update(){
    
    for(int i=0;i<TRIGGER_VECTOR.size();i++){
        for (int j=0; j<AGENTS.size(); j++) {
            if (TRIGGER_VECTOR[i]->_radio==-1) {
                AGENTS[j]->notify(TRIGGER_VECTOR[i]->_idTrigger, TRIGGER_VECTOR[i]->_type, TRIGGER_VECTOR[i]->_pos);
                continue;
            }
            if(EasyMath::EucCalcularDistancia(*AGENTS[j]->getPosition(), *TRIGGER_VECTOR[i]->_pos)>TRIGGER_VECTOR[i]->_radio)
                    continue;
            else
                AGENTS[j]->notify(TRIGGER_VECTOR[i]->_idTrigger,TRIGGER_VECTOR[i]->_type, TRIGGER_VECTOR[i]->_pos);
        }
    }
    update_trigger();
}
void trigger_system::update_trigger(){
    for (int i=0; i<TRIGGER_VECTOR.size(); i++) {
        if(TRIGGER_VECTOR[i]->_duration<time(NULL)){
            delete TRIGGER_VECTOR[i];
            TRIGGER_VECTOR.erase(TRIGGER_VECTOR.begin()+i);
        }
    }
    
}

trigger_system::~trigger_system() {}

trigger_system * trigger_system::_instance(){
    if(_TSinstance == 0)
        _TSinstance = new trigger_system;
    return _TSinstance;
}

void trigger_system::subs(NpcBook* npc){AGENTS.push_back(npc);}

bool trigger_system::ExistTrigger(const Prioridades& type, int& ID){
    for (int i=0; i<TRIGGER_VECTOR.size(); i++) {
        if(TRIGGER_VECTOR[i]->_type==type && TRIGGER_VECTOR[i]->_idSource==ID)
            return false;
    }
    return true;
}
