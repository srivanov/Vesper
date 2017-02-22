//
//  NodoPatrullar.cpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "NodoPatrullar.hpp"


NodoPatrullar::NodoPatrullar(){}

NodoPatrullar::~NodoPatrullar(){}
short NodoPatrullar::run(int &id){
    
    if (NpcLibrary::instancia()->recover_book(id)->ExistEventByType(P_PATRULLAR))
        return true;
    
    return false;
}
