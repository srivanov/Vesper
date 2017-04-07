//
//  Enemy.cpp
//  Arquitectura
//
//  Created by Gaspar Rodriguez Valero on 16/3/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#include "Enemy.hpp"

Enemy::Enemy(){
	component * componente = new ataque();
	componentes.insert(std::pair<const ComponentType,component*>(ATAQUE,componente));
	componente->setFather(this);
	
	Arbol = Behaviour_tree2::instancia()->ArbolPorDefecto();
    addNodo("3d/muro.3ds");
    setTexture("3d/naranja.jpg");
    t.start();
}

Enemy::~Enemy(){
    delete Arbol;
    NpcLibrary::instancia()->remove_book(m_ID);
    gestor_eventos::instance()->eliminarme(m_ID);
}

void Enemy::update(){
    
    if(t.tTranscurrido(6.f)){
        book->sed+=2;
        book->hambre++;
        t.reset();
    }
    
    if(book->salud <= 0){
        eliminar = true;
        return;
    }
    
    if (book->Evento) {Arbol->reset();book->Evento = false;}
    book->updateBook();
    Arbol->run(m_ID);
    
    mover(*book->VectorMovimiento);
    dvector3D aux = *getPosition() + *book->VectorMovimiento;
    rotarConRaton(aux);
    
    
    GameObject::update();
}

void Enemy::inicializar(int& ID){
    m_ID = ID;
    book = NpcLibrary::instancia()->add_book(m_ID, getPosition());
    gestor_eventos::instance()->subscribirse(book);
}

void Enemy::contacto(PhysicObject *g){
	if(g){
		if(g && g->getObjectType()==BALA){
			 //Bala * bullet = static_cast<Bala*>(g);
			 book->salud-=20;
		}
		if(g->getObjectType() == PLAYER)
			printf("ENEMIGO CONTACTO\n");
	}
}


