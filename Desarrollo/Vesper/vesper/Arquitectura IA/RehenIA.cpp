//
//  RehenIA.cpp
//  vesper
//
//  Created by Gaspar Rodriguez Valero on 14/4/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "RehenIA.hpp"
#define VELOCIDAD 1.5f

RehenIA::RehenIA(dvector3D * pos) : player(nullptr){
    actual = HIBERNANDO;
    posActual = pos;
    change = false;
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
    
    if(change) calcularCamino();
    switch (actual) {
        case HIBERNANDO:break;
        default:calcularSiguiente();break;
    }
    
}

void RehenIA::calcularCamino(){
    if(actual==ASUSTADO){
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
        case HIBERNANDO:    break; // COTINUA HIBERNANDO
        case SIGUIENDO:     break; // CONTINUA SIGUIENDO
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
    }else
        calculo = *player;
    
    float aux = EasyMath::EucCalcularDistancia(*posActual,calculo);
    
    if(actual==ASUSTADO && aux<1.0f){
            camino.erase(camino.begin());
            goto vuelta;
    }
    else if(actual==SIGUIENDO && aux < 2.0f) return;
    
    float xABS = calculo.x-(posActual->x);
    float yABS = calculo.y-(posActual->y);
    movimiento.x = xABS*((VELOCIDAD*100/aux)/100);
    movimiento.y = yABS*((VELOCIDAD*100/aux)/100);
    movimiento.z = 0;
}
