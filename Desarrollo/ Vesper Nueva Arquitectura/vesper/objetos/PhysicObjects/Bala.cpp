//
//  Bala.cpp
//  Arquitectura
//
//  Created by Gaspar Rodriguez Valero on 16/3/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#include "Bala.hpp"

Bala::Bala(dvector3D &pos, dvector3D &dir, float vel){
    velocidad = vel;
    
    direccion.x = dir.x * velocidad;
    direccion.y = dir.y * velocidad;
    direccion.z = 0;
    temp.start();
    tiempo_vida = 1.0f;
}

Bala::~Bala(){
    
}

void Bala::update(){
    PhysicObject::update();
    
    if(temp.tTranscurrido(tiempo_vida) && eliminar == false)
        eliminar = true;
    else
        mover(direccion);

}

void Bala::contacto(PhysicObject *g){
    if(g != NULL){
        eliminar = true;
    }
    
}
