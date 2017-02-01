//
//  Nodo_HayRuido.cpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Nodo_HayRuido.hpp"
#include "BlackBoards.hpp"


#define EVENTO_RUIDO 0


//#############################
//#    NODO DE CONDICION     #
//#############################

// NODO HAY RUIDO

Nodo_HayRuido::Nodo_HayRuido(){}

Nodo_HayRuido::~Nodo_HayRuido(){}
short Nodo_HayRuido::run(int &id){
    cout << " NODO HAY RUIDO ?" << endl;
    if (NPC_library::instance()->getMyBook(&id)->EventUsed(EVENTO_RUIDO)) {
        cout << "ESCUCHE" << endl;
        NPC_library::instance()->getMyBook(&id)->EventPosObjetivo(EVENTO_RUIDO);
        return true;
    }
    return false;
}
