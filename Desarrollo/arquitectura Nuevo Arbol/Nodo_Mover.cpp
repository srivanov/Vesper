//
//  Nodo_Mover.cpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 22/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Nodo_Mover.hpp"

#define VELOCIDAD 2


Nodo_Mover::~Nodo_Mover(){}
short Nodo_Mover::run(const int &id){
    ////cout << "NODO MOVER" << endl;
    
    NpcBook * book = NpcLibrary::instancia()->recover_book(id);
    
    book->resetVectorMovimiento();
    
    if(book->lastPosition()){
        if(aux==-1)
            return updatePosition(id);
        else
            return updateVMovement(id);
    }
    return FUNCIONO;
}

short Nodo_Mover::updateVMovement(const int &id){
    dvector3D * _movement = NpcLibrary::instancia()->recover_book(id)->VectorMovimiento;
    
    _movement->x = xABS*((VELOCIDAD*100/aux)/100);
    _movement->y = yABS*((VELOCIDAD*100/aux)/100);
    _movement->z = 0;
    
    aux = -1;
    return RUNNING;
}
short Nodo_Mover::updatePosition(const int &id){
    NpcBook * book = NpcLibrary::instancia()->recover_book(id);
    
    
    dvector3D posPropia = *book->getPosition();
    dvector3D posObjetivo = *book->lastPosition();
    aux = EasyMath::EucCalcularDistancia(posPropia,posObjetivo);
    xABS = posObjetivo.x-posPropia.x;
    yABS = posObjetivo.y-posPropia.y;
    
    if(aux<1.5f){
        book->updateObjetivo();
        reset();
    }
    return RUNNING;
}

void Nodo_Mover::reset(){aux=-1;}
