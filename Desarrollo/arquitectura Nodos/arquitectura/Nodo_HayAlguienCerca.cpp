//
//  Nodo_HayAlguienCerca.cpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Nodo_HayAlguienCerca.hpp"
#include "BlackBoards.hpp"


//#############################
//#    NODOS DE CONDICION     #
//#############################

// NODO HAY ALGUIEN CERCA ?
Nodo_HayAlguienCerca::Nodo_HayAlguienCerca(){}
Nodo_HayAlguienCerca::~Nodo_HayAlguienCerca(){}
short Nodo_HayAlguienCerca::run(int &id){
    TypeRecords radio = R_RADIO;
    TypeRecords cercano = R_CERCA;
    if(World_BlackBoard::instance()->existRecord(radio, id)) return false;
    if(World_BlackBoard::instance()->existRecord(cercano, id)){
        if(World_BlackBoard::instance()->hasAnswer(cercano, id)){
            return true;
        }
        return false;
    }
    World_BlackBoard::instance()->addRecord(cercano, id, NPC_library::instance()->getMyBook(&id)->getPosition());
    
    cout << "NODO HAY ALGUIEN CERCA " << endl;
    return false;
}
