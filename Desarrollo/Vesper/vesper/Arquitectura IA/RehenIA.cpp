//
//  RehenIA.cpp
//  vesper
//
//  Created by Gaspar Rodriguez Valero on 14/4/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "RehenIA.hpp"
#include "mundoBox2D.hpp"

#define VELOCIDAD 1.5f

RehenIA::RehenIA(dvector3D * pos) : player(nullptr) , m_salida(nullptr) {
    actual = HIBERNANDO;
    posActual = pos;
    change = Fsalida = Player = false;
    t.start();
    t2.start();
}

void RehenIA::changeState(R_states sta){
    actual = sta;
    change = true;
}

RehenIA::~RehenIA(){}

void RehenIA::inicializar(dvector3D * pos, dvector3D pos2){
    player = pos;
    change = true;
    posInicial = pos2;
}

bool RehenIA::inicializado(){
    if(player) return true;
    return false;
}

void RehenIA::update(){
    resetMov();
    
    if(change){
        Fsalida = false;
        Player = false;
        calcularCamino();
    }
    switch (actual) {
        case HIBERNANDO:break;
        default:calcularSiguiente();break;
    }
    
}

void RehenIA::calcularCamino(){
    
    if(actual==ASUSTADO){
        camino.clear();
        camino = PathPlanning::instance()->obtenerCamino(posActual, &posInicial);
    }
    change = false;
}


void RehenIA::resetMov(){
    movimiento.x=0;
    movimiento.y=0;
    movimiento.z=0;
}

void RehenIA::evaluar(){
    switch (actual) {
        case HIBERNANDO:                     break; // CONTINUA HIBERNANDO
        case SIGUIENDO:                      break; // CONTINUA SIGUIENDO
        case ASUSTADO:  actual = HIBERNANDO; break; // HIBERNA
        default:break;
    }
}

void RehenIA::calcularSiguiente(){
    
vuelta:
    
    dvector3D calculo;
    
    if(actual==ASUSTADO){
        if(camino.empty()){evaluar();return;}
        calculo = camino[0];
    }
    else if(Fsalida)
        calculo = *m_salida;
    else if(Player)
        calculo = *player;
    else if(t2.tTranscurrido(1.0f)){
        t2.reset();
        if(!mundoBox2D::Instance()->raycastContact(*posActual, *player))
            Player = true;
        return;
    }
    
    float aux = EasyMath::EucCalcularDistancia(*posActual,calculo);
    
    if(EasyMath::EucCalcularDistancia(*m_salida, *posActual) < 4.0f && !Fsalida && t.tTranscurrido(1)){
        Fsalida = true;
        t.reset();
    }
    
    if(actual==ASUSTADO && aux<1.0f){
            camino.erase(camino.begin());
            goto vuelta;
    }
    else if(actual==SIGUIENDO){
        if(aux > 8.0f){actual = HIBERNANDO;return;}
        if(aux < 2.0f && !Fsalida) return;
    }
    
    float xABS = calculo.x-(posActual->x);
    float yABS = calculo.y-(posActual->y);
    movimiento.x = xABS*((VELOCIDAD*100/aux)/100);
    movimiento.y = yABS*((VELOCIDAD*100/aux)/100);
    movimiento.z = 0;
    
}
