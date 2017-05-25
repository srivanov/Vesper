//
//  Nodo_AAtacar.cpp
//  vesper
//
//  Created by Gaspar Rodriguez Valero on 7/4/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Nodo_AAtacar.hpp"

#define VELOCIDAD 4

short Nodo_AAtacar::run(const int &ID){
    NpcBook * book = NpcLibrary::instancia()->recover_book(ID);
    
    updatePosition(ID);
    
    book->resetVectorMovimiento();
    
    if(aux<8.0f){
        
        return updateVMovement(ID);
        
    }else{
        book->Enemigo = false;
        book->Evento = true;
        book->remove_EventsByType(P_ENEMIGO);
    }
    
    return FUNCIONO;
}


short Nodo_AAtacar::updateVMovement(const int &id){
    dvector3D * _movement = NpcLibrary::instancia()->recover_book(id)->VectorMovimiento;
    
    _movement->x = xABS*((VELOCIDAD*100/aux)/100);
    _movement->y = yABS*((VELOCIDAD*100/aux)/100);
    _movement->z = 0;
   
    return RUNNING;
}
void Nodo_AAtacar::updatePosition(const int &id){
    NpcBook * book = NpcLibrary::instancia()->recover_book(id);
    
    
    dvector3D posPropia = *book->getPosition();
    dvector3D posObjetivo = *book->posPlayer;
    aux = EasyMath::EucCalcularDistancia(posPropia,posObjetivo);
    xABS = posObjetivo.x-posPropia.x;
    yABS = posObjetivo.y-posPropia.y;
}

