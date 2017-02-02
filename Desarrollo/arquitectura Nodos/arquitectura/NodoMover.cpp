//
//  NodoMover.cpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "NodoMover.hpp"
#include "BlackBoards.hpp"
//#include "trigger_system.hpp"

#define RUNNING 2


NodoMover::NodoMover(){_movement=new dvector3D(0,0,0);aux=-1;}

NodoMover::~NodoMover(){delete _movement;}
short NodoMover::run(int &id){
    cout << "NODO MOVER" << endl;
    if(_movement==NULL) _movement = new dvector3D;
    if(aux==-1){
        dvector3D posObjetivo,posPropia;
        posPropia = *NPC_library::instance()->getMyBook(&id)->getPosition();
        posObjetivo = *NPC_library::instance()->getMyBook(&id)->getPosObjetivo();
        aux = EasyMath::CalcularDistancia(posPropia,posObjetivo);
        xABS = posObjetivo.x-posPropia.x;
        yABS = posObjetivo.y-posPropia.y;
    }else if(aux>0 && aux<1.5f){
        NPC_library::instance()->getMyBook(&id)->updateEvent();
        aux=-1;
        return true;
    }else{
        float y=0,x=0;
        if(aux<2){
            x = xABS;
            y = yABS;
        }else{
            float por = (2*100/aux);
            x = xABS*(por/100);
            y = yABS*(por/100);
        }
        _movement->x = x;
        _movement->y = y;
        _movement->z = 0;
        NPC_library::instance()->getMyBook(&id)->setVMovement(_movement);
        aux = -1;
    }
    return RUNNING;
}
//float NodoMover::CalcularDistancia(dvector3D a, dvector3D b){
//    float x = fabs(a.x-b.x);
//    float y = fabs(a.y-b.y);
//    return x+y;
//}
