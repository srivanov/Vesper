//
//  Nodo_HayParaHablar.cpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Nodo_HayParaHablar.hpp"
#include "BlackBoards.hpp"

#define EVENTO_HABLAR 2


Nodo_HayParaHablar::Nodo_HayParaHablar(){}

Nodo_HayParaHablar::~Nodo_HayParaHablar(){}

short Nodo_HayParaHablar::run(int &id){
    if (NPC_library::instance()->getMyBook(&id)->EventUsed(EVENTO_HABLAR)) {
        NPC_library::instance()->getMyBook(&id)->EventPosObjetivo(EVENTO_HABLAR);
        return true;
    }
    cout << " NODO ALGUIEN HABLAR?" << endl;
    /*######################################
     TRIGGER SYSTEM
     #####################################*/
    return false;
}
