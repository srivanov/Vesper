//
//  DecisionSystem.cpp
//  Sistema de Decision
//
//  Created by Gaspar Rodriguez Valero on 8/11/16.
//  Copyright © 2016 Stoycho Ivanov Atanasov. All rights reserved.
//
#include "DecisionSystem.hpp"

#define STANDAR    0
#define SUSPECT    1
#define ALERT      2
#define INCOMBAT   3
#define FRIGHTENED 4

DecisionSystem::DecisionSystem(){
    Vestado = new Vstate();
    state = lastState = 0;
    sensor = 0;
    tiempo = NULL;
}
/* SENSOR */
enum{
    S_inactivo = 0,
    S_escuchado,
    S_alarma,
    S_enemigo,
    S_numSentido
};

void DecisionSystem::standar(){
    /*ESTANDAR*/
    if (sensor!=S_inactivo) {
        switch (sensor) {
            case S_escuchado:state=SUSPECT;break;
            case S_alarma:state=ALERT;break;
            case S_enemigo:state=INCOMBAT;break;
            default:state=lastState;break;
        }
    }
    else{
        if (Vestado->getLife()<=0) {cout << "HE MUERTO" << endl;}
        else if (Vestado->getLife()<50) {cout << "TENGO QUE CURARME" << endl;}// IR A BOTIQUÍN | PATHFINDING BOTIQUIN
        else if(Vestado->getThirst()>60){cout << "TENGO QUE BEBER" << endl;}// BEBER | PATHFINDING SED
        else if(Vestado->getHungry()>70){cout << "TENGO QUE COMER" << endl;}// COMER | PATHFINDING COMER
        else{cout << "SIGO CON MI PAUTA PRECONCEBIDA" << endl;} // PATRULLAR, HABLAR O VIGILAR | CUANDO CONTINUA SU MARCHA
    }
}
void DecisionSystem::suspect(){
    /*SOSPECHA*/
    if(tiempo==NULL) tiempo = new int;
    else{
        int aux = Vestado->calculate();
        if (*tiempo > 25) {delete tiempo;tiempo=NULL;state = STANDAR;} // CAMBIAR DE ESTADO A ESTÁNDAR
        else if (sensor == S_enemigo && aux<30){delete tiempo;tiempo=NULL;state=FRIGHTENED;}// CAMBIAR DE ESTADO A ASUSTADO
        
        else{
            if(aux>50 && aux<70){
                //if(NPC muy cerca) // COMUNICARSE CON COMPAÑERO
                //if(NPC a distanciad de radio) // AVISAR POR RADIO
                //else{} NADIE CERCA //BUSCAR RUIDO
            }
            else if(aux>70){}//BUSCAR RUIDO
        }
        tiempo++;
    }
}
void DecisionSystem::alert(){
    /*ALERTA*/
    if(tiempo==NULL) tiempo = new int;
    else{
        int aux = Vestado->calculate();
        if (*tiempo > 25 && sensor==S_inactivo) {delete tiempo;tiempo=NULL;state = STANDAR;} // CAMBIAR DE ESTADO A ESTÁNDAR
        else if(sensor==S_enemigo){delete tiempo;tiempo=NULL;state = INCOMBAT;}// CAMBIAR DE ESTADO A AGRESIVO
        else{
            if(aux>50 && aux<60){
                //if(NPC muy cerca) // COMUNICARSE CON COMPAÑERO
                //else if(NPC a distanciad de radio) // AVISAR POR RADIO
                //else if(ALARMA CERCANA) // BUSCAR ALARMA
                //else{} NADIE CERCA //RECORRER ZONA CERCANA
            }
            else if(aux>60){}//RECORRER ZONA CERCANA
        }
        tiempo++;
    }
    
}
void DecisionSystem::inCombat(){
    /*
     AGRESIVO
     
     
     
     
     CUBRIRSE
     
     */
    if(tiempo==NULL) tiempo = new int;
    else{
        int aux = Vestado->calculate();
        if(aux>30 && sensor==S_enemigo){ // SI TIENE MORAL Y VE AL ENEMIGO ATACA // ATACAR
        }
        //else if (aux<50 && aux>30 && compañero cerca){}//AVISAR POR RADIO
        //else if (aux<30 && sensor==S_enemigo && alarma cerca) //DAR ALARMA
        else if (aux<30 && sensor==S_enemigo){state=FRIGHTENED;}//CAMBIAR DE ESTADO A ASUSTADO
        else if (sensor==S_inactivo && *tiempo<40){state=ALERT;}//CAMBIAR DE ESTADO A ALERTA
        tiempo++;
    }
}
void DecisionSystem::frightened(){
    /*
     ASUSTADO
     HUIR
     CAMBIAR DE ESTADO A ESTÁNDAR
     AVISAR A OTROS NPCs CERCANOS
     DAR ALARMA
     AVISAR POR RADIO
     CAMBIAR A ESTADO DE ALERTA
     CAMBIAR A ESTADO DE SOSPECHA
     */
}
void DecisionSystem::updateDecision(){
    Vestado->updateVstate();
    switch (DecisionSystem::state) {
        case STANDAR: standar();break;
        case SUSPECT: suspect();break;
        case ALERT: alert();break;
        case INCOMBAT: inCombat();break;
        case FRIGHTENED: frightened();break;
        default:standar();break;
    }
}

