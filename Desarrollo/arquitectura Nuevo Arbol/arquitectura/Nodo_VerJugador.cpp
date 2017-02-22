//
//  Nodo_VerJugador.cpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Nodo_VerJugador.hpp"

//#############################
//#    NODO DE CONDICION     #
//#############################

Nodo_VerJugador::Nodo_VerJugador(){}
Nodo_VerJugador::~Nodo_VerJugador(){}
short Nodo_VerJugador::run(int &id){
    //cout << " NODO VES AL JUGADOR?" << endl;
    
    if (NpcLibrary::instancia()->recover_book(id)->ExistEventByType(P_ENEMIGO))
        return true;
    
    return false;
}
