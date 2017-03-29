//
//  Bala.cpp
//  Arquitectura
//
//  Created by Gaspar Rodriguez Valero on 16/3/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//
#include "../../Arquitectura IA/trigger_system.hpp"
#include "Bala.hpp"

Bala::Bala(dvector3D &pos, dvector3D &dir, float vel){
    velocidad = vel;
    
    
    
    createPhysicsBody(DYNAMIC_BODY,dvector3D(0.1,0.1,0));
    
    velocidad = vel;
    
    m_pos = pos + dir*1.5f;
    //pos.y += dir.y*1.5f;
    m_pos.z = 0;
    
    setPosition(m_pos);
    
    direccion.x = dir.x * velocidad;
    direccion.y = dir.y * velocidad;
    //direccion.z = 0;
    
    temp.start();
    tiempo_vida = 1.0f;
    
    //trigger_system::instance()->add_trigger(P_RUIDO, m_ID,m_pos, 20, 1);
    
}

Bala::~Bala(){
    class render * r = static_cast<class render*>(componentes.find(RENDER)->second);
    if(r)
        r->deleteNode();
}

void Bala::update(){
    
    //std::cout << "POS: X " << m_pos.x << " Y " << m_pos.y << std::endl;
    PhysicObject::update();
    
    if(temp.tTranscurrido(tiempo_vida) && eliminar == false)
        eliminar = true;
    else
        mover(direccion);

}

void Bala::contacto(PhysicObject *g){
    eliminar = true;
}
