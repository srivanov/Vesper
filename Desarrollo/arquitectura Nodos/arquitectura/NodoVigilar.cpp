//
//  NodoVigilar.cpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "NodoVigilar.hpp"
#include "BlackBoards.hpp"

#define ESTANDAR 0
#define ALERTA 1
#define COMBATE 2

#define TIEMPO_VIGILIA 10
#define TIEMPO_ESTADO_ALTERADO 10

NodoVigilar::NodoVigilar(){_time = 0;}
NodoVigilar::~NodoVigilar(){}

short NodoVigilar::run(int &id){
    cout << "VIGILANDO" << std::endl;
    if(_time==0) _time = time(NULL);
    int estado = NPC_library::instance()->getMyBook(&id)->getState();
    if(estado!=ESTANDAR){
        if(_time+TIEMPO_VIGILIA+TIEMPO_ESTADO_ALTERADO<time(NULL)){
            _time = 0;
            if (estado==COMBATE) {
                NPC_library::instance()->getMyBook(&id)->setState(ALERTA);
                return true;
            }
            NPC_library::instance()->getMyBook(&id)->setState(ESTANDAR);
            return true;
        }
    }else{
        if(_time+TIEMPO_VIGILIA<time(NULL)){
            _time = 0;
            return true;
        }
    }
    return false;
    /*
     if(NPC_library::instance()->getMyBook(&id)->getPosObjetivo()!=vigilar)
     NPC_library::instance()->getMyBook(&id)->setPosObjetivo(vigilar);
     else{
     // TO DO: RESUMIR LLAMADAS WITHOUT ID
     if(aux==-1){
     aux = CalcularDistancia(*NPC_library::instance()->getMyBook(&id)->getPosition(), *NPC_library::instance()->getMyBook(&id)->getPosObjetivo());
     xABS = NPC_library::instance()->getMyBook(&id)->getPosObjetivo()->x-NPC_library::instance()->getMyBook(&id)->getPosition()->x;
     yABS = NPC_library::instance()->getMyBook(&id)->getPosObjetivo()->y-NPC_library::instance()->getMyBook(&id)->getPosition()->y;
     }else if(aux>0 && aux<0.1){
     aux=-1;
     return true;
     }else{
     float y,x;
     if(aux<2){
     x = xABS;
     y = yABS;
     }else{
     float por = (100/aux);
     x = xABS*(por/100);
     y = yABS*(por/100);
     }
     _movement->x = x;
     _movement->y = y;
     _movement->z = 0;
     NPC_library::instance()->getMyBook(&id)->setVMovement(_movement);
     aux = -1;
     }
     }*/
    return false;
}
