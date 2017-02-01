//
//  Nodo_SuenaAlarma.cpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Nodo_SuenaAlarma.hpp"
#include "BlackBoards.hpp"

#define ALERTA 1
#define EVENTO_ALARMA 4



Nodo_SuenaAlarma::Nodo_SuenaAlarma(){}

Nodo_SuenaAlarma::~Nodo_SuenaAlarma(){}
short Nodo_SuenaAlarma::run(int &id){
    if (NPC_library::instance()->getMyBook(&id)->EventUsed(EVENTO_ALARMA)) {
        NPC_library::instance()->getMyBook(&id)->setState(ALERTA);
        return true;
    }
    cout << " NODO SUENA ALARMA?" << endl;
    /*######################################
     TRIGGER SYSTEM
     #####################################*/
    return false;
}
