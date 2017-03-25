//
//  Weapon.cpp
//  Arquitectura
//
//  Created by Gaspar Rodriguez Valero on 16/3/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#include "PlayerObjects.hpp"

PlayerObjects::PlayerObjects(){eliminar = false;}
PlayerObjects::~PlayerObjects(){}

void PlayerObjects::contacto(PhysicObject *g){
    if(g!=nullptr && g->getObjectType()==PLAYER)
        eliminar = true;
}
void PlayerObjects::contactoEnd(PhysicObject *g){
    return;
}
