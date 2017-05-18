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
    addNodo("3d/Puerta.obj");
    setTexture("3d/Puerta_Diffuse.png");
	key = 1;
    abierta = false;
}

void Puerta::inicializar(int id, const tipoPuerta p){
    pu = p;
    m_ID = id;
    dvector3D rotar = dvector3D(90,90,0);
    setRotation(rotar);
}

void Puerta::activarAlarma(){
    gestor_eventos::instance()->addEvento(m_ID, P_ALERTA, getPosition());
    gestor_eventos::instance()->addEvento(m_ID, P_ALARMA, getPosition());
    cout << "alarma activada" << endl;
}

void Puerta::contacto(PhysicObject *g){
    /*
    if(g && g->getObjectType()==PLAYER){
        if(static_cast<Player*>(g)->getActiveKey()==key){
            eliminar = true;
            if(pu==palarma) activarAlarma();
        }
    }
     */
}
bool Puerta::abrir(int llave){
    if(key!=llave)
        return false;
    
    abierta = true;
    eliminar = true;
    return true;
}
