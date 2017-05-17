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
    
    switch (m_tipo) {
        case PALA:          addNodo("3d/pala.obj");setTexture("3d/pala_Diffuse.png");break;
        case MONEDAS:       addNodo("3d/moneda.obj");setTexture("3d/moneda_Diffuse.png");break;
        case PIEDRA:        addNodo("3d/Piedra.obj");setTexture("3d/Piedra_Diffuse.png");break;
        case ESCOPETA:      addNodo("3d/escopeta.obj");setTexture("3d/escopeta_diffuse.png");break;
        case SWEET_SHOOTER: addNodo("3d/lanzacaramelos.obj");setTexture("3d/lanzacaramelos_Diffuse.png");break;
        case GLOBO_AGUA:    addNodo("3d/muro.3ds");setTexture("3d/globoagua.png");break;
        case BUMMER_BOOM:   addNodo("3d/muro.3ds");setTexture("3d/chicle.png");break;
        case BOMBA_HUMO:    addNodo("3d/muro.3ds");setTexture("3d/bombahumo.png");break;
        case LLAVE:
            LLave_value = m_ID;
            addNodo("3d/key.obj");
            setTexture("3d/key_Diffuse.png");
            break;
        default:
            break;
    }
    /*
    dvector3D rotar = dvector3D(0,90,0);
    setRotation(rotar);*/
}
