//
//  NodoMover.cpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "NodoMover.hpp"
//#include "trigger_system.hpp"


#define VELOCIDAD 2

NodoMover::NodoMover(){
    aux=-1;
}


NodoMover::~NodoMover(){}
short NodoMover::run(int &id){
    //cout << "NODO MOVER" << endl;
    
    NpcLibrary::instancia()->recover_book(id)->resetVectorMovimiento();
    
    if (NpcLibrary::instancia()->recover_book(id)->lastPosition()) {
        if(aux==-1)
            return updatePosition(id);
        else
            return updateVMovement(id);
    }
    return true;
}

short NodoMover::updateVMovement(int &id){
    dvector3D * _movement = NpcLibrary::instancia()->recover_book(id)->VectorMovimiento;
    
    _movement->x = xABS*((VELOCIDAD*100/aux)/100);
    _movement->y = yABS*((VELOCIDAD*100/aux)/100);
    _movement->z = 0;
    
    aux = -1;
    
    _movement = nullptr;
    return RUNNING;
}
short NodoMover::updatePosition(int &id){
    
    dvector3D posPropia = *NpcLibrary::instancia()->recover_book(id)->getPosition();
    dvector3D posObjetivo = *NpcLibrary::instancia()->recover_book(id)->lastPosition();
    aux = EasyMath::EucCalcularDistancia(posPropia,posObjetivo);
    xABS = posObjetivo.x-posPropia.x;
    yABS = posObjetivo.y-posPropia.y;
    
    if(aux<1.5f){
        NpcLibrary::instancia()->recover_book(id)->updatePilaObjetivo();
        aux = -1;
    }
    
    return RUNNING;
}
