//
//  Nodo_HayParaHablar.cpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Nodo_HayParaHablar.hpp"

#define EVENTO_HABLAR 3


Nodo_HayParaHablar::Nodo_HayParaHablar(){}

Nodo_HayParaHablar::~Nodo_HayParaHablar(){}

short Nodo_HayParaHablar::run(int &id){
    //cout << " NODO ALGUIEN HABLAR?" << endl;
    
    NpcBook * book = NpcLibrary::instancia()->recover_book(id);
    if (book->ExistEventByType(P_HABLAR)) return true;
    return false;
}
