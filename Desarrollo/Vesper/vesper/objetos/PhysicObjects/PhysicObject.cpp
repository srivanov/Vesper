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
	std::pair<const ComponentType,component*>(PHYSICS,componente));
	componente->setFather(this);
	
}

PhysicObject::~PhysicObject(){
    it = componentes.find(PHYSICS);
    if(it!=componentes.end()){
        delete it->second;
        it->second = NULL;
    }
}

void PhysicObject::setPosition(dvector3D &pos){
	
	physics* go = static_cast<physics*>(componentes.at(PHYSICS));
	if(go != NULL)
		go->setPosition(pos);
//	class render* ren = (static_cast<class render*>(componentes.find(RENDER)->second));
//	if(ren != NULL)
//		ren->setNodePosition(pos);
	GameObject::setPosition(pos);
}

void PhysicObject::setDirDisparo(dvector3D &dir){
    anguloDisparo = dir;
}

void PhysicObject::rotarAposicion(dvector3D &posRaton){
    physics* go = static_cast<physics*>(componentes.at(PHYSICS));
	if(go != NULL){
		prev_rot = m_rot;
		m_rot.z = go->rotarAposicion(posRaton);
	}
//    class render* ren = (static_cast<class render*>(componentes.find(RENDER)->second));
//    if(ren != NULL)
//        ren->setNodeRotation(m_rot);
	GameObject::setRotation(m_rot);
}

void PhysicObject::rotarAraton(dvector3D &posRaton){
	physics* go = static_cast<physics*>(componentes.at(PHYSICS));
	if(go != NULL){
		prev_rot = m_rot;
		m_rot.z = go->rotarAposicion(posRaton,false);
	}
	GameObject::setRotation(m_rot);
}

void PhysicObject::setRotation(dvector3D &rot){
	
	physics* go = static_cast<physics*>(componentes.at(PHYSICS));
	if(go != NULL){
		prev_rot.z = m_rot.z;
		m_rot = rot;
		go->rotar(rot.z);
	}
//	class render* ren = (static_cast<class render*>(componentes.find(RENDER)->second));
//	if(ren != NULL)
//		ren->setNodeRotation(m_rot);
	GameObject::setRotation(m_rot);
}

void PhysicObject::createPhysicsBody(const BodyObject body, dvector3D dim){
    physics* fisica = static_cast<physics*>(componentes.at(PHYSICS));
    if(body==DYNAMIC_BODY)
        fisica->crearBodyDinamico(dim, m_pos);
    else
        fisica->crearBodyEstatico(dim, m_pos, 90.f);
}

void PhysicObject::mover(dvector3D &vel){
    physics* go = static_cast<physics*>(componentes.at(PHYSICS));
    if(go != NULL)
        go->setVelocity(vel);
}
