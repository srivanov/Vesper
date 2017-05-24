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
//    addNodo("3d/muro.obj");
    switch (m_tipo) {
//        case PALA:          setTexture("3d/pala.png");break;
//        case MONEDAS:       setTexture("3d/moneda.png");break;
//        case PIEDRA:        setTexture("3d/piedra.png");break;
//        case ESCOPETA:      setTexture("3d/letraE.png");break;
//        case SWEET_SHOOTER: setTexture("3d/letraL.png");break;
//        case GLOBO_AGUA:    setTexture("3d/globoagua.png");break;
//        case BUMMER_BOOM:   setTexture("3d/chicle.png");break;
//        case BOMBA_HUMO:    setTexture("3d/bombahumo.png");break;
//        case LLAVE:
//            LLave_value = m_ID;
//            setTexture("3d/llave.png");
//            break;

        case PALA:          addNodo("3d/pala.obj");break;
        case MONEDAS:       addNodo("3d/moneda.obj");break;
        case PIEDRA:        addNodo("3d/Piedra.obj");break;
        case ESCOPETA:      addNodo("3d/escopeta.obj");break;
        case SWEET_SHOOTER: addNodo("3d/lanzacaramelos.obj");break;
        case GLOBO_AGUA:    addNodo("3d/globo_agua.obj");break;
        case BUMMER_BOOM:   addNodo("3d/chicle.obj");break;
        case BOMBA_HUMO:    addNodo("3d/bomba_humo.obj");break;
        case LLAVE:
            LLave_value = m_ID;
            addNodo("3d/llave.obj");
            break;
        default:
            break;
            dvector3D m = *getPosition();
            m.z = 2;
            setPosition(m);
    }
}
