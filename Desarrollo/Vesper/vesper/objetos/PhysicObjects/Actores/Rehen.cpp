//
//  Rehen.cpp
//  Arquitectura
//
//  Created by Gaspar Rodriguez Valero on 16/3/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#include "Rehen.hpp"
#include "../../../Arquitectura IA/gestor_eventos.hpp"

Rehen::Rehen(){
	
    std::string ruta = "3d/";
    
    ruta += "Player3/";
    
    class render * r = static_cast<class render*>(componentes.find(RENDER)->second);
    r->AnimateNode(true);
    
    r->addAnimation(ruta+"Reposo/","reposo.obj", 0.5f);
    //r->addAnimation(ruta+"Correr/","correr.obj", 0.5f);
    r->addAnimation(ruta+"Andar/","andar.obj", 1.f);
    
    char* text = (char*)(ruta+"Player3_Diffuse.png").c_str();
    setTexture(text);

    m_rot.x+=90;
    
    m_brain = new RehenIA(getPosition());
    gestor_eventos::instance()->subscribirse(this);
}

Rehen::~Rehen(){delete m_brain;}

void Rehen::contacto(PhysicObject * g){
    if (g && g->getObjectType()==PLAYER) {
        if(!m_brain->inicializado()){
            m_brain->inicializar(g->getPosition(),*getPosition());
        }
        
        m_brain->changeState(SIGUIENDO);
    }
}
void Rehen::setSalida(dvector3D *salida){
    m_brain->setSalida(salida);
}
void Rehen::update(){
    
    m_brain->update();
    dvector3D mov = m_brain->Vmover();
    if(mov.x!=0 && mov.y!=0){
        lastM = mov;
        Animaciones(andar);
    }else{
        Animaciones(reposo);
    }
    dvector3D rot = *getPosition() + lastM;
    mover(mov);
    rotarAposicion(rot);
    PhysicObject::update();
    
}

void Rehen::Animaciones(Anims e){
    class render * r = static_cast<class render*>(componentes.find(RENDER)->second);
    switch (e) {
        case reposo:r->changeAnimation("reposo");break;
        case andar:r->changeAnimation("andar");break;
        default:
            break;
    }
}

void Rehen::asustado(){m_brain->changeState(ASUSTADO);}

void Rehen::contactoEnd(PhysicObject*){

}
