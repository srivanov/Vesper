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

#define VELOCIDADN 2.f




Player::Player() : obj_colisionado(nullptr){
    
    arma = new armas;
    componentes.insert(std::pair<ComponentType, component*>(ARMAS,arma));
    arma->setFather(this);
    component * componente = new habilidadEspecial();
	((habilidadEspecial*)componente)->setTipo(tHabINVISIBLE);
    componentes.insert(std::pair<ComponentType, component*>(HABESPECIAL,componente));
    componente->setFather(this);
    
    char buffer[2], ruta[50] = "";
    estado = states::Instance();
    if(estado->character > 0 && estado->character <= 3) {
        sprintf(buffer, "%d", estado->character);
        
        strcat(ruta, "3d/player");
        strcat(ruta, buffer);
        strcat(ruta, ".obj");
    } else {
        strcat(ruta, "3d/player1.obj");
    }
    addNodo(ruta);
    
    setTexture("3d/naranja.jpg");
	
	input = MyEventReceiver::Instance();
    vida = 100;
	hud.init();
    t.start();t2.start();
}

void Player::inicializar(int ID, int numL){
	numLlaves = numL;
	llaves = new int[numLlaves];
	m_ID = ID; activa = 0;
	for(size_t a=0;a<numLlaves;a++)
		llaves[a]=-1;
    
    hud.getVida(vida);
    hud.getCarga(arma->getCarga());
    hud.getMunicion(arma->getMunicion());
}

Player::~Player(){
    if(llaves)
        delete[] llaves;
}

void Player::update(){
    
    if(vida <= 0){
		estado->nextState = MENU;
		estado->menu = tmMENUPRINCIPAL;
		estado->destruir = true;
    }
	
    hud.getVida(vida);
//    hud.getllaves(*llaves);
    
	dvector3D vel;
    /*
    Keys aux;
    for(aux=SKY_MOUSE_BUTTON_1;aux<SKY_KEY_RIGHT_CONTROL;aux++){
        
    }
     */
	
    if(obj_colisionado!=nullptr){
        float dist = EasyMath::EucCalcularDistancia(*obj_colisionado->getPosition(), *getPosition());
        if(dist>4.f)
            obj_colisionado = nullptr;
        else{
            if(obj_colisionado->getObjectType()==ENEMIGOS && t2.tTranscurrido(0.5)){
                vida-=5;t2.reset();
            }
        }
    }
    if(input->IsKeyDown(SKY_KEY_W))
		vel.y += VELOCIDADN;
    if(input->IsKeyDown(SKY_KEY_S))
		vel.y += -VELOCIDADN;
    if(input->IsKeyDown(SKY_KEY_A))
		vel.x += -VELOCIDADN;
	if(input->IsKeyDown(SKY_KEY_D))
		vel.x += VELOCIDADN;
	
    if(input->getLeftClick()){
        atacar();
    	hud.getCarga(arma->getCarga());
    	hud.getMunicion(arma->getMunicion());
    }
    if(arma->getArmaActual()==tPALA)
        printf("PALA \n");
	if(t.tTranscurrido(0.5f)){
		if(input->IsKeyDown(SKY_KEY_TAB)){
		   	cambiarArma();
			t.reset();
		}
		if(input->IsKeyDown(SKY_KEY_Q)){
			changeActiveKey();
			t.reset();
		}
        if(input->IsKeyDown(SKY_KEY_E)){
            accionar();
            t.reset();
        }
	}
    if(input->IsKeyDown(SKY_KEY_SPACE))
        vel*=2;
	
	mover(vel);
	
    m_rot = ventana::Instance()->posicionRaton(m_pos);
    rotarConRaton(m_rot);
    GameObject::update();
    arma->update();

}

void Player::render(){
    PhysicObject::render();
    arma->render();
	hud.beginRender();
	hud.render();
	hud.endRender();
}

void Player::atacar(){
    
    if(arma->getArmaActual() == tPALA)
        cuerpoacuerpo();
    else
        arma->shoot();
}

void Player::cambiarArma(){
    arma->changeGun();
    hud.mostrarArma(arma->getArmaActual());
    hud.getCarga(arma->getCarga());
    hud.getMunicion(arma->getMunicion());
    std::cout << arma->getArmaActual() << std::endl;
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
        if(g->getObjectType() == PALA){
            arma->insertarArma(9);
        }
		//if(g->getObjectType() == ENEMIGOS)
			
		
        if(g->getObjectType() == MONEDAS){
            habilidadEspecial * h = static_cast<habilidadEspecial*>(componentes.find(HABESPECIAL)->second);
            h->aumentarMoneda();
            hud.getMonedas(h->getActual());
        }
        if(g->getObjectType() == PIEDRA ||
           (g->getObjectType() > REHEN && g->getObjectType() < ARBUSTOS))
            arma->insertarArma((int)g->getObjectType());
        
        if(g->getObjectType() == LLAVE)
            asignarLLave(static_cast<PlayerObjects*>(g)->Llave());
            
        
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
