//
//  Nodo_VidaBaja.cpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Nodo_VidaBaja.hpp"

#define UMBRAL_VIDA 30



Nodo_VidaBaja::Nodo_VidaBaja(){}
Nodo_VidaBaja::~Nodo_VidaBaja(){}
short Nodo_VidaBaja::run(int &id){
    //cout << " NODO VIDA BAJA?" << endl;
    if(!NpcLibrary::instancia()->recover_book(id)) return false;
    
    if(NpcLibrary::instancia()->recover_book(id)->salud<=UMBRAL_VIDA)
        return true;
    return false;
}
