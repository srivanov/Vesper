//
//  ObjectsMemory.cpp
//  vesper
//
//  Created by Gaspar Rodriguez Valero on 9/5/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "ObjectsMemory.hpp"

Evalue MemoryObjects::evalue(PhysicObject *other){
    
    if(     other->getObjectType() != ALARMA
       &&   other->getObjectType() != PUERTA
       &&   other->getObjectType() != FUENTE
       )
        return NO_VALUABLE;
    
    if(!FindObject(other)){
        addObject(other);
        return NEW;
    }
    bool value = ExtractState(other);
    if(value!=Objectos[it]->state){
        Objectos[it]->state = value;
        Objectos[it]->t.reset();
        return CHANGED;
    }
    else return NORMAL;
}

bool MemoryObjects::FindObject(PhysicObject *other){
    end = Objectos.size();
    for (it = 0; it<end; it++) {
        if(*other->getPosition()==Objectos[it]->m_pos){
            return true;
        }
    }
    return false;
}

void MemoryObjects::addObject(PhysicObject *m_new){
    if(!m_new) return;
    
    Objecto * nuevo = new Objecto;
    nuevo->m_pos = *m_new->getPosition();
    nuevo->m_tipo = m_new->getObjectType();
    nuevo->state = ExtractState(m_new);
    Objectos.push_back(nuevo);
}
void MemoryObjects::update(){
    it = 0;
    end = Objectos.size();
    for(;it<end;it++){
        if(Objectos[it]->t.tTranscurrido(CADUCIDAD)){
            delete Objectos[it];
            Objectos.erase(Objectos.begin()+it);
            if(it!=0) it--;
            end = Objectos.size();
        }
    }
}

bool MemoryObjects::ExtractState(PhysicObject *m_new){
    bool value = false;
    if(m_new->getObjectType() == ALARMA){
        value = static_cast<Alarm*>(m_new)->EstaRota();
    }
    else if(m_new->getObjectType() == FUENTE){
        value = static_cast<Fuente*>(m_new)->EstaRota();
    }
    else if(m_new->getObjectType() == PUERTA){
        value = static_cast<Puerta*>(m_new)->EstaAbierta();
    }
    return value;
}
