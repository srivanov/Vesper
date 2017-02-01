//
//  Nodo_EstasCercaJugador.cpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Nodo_EstasCercaJugador.hpp"


//#############################
//#    NODOS DE CONDICION     #
//#############################

// NODO ESTAS CERCA JUGADOR ?
Nodo_EstasCercaJugador::Nodo_EstasCercaJugador(){}
Nodo_EstasCercaJugador::~Nodo_EstasCercaJugador(){}
short Nodo_EstasCercaJugador::run(int &id){
    cout << " NODO ESTAS CERCA DEL PLAYER?" << endl;
    return false;
}
