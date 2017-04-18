//
//  Rehen.cpp
//  Arquitectura
//
//  Created by Gaspar Rodriguez Valero on 16/3/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#include "Rehen.hpp"
#include "../../../Arquitectura IA/gestor_eventos.hpp"

Rehen::Rehen(){
	addNodo("3d/muro.3ds");
	setTexture("3d/rehen.jpg");
    m_brain = new RehenIA(getPosition());
    gestor_eventos::instance()->subscribirse(this);
}

Rehen::~Rehen(){delete m_brain;}

void Rehen::contacto(PhysicObject * g){
    if (g && g->getObjectType()==PLAYER) {
        if(!m_brain->inicializado()){
            m_brain->inicializar(g->getPosition(),*getPosition());
        }
        
        m_brain->changeState(SIGUIENDO);
    }
}

void Rehen::update(){
    m_brain->update();
    dvector3D mov = m_brain->Vmover();
    dvector3D rot = *getPosition() + mov;
    mover(mov);
    rotarConRaton(rot);
    PhysicObject::update();
    
}

void Rehen::asustado(){m_brain->changeState(ASUSTADO);}

void Rehen::contactoEnd(PhysicObject*){

}
