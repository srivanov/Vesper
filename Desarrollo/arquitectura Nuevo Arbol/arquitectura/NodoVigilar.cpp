//
//  NodoVigilar.cpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "NodoVigilar.hpp"

#define TIEMPO_VIGILIA 10
#define TIEMPO_ESTADO_ALTERADO 10

NodoVigilar::NodoVigilar(){_time = 0;}
NodoVigilar::~NodoVigilar(){}

short NodoVigilar::run(int &id){
    return true;
    //cout << "VIGILANDO" << std::endl;
    if(_time==0) _time = time(NULL);
    int estado = NpcLibrary::instancia()->recover_book(id)->estado;
    if(estado!=ESTANDAR){
        if(_time+TIEMPO_VIGILIA+TIEMPO_ESTADO_ALTERADO<time(NULL)){
            _time = 0;
            if (estado==COMBATE) {
                NpcLibrary::instancia()->recover_book(id)->estado = ALERTA;
                return true;
            }
            NpcLibrary::instancia()->recover_book(id)->estado = ESTANDAR;
            return true;
        }
    }else{
        if(_time+TIEMPO_VIGILIA<time(NULL)){
            _time = 0;
            return true;
        }
    }
    return false;
}
