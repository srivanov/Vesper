//
//  Puerta.cpp
//  Arquitectura
//
//  Created by Gaspar Rodriguez Valero on 16/3/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#include "Puerta.hpp"
#include "Player.hpp"

Puerta::Puerta(){
    addNodo("3d/muro.3ds");
    setTexture("3d/puerta.jpg");
}

void Puerta::contacto(PhysicObject *g){
    if(g && g->getObjectType()==PLAYER){
        if(static_cast<Player*>(g)->getActiveKey()==key)
            eliminar = true;
    }
}
