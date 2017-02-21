//
//  Nodo_NecesitoAyuda.cpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Nodo_NecesitoAyuda.hpp"

Nodo_NecesitoAyuda::~Nodo_NecesitoAyuda(){}

Nodo_NecesitoAyuda::Nodo_NecesitoAyuda(){}

short Nodo_NecesitoAyuda::run(int &id){
    //cout << " NODO NECESITO AYUDA ?" << endl;
    if(!NpcLibrary::instancia()->recover_book(id)) return false;
    
    return false;
}
