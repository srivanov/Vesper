//
//  gestor_eventos.cpp
//  vesper
//
//  Created by Gaspar Rodriguez Valero on 28/3/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "gestor_eventos.hpp"

#define MAPA -1

/*
 
 Eventos
 
 */

eventos::eventos(){m_t.start();}
eventos::~eventos(){}

/*
 
 GESTOR DE EVENTOS
 
 */

gestor_eventos::gestor_eventos(){id_counts=0;}
gestor_eventos::~gestor_eventos(){
    end = World_events.size();
    for (it=0;it<end;it++)
        delete World_events[it];
    
}

gestor_eventos * gestor_eventos::instance(){
    static gestor_eventos gestor;
    return &gestor;
}

void gestor_eventos::addEvento(int id,const Prioridades t,dvector3D pos){
    id_counts++;
    eventos * evento = new eventos;
    evento->m_ID = id_counts;
    evento->m_tipo = t;
    evento->m_posicion = pos;
    World_events.push_back(evento);
}

void gestor_eventos::subscribirse(NpcBook *libro){
    if(!libro) return;
    Suscritos.push_back(libro);
}

void gestor_eventos::update(){
    limpiar();
    comprobar();
}

void gestor_eventos::comprobar(){
    end = World_events.size();
    size_t end_s = Suscritos.size(), it_s=0;
    
    for (it=0; it<end; it++) {
        eventos * ev = World_events[it];
        for (; it_s<end_s; it_s++) {
            NpcBook * sub = Suscritos[it_s];
            
            // SI ES EL CREADOR
            if(ev->m_ID_CREADOR == sub->m_ID) continue;
            
            // SI ES EVENTO DE MAPA
            if(ev->radio==MAPA){
                sub->notify(ev->m_ID, ev->m_tipo, &ev->m_posicion);
                continue;
            }
            
            float distancia = EasyMath::EucCalcularDistancia(ev->m_posicion, sub->getPosition());
            
            // SI ESTA A LA DISTANCIA
            if(distancia<ev->radio)
                sub->notify(ev->m_ID, ev->m_tipo, &ev->m_posicion);
            
        }
    }
    
}

void gestor_eventos::limpiar(){
    end = World_events.size();
    for (int i=0; i<end; i++) {
        eventos * evento = World_events[i];
        if(evento->m_t.tTranscurrido(evento->m_caducidad)){
            delete evento;
            World_events.erase(World_events.begin()+i);
            i--<0  ? i=0 : i-- ;
        }
    }
}
