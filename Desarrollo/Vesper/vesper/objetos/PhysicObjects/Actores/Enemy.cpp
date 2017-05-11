//
//  Enemy.cpp
//  Arquitectura
//
//  Created by Gaspar Rodriguez Valero on 16/3/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#include "Enemy.hpp"

dvector3D * patrulla::getNextPosPatrulla(){
    if(posicion_actual++>posiciones.size())
        posicion_actual = 0;
    return posiciones[posicion_actual];
}

void patrulla::addPosPatrulla(dvector3D * pos){
    posiciones.push_back(pos);
}

Enemy::Enemy() : patrullar(nullptr){
	component * componente = new ataque();
	componentes.insert(std::pair<const ComponentType,component*>(ATAQUE,componente));
	componente->setFather(this);
	
	Arbol = Behaviour_tree2::instancia()->ArbolPorDefecto();
    addNodo("3d/muro.3ds");
    setTexture("3d/naranja.jpg");
    t.start();
    memory = new MemoryObjects;
}

Enemy::~Enemy(){
    delete patrullar;
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
    
    if (book->Evento) {
        Arbol->reset();
        book->Evento = false;
    }
    if(!book->Patrullar && patrullar){
        book->notify(m_ID, P_PATRULLAR, patrullar->getNextPosPatrulla());
    }
    book->updateBook();
    memory->update();
    Arbol->run(m_ID);
    
    
    mover(*book->VectorMovimiento);
    dvector3D aux = *getPosition() + *book->VectorMovimiento;
    rotarConRaton(aux);
    
    GameObject::update();
}

void Enemy::inicializar(int& ID , bool pat, vector<dvector3D*> pos){
    m_ID = ID;
    book = NpcLibrary::instancia()->add_book(m_ID, getPosition());
    gestor_eventos::instance()->subscribirse(book);
    book->notify(m_ID, P_VIGILAR, getPosition());
    if(pat && pos.size()>1){
        patrullar = new patrulla;
        for (size_t i=0; i<pos.size(); i++) {
            patrullar->addPosPatrulla(pos[i]);
        }
    }
}

void Enemy::contacto(PhysicObject *g){
	if(g){
        //Bala * bullet = static_cast<Bala*>(g);
		if(g && g->getObjectType()==BALA)
			 book->salud-=20;
        else if(g->getObjectType() == PLAYER)
            if(!book->ExistEventByType(P_ENEMIGO))
                book->notify(m_ID, P_ENEMIGO, g->getPosition());
        else if(memory->evalue(g) == CHANGED)
            book->notify(m_ID, P_AVISO, g->getPosition());
	}
}


