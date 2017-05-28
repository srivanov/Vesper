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
    class render * r = static_cast<class render*>(componentes.find(RENDER)->second);
    r->AnimateNode(true);
    dead = false;
    //addNodo("3d/m1/andar/andar.obj");
    
    srand(t.getActual());
    
    unsigned int monster = rand() % 3 + 1 ;
    std::string ruta = "3d/";
    
    ruta += "m"+to_string(monster)+"/";
    
    r->addAnimation(ruta+"reposo/","reposo.obj", 0.5f);
    r->addAnimation(ruta+"muerte/","muerte.obj", 0.7f);
    r->addAnimation(ruta+"comer/","comer.obj", 0.5f);
    r->addAnimation(ruta+"recibirDisparo/","recibirDisparo.obj", 0.7f);
    r->addAnimation(ruta+"andar/","andar.obj", 0.1f);
    r->addAnimation(ruta+"zarpazo/","zarpazo.obj", 0.7f);
    
    char* text = (char*)(ruta+"Monstruo"+to_string(monster)+"_Diffuse.png").c_str();
    setTexture(text);
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
    
    
    
    if(book->VectorMovimiento->x != 0.f || book->VectorMovimiento->y != 0.f){
        lastView = *book->VectorMovimiento;
        NextAnimation(ANDAR);
    }else{
        NextAnimation(REPOSO);
    }
    
    
    
    mover(*book->VectorMovimiento);
    dvector3D aux = *getPosition() + lastView;
    rotarAposicion(aux);
    PhysicObject::update();
}

void Enemy::updateStats(){
    if(t.tTranscurrido(5.f) && !dead){
        book->sed+=2;
        book->hambre++;
        t.reset();
    }
    
    if(book->salud <= 0){
        if(!dead) {
            t.reset();
            dead = true;
            
        }
        NextAnimation(MUERTE);
        if(t.tTranscurrido(2.0f)){
            eliminar = true;
        }
        return;
    }
}

void Enemy::NextAnimation(EEnemyAnimations e){
    class render * r = static_cast<class render*>(componentes.find(RENDER)->second);
    std::string anim;
    switch (e) {
        case ANDAR:     anim="andar";   break;
        case COMER:     anim="comer";   break;
        case REP_DISP:  anim="disparo"; break;
        case ZARPAZO:   anim="zarpazo"; break;
        case MUERTE:    anim="muerte";  break;
        default:        anim="reposo";  break;
    }
    r->changeAnimation(anim);
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
    m_rot.x+=90;
}

void Enemy::contacto(PhysicObject *g){
    
	if(g){
        if(g->getObjectType()>SALIDA && g->getObjectType()!=BALA)
            return;
		if(g->getObjectType()==BALA)
			 book->salud-=static_cast<Bala*>(g)->getDamage();
        else if(g->getObjectType() == PLAYER)
            posP = g->getPosition();
        else if(memory->evalue(g) == CHANGED){
            book->notify(m_ID, P_RUIDO, g->getPosition());
            if(g->getObjectType()==FUENTE)
                LevelBlackBoard::instance()->CreateRecord(g->getObjectID(), P_SED, g->getPosition());
            else if(g->getObjectType()==ALARMA)
                LevelBlackBoard::instance()->CreateRecord(g->getObjectID(), P_ALARMA, g->getPosition());
            else if(g->getObjectType()==PUERTA)
                book->Aviso = true;
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
