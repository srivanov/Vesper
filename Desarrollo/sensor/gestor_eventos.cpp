//
//  gestor_eventos.cpp
//  vesper
//
//  Created by Gaspar Rodriguez Valero on 17/12/16.
//  Copyright © 2016 Skyscrapers. All rights reserved.
//

#include "gestor_eventos.hpp"
#include "NPC.hpp"

#define SONIDO 10
#define AVISO 80
#define ENEMIGO 40

eventos::eventos(int id,Event_type tipo, vector3D posicion, int * objeto_id) : pos_objeto(posicion) , id_objeto(objeto_id){
    id_evento = id;
    tE = tipo;
    timeExpires = timeStamp = time(NULL);
    switch (tE) {
        case tE_None:
            break;
        case tE_Sound:
            radio=SONIDO;
            timeExpires++;
            break;
        case tE_Aviso:
            radio=AVISO;
            timeExpires+=10;
            break;
        case tE_Enemy:
            radio=ENEMIGO;
            timeExpires+=10;
            break;
        default:break;
    }
}
eventos::~eventos(){tE = tE_None;}


gestor* gestor::pInstancia = 0;
gestor::gestor(){
    contador = 0;
}
gestor::~gestor(){}
gestor * gestor::Instance(){
    if(pInstancia==0)
        pInstancia = new gestor;
    return pInstancia;
};
void gestor::addEvent(Event_type tipo, vector3D posicion, int * objeto_id){
    eventos * new_evento = new eventos(contador,tipo,posicion,objeto_id);
    contador++;
    events.push_back(new_evento);
}
bool gestor::ExistEvent(Event_type tipo, int id){
    for (size_t i=0; i<events.size(); i++) {
        if(*events[i]->id_objeto==id && events[i]->tE==tipo) return true;
    }
    return false;
}
void gestor::update(std::vector<NPC*>& agentes){
    
    time_t AcTime = time(NULL);
    NPC * pAgent = NULL;
    
    for (size_t i=0; i<events.size(); i++) {
        if (events[i]->timeExpires==events[i]->timeStamp) {
            events[i]->~eventos();
            events[i] = NULL;
            events.erase(events.begin()+i);
        }else{
            events[i]->timeStamp = AcTime;
        }
    }
    for (size_t i=0; i<agentes.size(); i++) {
        pAgent = agentes[i];
        
        for (size_t t=0; t<events.size(); t++) {
            if( !events[t]->tE && pAgent->getFlags(events[t]->tE)){}
            else if(*events[t]->id_objeto == pAgent->getId()){}
            else{
                vector3D posAgent = *pAgent->getPosition();
                vector3D posEvent = events[t]->pos_objeto;
                float dist = vector3D::CalcularDistancia(posEvent, posAgent);
                if(dist<=events[t]->radio){
                    pAgent->setEventFlag(events[t]->pos_objeto,events[t]->tE);
                }
            }
        }
    }
}
