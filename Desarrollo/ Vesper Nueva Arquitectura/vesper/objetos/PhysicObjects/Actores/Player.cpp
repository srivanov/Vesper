//
//  Player.cpp
//  Arquitectura
//
//  Created by Gaspar Rodriguez Valero on 16/3/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#include "Player.hpp"

Player::Player(){
    
    arma = new armas;
    componentes.insert(std::pair<ComponentType, component*>(ARMAS,arma));
    
    component * componente = new habilidadEspecial();
	((habilidadEspecial*)componente)->setTipo(tHabINVISIBLE);
    componentes.insert(std::pair<ComponentType, component*>(HABESPECIAL,componente));
    
}

Player::~Player(){}

void Player::update(){
    GameObject::update();
    arma->update();

}

void Player::render(){
    PhysicObject::render();
    arma->render();
}

void Player::atacar(){
    
    if(*(arma->getArmaActual()->getType()) == tPALAc)
        cuerpoacuerpo();
    else
        arma->shoot();
}

void Player::cambiarArma(){
    arma->changeGun();
    //std::cout << *arma->getArmaActual()->getType() << std::endl;
}



void Player::setVelocidad(unsigned int vel){
    velocidad = vel;
}

void Player::activarHab(){
    if(habActiva()){
        habilidadEspecial * hab = static_cast<habilidadEspecial*>(componentes.find(HABESPECIAL)->second);
        hab->activar();
    }
    
}

bool Player::habActiva(){
    habilidadEspecial * hab = static_cast<habilidadEspecial*>(componentes.find(HABESPECIAL)->second);
    return hab->puedoUsar();
}


void Player::contacto(PhysicObject * g){
    if(g != NULL){
        if(g->getObjectType() == PALA){
            //arma->insertarArma(9);
        }
        if(g->getObjectType() == MONEDAS){
            //((habilidadEspecial*)findComponent("habilidadEspecial"))->aumentarMoneda();
        }
        if(g->getObjectType() == ALARMA){
            //
        }
        if(g->getObjectType() == ESCOPETA){
            //arma->insertarArma(2);
        }
        if(g->getObjectType() == SWEET_SHOOTER){
            //arma->insertarArma(3);
        }
        if(g->getObjectType() == GLOBO_AGUA){
            //arma->insertarArma(5);
        }
        if(g->getObjectType() == BUMMER_BOOM){
            //arma->insertarArma(6);
        }
        if(g->getObjectType() == BOMBA_HUMO){
            //arma->insertarArma(7);
        }
    }
    obj_colisionado = g;
}

void Player::addArma(){
    /*
     class render* go = (class render*)findComponent("render");
    if(go != NULL)
        go->anyadirArma();
     */
}



void Player::accionar(){
    /*
    if(obj_colisionado != NULL){
        if(*obj_colisionado->getType() == tALARMA){
            if(!(static_cast<alarma*>(obj_colisionado)->estaActivado())){
                static_cast<alarma*>(obj_colisionado)->activar();
            }
        }else if(*obj_colisionado->getType() == tPUERTA){
            if(!(static_cast<puerta*>(obj_colisionado))->estasAbierta()){
                static_cast<puerta*>(obj_colisionado)->abre();
            }else
                static_cast<puerta*>(obj_colisionado)->cierra();
        }
    }
     */
}

void Player::cuerpoacuerpo(){
    //TO DO: revisar
    /*
    if(obj_colisionado != NULL){
        if(*obj_colisionado->getType() == tALARMA){
            if(*(arma->getArmaActual()->getType()) == tPALAc){
                static_cast<alarma*>(obj_colisionado)->muere();
                obj_colisionado = NULL;
            }
        }else if(*obj_colisionado->getType() == tFUENTE){
            if(*(arma->getArmaActual()->getType()) == tPALAc){
                static_cast<fuente*>(obj_colisionado)->muere();
                obj_colisionado = NULL;
            }
        }
    }
     */
}
