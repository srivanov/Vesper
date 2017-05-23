//
//  GameObject.cpp
//  Arquitectura
//
//  Created by Gaspar Rodriguez Valero on 15/3/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#include "GameObject.hpp"

GameObject::GameObject(){
     component * componente = new class render();
     componentes.insert(std::pair<const ComponentType,component*>(RENDER,componente));
     componente->setFather(this);
	first = true;
}

void GameObject::inicializar(int ID){ //que reciba tb el tipo de la puerta
    m_ID = ID;
}

GameObject::~GameObject(){
    for (it = componentes.begin(); it!=componentes.end(); it++)
        delete it->second;
}

void GameObject::setPosition(dvector3D &position){
    prev_pos = m_pos;
	m_pos = position;
	if(first){
		prev_pos = posicion;
		first = false;
	}
    class render* ren = (static_cast<class render*>(componentes.find(RENDER)->second));
    if(ren != NULL)
        ren->setNodePosition(position);
}

void GameObject::setRotation(dvector3D& rotation){
	
	class render* ren = (static_cast<class render*>(componentes.find(RENDER)->second));
	if(ren != NULL){
		prev_rot = m_rot;
		m_rot = rotation;
		ren->setNodeRotation(rotation);
	}
}

void GameObject::update(){
    for (it = componentes.begin(); it!=componentes.end(); it++)
        it->second->update();
}

void GameObject::addNodo(char* filename){
    class render* ren = static_cast<class render*>(componentes.find(RENDER)->second);
    if(ren != NULL){
        ren->setNode(filename);
    }
}

void GameObject::setTexture(char* filename){
    class render* ren = static_cast<class render*>(componentes.find(RENDER)->second);
    if(ren != NULL){
        ren->setNodeTexture(filename);
    }
}

void GameObject::render(float &interpolation){
	class render* ren = (class render*)findComponent("render");
	if(ren != NULL){
		//		ren->setNodeRotation(rotacion);
		ren->DrawNode(prev_pos, m_pos, prev_rot, m_rot, interpolation);
	}
}



