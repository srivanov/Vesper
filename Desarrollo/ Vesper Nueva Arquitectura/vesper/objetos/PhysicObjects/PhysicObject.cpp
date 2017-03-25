//
//  PhysicObject.cpp
//  Arquitectura
//
//  Created by Gaspar Rodriguez Valero on 16/3/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#include "PhysicObject.hpp"

PhysicObject::PhysicObject(){
    eliminar = false;
    
     
     component * componente = new physics();
     componentes.insert(
     std::pair<const ComponentType,component*>(PHYSICS,componente)
     );
     componente->setFather(this);
    
}

void PhysicObject::setPosition(dvector3D &pos){
    m_pos = pos;
    
     
     physics* go = static_cast<physics*>(componentes.find(PHYSICS)->second);
     if(go != NULL)
         go->setPosition(pos);
     class render* ren = (static_cast<class render*>(componentes.find(RENDER)->second));
     if(ren != NULL)
        ren->setNodePosition(pos);
     
     
    
}

void PhysicObject::setDirDisparo(dvector3D &dir){
    anguloDisparo = dir;
}

void PhysicObject::rotarConRaton(dvector3D &posRaton){
    
    
    physics* go = static_cast<physics*>(componentes.find(PHYSICS)->second);
    if(go != NULL)
        m_rot.z = go->rotarConRaton(posRaton);
    class render* ren = (static_cast<class render*>(componentes.find(RENDER)->second));
    if(ren != NULL)
        ren->setNodeRotation(m_rot);
     
    
}


void PhysicObject::setRotation(dvector3D &rot){
    m_rot = rot;
     physics* go = static_cast<physics*>(componentes.find(PHYSICS)->second);
     if(go != NULL)
        go->rotar(m_rot.z);
     class render* ren = (static_cast<class render*>(componentes.find(RENDER)->second));
     if(ren != NULL)
        ren->setNodeRotation(m_rot);
     
}

void PhysicObject::createPhysicsBody(const BodyObject body, dvector3D dim){
    physics* fisica = static_cast<physics*>(componentes.find(PHYSICS)->second);
    if(body==DYNAMIC_BODY)
        fisica->crearBodyDinamico(dim, m_pos);
    else
        fisica->crearBodyEstatico(dim, m_pos, 90.f);
}

void PhysicObject::mover(dvector3D &vel){
    
    physics* go = static_cast<physics*>(componentes.find(PHYSICS)->second);
    if(go != NULL)
        go->setVelocity(vel);
}
