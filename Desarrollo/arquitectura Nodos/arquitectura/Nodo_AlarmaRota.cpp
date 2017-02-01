//
//  Nodo_AlarmaRota.cpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Nodo_AlarmaRota.hpp"

//#############################
//#    NODOS DE CONDICION     #
//#############################

// NODO ALARMA ROTA?
Nodo_AlarmaRota::~Nodo_AlarmaRota(){}

Nodo_AlarmaRota::Nodo_AlarmaRota(){}

short Nodo_AlarmaRota::run(int &id){
    cout << " NODO ALARMA ROTA ?" << endl;
    // WorldInfo->comprobadaAlarma = true;
    //if(WorldInfo->estadoAlarma) return false;
    return true;
}
