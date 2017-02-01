//
//  Nodo_AlarmaCerca.cpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Nodo_AlarmaCerca.hpp"
#include "BlackBoards.hpp"

#define EVENTO_ALARMA_CERCA 5


// NODO ALARMA CERCA?
Nodo_AlarmaCerca::Nodo_AlarmaCerca(){}
Nodo_AlarmaCerca::~Nodo_AlarmaCerca(){}
short Nodo_AlarmaCerca::run(int &id){
    
    if (NPC_library::instance()->getMyBook(&id)->EventUsed(EVENTO_ALARMA_CERCA)) {
        NPC_library::instance()->getMyBook(&id)->EventPosObjetivo(EVENTO_ALARMA_CERCA);
        return true;
    }
    cout << " NODO ALARMA CERCA?" << endl;
    /*######################################
     TRIGGER SYSTEM
     #####################################*/
    return false;
}
