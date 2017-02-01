//
//  Nodo_HayAlguienRadio.cpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Nodo_HayAlguienRadio.hpp"
#include "BlackBoards.hpp"


//#############################
//#    NODOS DE CONDICION     #
//#############################

// NODO HAY ALGUIEN RADIO ?
Nodo_HayAlguienRadio::Nodo_HayAlguienRadio(){}
Nodo_HayAlguienRadio::~Nodo_HayAlguienRadio(){}
short Nodo_HayAlguienRadio::run(int &id){
    TypeRecords radio = R_RADIO;
    TypeRecords cercano = R_CERCA;
    if(World_BlackBoard::instance()->existRecord(cercano, id)) return false;
    if(World_BlackBoard::instance()->existRecord(radio, id)){
        if(World_BlackBoard::instance()->hasAnswer(radio, id)){
            return true;
        }
        return false;
    }
    World_BlackBoard::instance()->addRecord(radio, id, NPC_library::instance()->getMyBook(&id)->getPosition());
        
    cout << " NODO HAY NPCS POR RADIO?" << endl;
    
    return false;
}
