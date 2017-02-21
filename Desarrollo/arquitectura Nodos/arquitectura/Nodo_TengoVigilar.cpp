//
//  Nodo_TengoVigilar.cpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Nodo_TengoVigilar.hpp"



Nodo_TengoVigilar::Nodo_TengoVigilar(){}

Nodo_TengoVigilar::~Nodo_TengoVigilar(){}

short Nodo_TengoVigilar::run(int &id){
    //cout << "TENGO QUE VIGILAR" << endl;
    if (NpcLibrary::instancia()->recover_book(id)->ExistEventByType(P_VIGILAR))
        return true;
    
    return  false;
}
