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

triggers::triggers(TypeEvents& type, unsigned int& idTrigger, int* idSource, dvector3D* pos, float radio, float duration){
    _type = type;
    _idTrigger = idTrigger;
    _idSource = idSource;
    _pos = *pos;
    _radio = radio;
    _duration = time(NULL)+duration;
}
triggers::~triggers(){_idSource = NULL; delete _idSource;}
trigger_system * trigger_system::_TSinstance = 0;
trigger_system::trigger_system() {IDcont=0;}

unsigned long trigger_system::add_trigger(TypeEvents type, int* id, dvector3D* pos, float radio, float duration){
    triggers * _trigger = new triggers(type,IDcont,id,pos,radio,duration);
    TRIGGER_VECTOR.push_back(_trigger);
    return _trigger->_idTrigger;
}
void trigger_system::update(){
    for(int i=0;i<TRIGGER_VECTOR.size();i++){
        if(TRIGGER_VECTOR[i]->_duration<time(NULL)){
            delete TRIGGER_VECTOR[i];
            TRIGGER_VECTOR.erase(TRIGGER_VECTOR.begin()+i);
        }else{
            for (int j=0; j<AGENTS.size(); j++) {
                if(!AGENTS[j]->EventUsed(TRIGGER_VECTOR[i]->_type))
                    continue;
                else if(AGENTS[j]->getID()==TRIGGER_VECTOR[i]->_idSource)
                    continue;
                else if(CalcularDistancia(*AGENTS[j]->getPosicion(), TRIGGER_VECTOR[i]->_pos)>TRIGGER_VECTOR[i]->_radio)
                    continue;
                else
                    AGENTS[j]->notify(TRIGGER_VECTOR[i]->_pos, TRIGGER_VECTOR[i]->_type);
            }
            
        }
    }
}
void trigger_system::remove_trigger(unsigned long id){
    unsigned long it = 0;
    while( it != TRIGGER_VECTOR.size() ){
        
        if(TRIGGER_VECTOR[it]->_idTrigger == id){
            delete TRIGGER_VECTOR[it];
            return;
        }
        else  ++it;
    }
}

trigger_system::~trigger_system() {}

trigger_system * trigger_system::_instance(){
    if(_TSinstance == 0)
        _TSinstance = new trigger_system;
    return _TSinstance;
}

float trigger_system::CalcularDistancia(dvector3D a, dvector3D b){
    float x = fabs(a.x-b.x);
    float y = fabs(a.y-b.y);
    return x+y;
}
void trigger_system::subs(enemigos* npc){
    AGENTS.push_back(npc);
}
bool trigger_system::ExistTrigger(TypeEvents& type, int& ID){
    for (int i=0; i<TRIGGER_VECTOR.size(); i++) {
        if(TRIGGER_VECTOR[i]->_type==type && *TRIGGER_VECTOR[i]->_idSource==ID)
            return false;
    }
    return true;
}
