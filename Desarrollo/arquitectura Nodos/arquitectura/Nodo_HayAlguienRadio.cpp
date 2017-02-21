//
//  Nodo_HayAlguienRadio.cpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Nodo_HayAlguienRadio.hpp"


//#############################
//#    NODOS DE CONDICION     #
//#############################

// NODO HAY ALGUIEN RADIO ?
Nodo_HayAlguienRadio::Nodo_HayAlguienRadio(){}
Nodo_HayAlguienRadio::~Nodo_HayAlguienRadio(){}
short Nodo_HayAlguienRadio::run(int &id){
    /*
    if(World_BlackBoard::instance()->existRecord(R_CERCA, id)) return false;
    if(World_BlackBoard::instance()->existRecord(R_RADIO, id)){
        if(World_BlackBoard::instance()->hasAnswer(R_RADIO, id)){
            return true;
        }
        return false;
    }
    World_BlackBoard::instance()->addRecord(R_RADIO, id, NPC_library::instance()->getMyBook(id)->getPosition());
        
    //cout << " NODO HAY NPCS POR RADIO?" << endl;
    */
    return false;
}
