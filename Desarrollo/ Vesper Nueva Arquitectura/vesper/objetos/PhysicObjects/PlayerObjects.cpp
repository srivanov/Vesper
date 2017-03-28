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

void PlayerObjects::inicializar(int ID){
    m_ID = ID;
    addNodo("3d/muro.3ds");
    switch (m_tipo) {
        case PALA:          setTexture("3d/pala.jpg");break;
        case MONEDAS:       setTexture("3d/moneda.jpg");break;
        case PIEDRA:        setTexture("3d/piedra.jpg");break;
        case ESCOPETA:      setTexture("3d/letraE.png");break;
        case SWEET_SHOOTER: setTexture("3d/letraL.png");break;
        case GLOBO_AGUA:    setTexture("3d/globoagua.png");break;
        case BUMMER_BOOM:   setTexture("3d/chicle.png");break;
        case BOMBA_HUMO:    setTexture("3d/bombahumo.png");break;
        case LLAVE:
            LLave_value = m_ID;
            setTexture("3d/llave.jpg");
            break;
        default:
            break;
    }
}
