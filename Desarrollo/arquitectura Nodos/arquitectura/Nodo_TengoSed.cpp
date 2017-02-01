//
//  Nodo_TengoSed.cpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Nodo_TengoSed.hpp"
#include "BlackBoards.hpp"

#define UMBRAL_SED 70


//#############################
//#    NODOS DE CONDICION     #
//#############################

// NODO TENGO SED ?
Nodo_TengoSed::Nodo_TengoSed(){}
Nodo_TengoSed::~Nodo_TengoSed(){}
short Nodo_TengoSed::run(int &id){
    cout << "NODO TENGO SED" << endl;
    TypeRecords sed = R_FUENTE;
    if(NPC_library::instance()->getMyBook(&id)->getThirst()>UMBRAL_SED){
        if (World_BlackBoard::instance()->existRecord(sed, id)) {
            if (World_BlackBoard::instance()->hasAnswer(sed, id)) {
                NPC_library::instance()->getMyBook(&id)->setPosObjetivo(World_BlackBoard::instance()->getAnswer(sed, id)->_answerInfo);
                return true;
            }
            return false;
        }
        World_BlackBoard::instance()->addRecord(sed, id, NPC_library::instance()->getMyBook(&id)->getPosition());
    }
    return false;
}
