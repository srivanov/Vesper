//
//  Player.cpp
//  Arquitectura
//
//  Created by Gaspar Rodriguez Valero on 16/3/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#include "Player.hpp"
#include "../PlayerObjects.hpp"
#include <iostream>
#include "../World/Puerta.hpp"
#include "../World/Alarm.hpp"
#include "../World/Fuente.hpp"

#define VELOCIDADN 4.f

Player::Player() : obj_colisionado(nullptr){
    action = true;
    arma = new armas;
    componentes.insert(std::pair<ComponentType, component*>(ARMAS,arma));
    arma->setFather(this);
    component * componente = new habilidadEspecial();
	((habilidadEspecial*)componente)->setTipo(tHabINVISIBLE);
    componentes.insert(std::pair<ComponentType, component*>(HABESPECIAL,componente));
    componente->setFather(this);
    
    estado = states::Instance();
    
        
        
        std::string ruta = "3d/";
        
        ruta += "Player"+to_string(estado->character)+"/";
        
        class render * r = static_cast<class render*>(componentes.find(RENDER)->second);
        r->AnimateNode(true);
        
        r->addAnimation(ruta+"Reposo/","reposo.obj", 0.5f);
        r->addAnimation(ruta+"Golpear/","golpear.obj", 0.7f);
        r->addAnimation(ruta+"Correr/","correr.obj", 0.5f);
        r->addAnimation(ruta+"AndarApuntando/","andarApuntando.obj", 0.7f);
        r->addAnimation(ruta+"Andar/","andar.obj", 0.3f);
        r->addAnimation(ruta+"CorrerApuntando/","CorrerApuntando.obj", 0.3f);
        //r->addAnimation(ruta+"LanzarGranada/","lanzarGranada.obj", 0.7f);
        
        char* text = (char*)(ruta+"Player"+to_string(estado->character)+"_Diffuse.png").c_str();
        setTexture(text);
        
    
    
	
	input = InputManager::Instance();
    vida = 100;
    t.start(); t2.start();
	vent = ventana::Instance();
}

void Player::inicializar(int ID, int numL){
	numLlaves = numL;
	llaves = new int[numLlaves];
	m_ID = ID; activa = 0;
	for(size_t a=0;a<numLlaves;a++)
		llaves[a]=-1;
	
//	dvector3D m = *getRotation();
//	m.z = -m.z;
//	setRotation(m);
    
    // HUD
    /*
    hud.getVida(vida);
    hud.getCarga(arma->getCarga());
    hud.getMunicion(arma->getMunicion());
     */
    estado->datos.vida = vida;
    estado->datos.carga = arma->getCarga();
    estado->datos.municion = arma->getMunicion();
    estado->datos.update = true;
    m_rot.x+=90;
    m_rot.z = 0;
}

Player::~Player(){
    if(llaves)
        delete[] llaves;
}

void Player::update(){
	
    //hud.getVida(vida); // HUD
//    hud.getllaves(*llaves);
    
    estado->datos.vida = vida;
    estado->datos.update = true;
    
    isDead();
    dvector3D vel = dvector3D(0,0,0);
    
    if(input->isPressed(SKY_KEY_W))
        vel.y += VELOCIDADN;
    if(input->isPressed(SKY_KEY_S))
        vel.y += -VELOCIDADN;
    if(input->isPressed(SKY_KEY_A))
        vel.x += -VELOCIDADN;
    if(input->isPressed(SKY_KEY_D))
        vel.x += VELOCIDADN;
    
    
    if(vel.x != 0 || vel.y != 0){
        prior = ANDANDO;
        action = true;
    }else{
        prior = QUIETO;
        action = false;
    }
    if(input->isPressed(SKY_MOUSE_BUTTON_LEFT)){
        atacar();
        // HUD
        //hud.getCarga(arma->getCarga());
        //hud.getMunicion(arma->getMunicion());
        estado->datos.carga = arma->getCarga();
        estado->datos.municion = arma->getMunicion();
        estado->datos.update = true;
        
        action = true;
        if(arma->getArmaActual() != tPALA
           || arma->getArmaActual() != tMARTILLO)
            prior = ATACANDO;
        else
            prior = DISTANCIA;
    }
    if(t.tTranscurrido(0.5f)){
        if(input->isPressed(SKY_KEY_TAB)){
            cambiarArma();
            t.reset();
        }
        if(input->isPressed(SKY_KEY_Q)){
            changeActiveKey();
            t.reset();
        }
        if(input->isPressed(SKY_KEY_E)){
            accionar();
            t.reset();
            
        }
    }
    if(input->isPressed(SKY_KEY_SPACE))
        vel*=2;
    
    
    mover(vel);
    
    object_colision_update();
    
    
	
//    m_rot = ventana::Instance()->posicionRaton(m_pos);
	dvector3D m, v;
 	m = input->mousePos;
	m = m.normalize();
	m.invertir();
    rotarAraton(m);
    PhysicObject::update();
    arma->update();
    Animaciones();
}

bool Player::isDead(){
    if(vida <= 0){
        estado->nextState = MENU;
        estado->menu = tmMENUPRINCIPAL;
        estado->destruir = true;
        return true;
    }
    return false;
}


void Player::Animaciones(){
    class render * ren = static_cast<class render*>(componentes.find(RENDER)->second);
    switch(prior){
        case QUIETO:
            ren->changeAnimation("reposo");
            break;
        case ANDANDO:
            ren->changeAnimation("andar");
            break;
        case ATACANDO:
            ren->changeAnimation("golpear");
            break;
        case DISTANCIA:
            ren->changeAnimation("andarApuntando");
            break;
    }
}

void Player::object_colision_update(){
    if(obj_colisionado!=nullptr){
        float dist = EasyMath::EucCalcularDistancia(*obj_colisionado->getPosition(), *getPosition());
        
        if(dist>4.f)
            obj_colisionado = nullptr;
        else if(obj_colisionado->getObjectType()==ENEMIGOS
                && t2.tTranscurrido(0.5)){
            vida-=5;t2.reset();
        }
    }
}

void Player::render(float &interpolation){
    PhysicObject::render(interpolation);
    arma->render(interpolation);
}

void Player::atacar(){
    
    if(arma->getArmaActual() == tPALA)
        cuerpoacuerpo();
    else
        arma->shoot();
}

void Player::cambiarArma(){
    arma->changeGun();
    // HUD
    /*
    hud.mostrarArma(arma->getArmaActual());
    hud.getCarga(arma->getCarga());
    hud.getMunicion(arma->getMunicion());
     */
    estado->datos.arma = arma->getArmaActual();
    estado->datos.carga = arma->getCarga();
    estado->datos.municion = arma->getMunicion();
    estado->datos.update = true;
    
    //std::cout << arma->getArmaActual() << std::endl;
}

void Player::changeActiveKey(){
    activa++;
    if(activa==numLlaves) activa = 0;
    std::cout << "LLAVE :" << activa << "| VALOR:"<< llaves[activa] << std::endl;
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

void Player::asignarLLave(int value){
    for (size_t a=0; a<numLlaves; a++) {
        if(llaves[a]==-1) {
            llaves[a]=value;
            break;
        }
    }
}

void Player::contacto(PhysicObject * g){
    if(g != nullptr){
        /*if(g->getObjectType() == PALA){
            arma->insertarArma(9);
        }*/
		//if(g->getObjectType() == ENEMIGOS)
			
		
        if(g->getObjectType() == MONEDAS){
            habilidadEspecial * h = static_cast<habilidadEspecial*>(componentes.find(HABESPECIAL)->second);
            h->aumentarMoneda();
            // HUD
            //hud.getMonedas(h->getActual());
            estado->datos.monedas = h->getActual();
            estado->datos.update = true;
        }
        else if(g->getObjectType() == PIEDRA ||
           (g->getObjectType() > REHEN && g->getObjectType() < ARBUSTOS) || g->getObjectType() == PALA)
            arma->insertarArma((int)g->getObjectType());
        
        else if(g->getObjectType() == LLAVE){
            asignarLLave(static_cast<PlayerObjects*>(g)->Llave());
            estado->datos.llaves = numLlaves;
            estado->datos.update = true;
            
        }
        
        
    }
    obj_colisionado = g;
}

void Player::addArma(){
    
    class render* go = static_cast<class render*>(componentes.find(RENDER)->second);
    if(go != NULL)
        go->anyadirArma();
}



void Player::accionar(){
    
    if(obj_colisionado != nullptr){
        if(obj_colisionado->getObjectType() == ALARMA && arma->getArmaActual() == tPALA){
            static_cast<Alarm*>(obj_colisionado)->romper();
        }
        else if(obj_colisionado->getObjectType() == FUENTE && arma->getArmaActual() == tPALA){
            static_cast<Fuente*>(obj_colisionado)->romper();
        }
        else if(obj_colisionado->getObjectType() == PUERTA){
            Puerta * puerta = static_cast<Puerta*>(obj_colisionado);
            if(puerta->abrir(llaves[activa])){
                if(puerta->getPuerta() == pdestructiva) vida -= 10;
            }
            
        }
        return;
    }
    printf("NO HAY OBJECTOS DE INTERACT \n");
    
}

void Player::cuerpoacuerpo(){
    //TO DO: revisar
    /*
    if(obj_colisionado != NULL){
        if(*obj_colisionado->getObjectType() == tALARMA){
            if(*(arma->getArmaActual()->getType()) == tPALAc){
                static_cast<alarma*>(obj_colisionado)->muere();
                obj_colisionado = NULL;
            }
        }else if(*obj_colisionado->getObjectType() == tFUENTE){
            if(*(arma->getArmaActual()->getType()) == tPALAc){
                static_cast<fuente*>(obj_colisionado)->muere();
                obj_colisionado = NULL;
            }
        }
    }
    */
}
