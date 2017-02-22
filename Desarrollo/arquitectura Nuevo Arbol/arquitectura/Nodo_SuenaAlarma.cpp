//
//  Nodo_SuenaAlarma.cpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Nodo_SuenaAlarma.hpp"

#define ALERTA 1



Nodo_SuenaAlarma::Nodo_SuenaAlarma(){}

Nodo_SuenaAlarma::~Nodo_SuenaAlarma(){}
short Nodo_SuenaAlarma::run(int &id){
    //cout << " NODO SUENA ALARMA?" << endl;
    if (NpcLibrary::instancia()->recover_book(id)->ExistEventByType(P_ALARMA)) {
        cout << "suena" << endl;
        NpcLibrary::instancia()->recover_book(id)->estado = ALERTA;
        return true;
    }
    return false;
}
