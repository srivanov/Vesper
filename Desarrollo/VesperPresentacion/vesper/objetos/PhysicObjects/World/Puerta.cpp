//
//  Puerta.cpp
//  Arquitectura
//
//  Created by Gaspar Rodriguez Valero on 16/3/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#include "Puerta.hpp"
#include "../Actores/Player.hpp"

Puerta::Puerta(){
    
    addNodo("3d/door.obj");
    setTexture("3d/Door_Diffuse.png");
	key = 1;
    abierta = false;
}

void Puerta::inicializar(int id, const tipoPuerta p){
    pu = p;
    m_ID = id;
    /*
    std::string ruta = "3d/Puerta/";
    
    class render * r = static_cast<class render*>(componentes.find(RENDER)->second);
    r->AnimateNode(true);
    
    r->addAnimation(ruta+"Cerrada/","cerrada.obj", 99.f);
    r->addAnimation(ruta+"Abrir/","abrir.obj", 1.f);
    r->addAnimation(ruta+"abierta/","abierta.obj", 99.f);
    
    
    char* text = (char*)(ruta+"Door_Diffuse.png").c_str();
    setTexture(text);
    */
    dvector3D rotar = dvector3D(0,180,0);
    setRotation(rotar);
}

void Puerta::update(){
    /*
    if(abierta && t.tTranscurrido(1.f)){
        static_cast<class render*>(componentes.find(RENDER)->second)->changeAnimation("abierta");
        static_cast<physics*>(componentes.find(PHYSICS)->second)->DeleteBody();
    }*/
    PhysicObject::update();
}

void Puerta::activarAlarma(){
    gestor_eventos::instance()->addEvento(m_ID, P_ALERTA, getPosition());
    gestor_eventos::instance()->addEvento(m_ID, P_ALARMA, getPosition());
    //cout << "alarma activada" << endl;
}

void Puerta::contacto(PhysicObject *g){
    /*
    if(g && g->getObjectType()==PLAYER){
        if(static_cast<Player*>(g)->getActiveKey()==key){
            eliminar = true;
            if(pu==palarma) activarAlarma();
        }
    }
     */
}
bool Puerta::abrir(int llave){
    
    if(!abierta && llave==key){
        abierta = true;
        //static_cast<class render*>(componentes.find(RENDER)->second)->changeAnimation("abrir");
        eliminar = true;
        t.start();
    }
    return true;
}
