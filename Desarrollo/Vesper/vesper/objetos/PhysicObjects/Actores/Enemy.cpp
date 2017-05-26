//
//  Enemy.cpp
//  Arquitectura
//
//  Created by Gaspar Rodriguez Valero on 16/3/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#include "Enemy.hpp"
#include "../Bala.hpp"

dvector3D * patrulla::getNextPosPatrulla(){
    if(posicion_actual++>posiciones.size())
        posicion_actual = 0;
    return posiciones[posicion_actual];
}

void patrulla::addPosPatrulla(dvector3D * pos){
    posiciones.push_back(pos);
}

Enemy::Enemy() : patrullar(nullptr) , posP(nullptr) {
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
    
    updateStats();
    comprobar_vision();
    STD();
    book->updateBook();
    memory->update();
    
    if(!book->Patrullar && patrullar)
        book->notify(m_ID, P_PATRULLAR, patrullar->getNextPosPatrulla());
    
    
    
    if(book->VectorMovimiento->x != 0.f || book->VectorMovimiento->y != 0.f)
        lastView = *book->VectorMovimiento;
    
    
    mover(*book->VectorMovimiento);
    dvector3D aux = *getPosition() + lastView;
    rotarAposicion(aux);
    GameObject::update();
}

void Enemy::updateStats(){
    if(t.tTranscurrido(6.f)){
        book->sed+=2;
        book->hambre++;
        t.reset();
    }
    
    if(book->salud <= 0){
        eliminar = true;
        return;
    }
}
void Enemy::STD(){
    if (book->Evento) {
        Arbol->reset();
        book->Evento = false;
    }
    Arbol->run(m_ID);
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
			 book->salud-=static_cast<Bala*>(g)->getDamage();
        else if(g->getObjectType() == PLAYER){
            posP = g->getPosition();
        }else if(memory->evalue(g) == CHANGED){
            book->notify(m_ID, P_RUIDO, g->getPosition());
            if(g->getObjectType()==FUENTE){
                LevelBlackBoard::instance()->CreateRecord(g->getObjectID(), P_SED, g->getPosition());
            }
            else if(g->getObjectType()==ALARMA){
                LevelBlackBoard::instance()->CreateRecord(g->getObjectID(), P_ALARMA, g->getPosition());
            }else if(g->getObjectType()==PUERTA){
                book->Aviso = true;
            }
        }
	}
}

void Enemy::comprobar_vision(){
    if(posP){
        if(EasyMath::EucCalcularDistancia(*getPosition(), *posP) < 6.0f){
            physics * ph = static_cast<physics*>(componentes.find(PHYSICS)->second);
            if(!ph->RayCastControl(*getPosition(), posP) && !book->ExistEventByType(P_ENEMIGO))
                book->notify(m_ID, P_ENEMIGO, posP);
        }else
            return;
        
    }
}
