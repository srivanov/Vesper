//
//  gestor_eventos.cpp
//  vesper
//
//  Created by Gaspar Rodriguez Valero on 28/3/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "gestor_eventos.hpp"
#include "../objetos/PhysicObjects/Actores/Rehen.hpp"

#define MAPA -1

/*
 
 Eventos
 
 */

eventos::eventos(){m_t.start();revisado=false;}
eventos::~eventos(){}

/*
 
 GESTOR DE EVENTOS
 
 */


eventos_values Evalores[] = {
//     TIPO      RADIO  CADUCIDAD(seg)
    { P_ALARMA  , 40.f   , 2.0f},
    { P_ALERTA  , -1.f   , 20.f},
    { P_AVISO   , 20.f   , 5.0f},
    { P_AYUDA   , 40.f   , 2.0f},
    { P_RUIDO   , 20.f   , 0.5f},
    { P_VOID    , 0.f    , 0.5f}
};


gestor_eventos::gestor_eventos() : rehen(nullptr){id_counts=0;}
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
    evento->m_ID_CREADOR = id;
    //DEBUG VALUES
    
    it = 0;
    while(Evalores[it].m_tipo!=P_VOID){
        if(Evalores[it].m_tipo==t){
            evento->radio = Evalores[it].radio;
            evento->m_caducidad = Evalores[it].caducidad;
            break;
        }
        it++;
    }
    World_events.push_back(evento);
}

void gestor_eventos::subscribirse(NpcBook *libro){
    if(!libro) return;
    Suscritos.push_back(libro);
}
void gestor_eventos::subscribirse(Rehen * r){
    rehen = r;
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
            if(ev->m_ID_CREADOR == sub->m_ID || sub->TengoEsteEvento(ev->m_tipo, ev->m_ID)) continue;
            
            // SI ES EVENTO DE MAPA
            if(ev->radio==MAPA){
                sub->notify(ev->m_ID, ev->m_tipo, &ev->m_posicion);
                continue;
            }
            
            float distancia;
            
            if(rehen && ev->m_tipo==P_RUIDO){
                distancia = EasyMath::EucCalcularDistancia(ev->m_posicion, *rehen->getPosition());
                if(distancia<ev->radio)
                    rehen->asustado();
                
            }
            
            distancia = EasyMath::EucCalcularDistancia(ev->m_posicion, *sub->getPosition());
            
            // SI ESTA A LA DISTANCIA
            if(distancia<ev->radio){
                ev->revisado = true;
                sub->notify(ev->m_ID, ev->m_tipo, &ev->m_posicion);
            }
            
        }
    }
    
}

void gestor_eventos::eliminarme(int ID){
    end = Suscritos.size();
    for (it=0; it<end; it++)
        if(Suscritos[it]->m_ID==ID){
            Suscritos.erase(Suscritos.begin()+it);
            return;
        }
    
}

bool gestor_eventos::revisadoEvento(const Prioridades tipo, const int ID){
    if(existeEvento(tipo, ID)){
        return World_events[it]->revisado;
    }
    return false;
}

bool gestor_eventos::existeEvento(const Prioridades tipo, const int ID){
    end = World_events.size();
    for (it = 0; it<end; it++)
        if(
            World_events[it]->m_tipo == tipo
        &&  World_events[it]->m_ID_CREADOR == ID
           )
            return true;
    
    return false;
}

void gestor_eventos::limpiar(){
    end = World_events.size();
    for (int i=0; i<end; i++) {
        eventos * evento = World_events[i];
        if(evento->m_t.tTranscurrido(evento->m_caducidad)){
            delete evento;
            World_events.erase(World_events.begin()+i);
            end = World_events.size();
            i--;
        }
    }
}
