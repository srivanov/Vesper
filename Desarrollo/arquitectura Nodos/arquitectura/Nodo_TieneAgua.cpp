//
//  Nodo_TieneAgua.cpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Nodo_TieneAgua.hpp"

//#############################
//#    NODOS DE CONDICION     #
//#############################

// NODO TIENE AGUA ?
Nodo_TieneAgua::Nodo_TieneAgua(){}

Nodo_TieneAgua::~Nodo_TieneAgua(){}

short Nodo_TieneAgua::run(int &id){
    cout << " NODO FUENTE TIENE AGUA?" << endl;
    
    return true;
}
