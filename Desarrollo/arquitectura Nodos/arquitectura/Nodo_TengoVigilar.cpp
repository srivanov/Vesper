//
//  Nodo_TengoVigilar.cpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Nodo_TengoVigilar.hpp"
#include "BlackBoards.hpp"

#define EVENTO_VIGILAR 99



Nodo_TengoVigilar::Nodo_TengoVigilar(){}

Nodo_TengoVigilar::~Nodo_TengoVigilar(){}

short Nodo_TengoVigilar::run(int &id){
    cout << "TENGO QUE VIGILAR" << endl;
    if (NPC_library::instance()->getMyBook(&id)->EventUsed(EVENTO_VIGILAR)) {
        NPC_library::instance()->getMyBook(&id)->EventPosObjetivo(EVENTO_VIGILAR);
        return true;
    }
    return  false;
}
