//
//  Nodo_TengoHambre.cpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Nodo_TengoHambre.hpp"
#include "BlackBoards.hpp"

#define UMBRAL_HAMBRE 60


Nodo_TengoHambre::Nodo_TengoHambre(){}

Nodo_TengoHambre::~Nodo_TengoHambre(){}

short Nodo_TengoHambre::run(int &id){
    cout << "NODO TENGO HAMBRE" << endl;
    TypeRecords comida = R_COMIDA;
    if(NPC_library::instance()->getMyBook(&id)->getHungry()>=UMBRAL_HAMBRE){
        if (World_BlackBoard::instance()->existRecord(comida, id)) {
            if (World_BlackBoard::instance()->hasAnswer(comida, id)) {
                NPC_library::instance()->getMyBook(&id)->setPosObjetivo(World_BlackBoard::instance()->getAnswer(comida, id)->_answerInfo);
                return true;
            }
            return false;
        }
        World_BlackBoard::instance()->addRecord(comida, id, NPC_library::instance()->getMyBook(&id)->getPosition());
    }
    return false;
}
