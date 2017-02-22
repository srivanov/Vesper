//
//  Nodo_HayRuido.cpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Nodo_HayRuido.hpp"


Nodo_HayRuido::Nodo_HayRuido(){}

Nodo_HayRuido::~Nodo_HayRuido(){}
short Nodo_HayRuido::run(int &id){
    //cout << " NODO HAY RUIDO ?" << endl;
    
    if (NpcLibrary::instancia()->recover_book(id)->Ruido) {
        cout << "ESCUCHE" << endl;
        return true;
    }
    return false;
}
