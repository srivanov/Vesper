//
//  ObjectFactory.cpp
//  Arquitectura
//
//  Created by Gaspar Rodriguez Valero on 20/3/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#include "ObjectFactory.hpp"

void ObjectFactory::initEnemy(int ID, dvector3D posicion,ObjectType tipo,const BodyObject body){
	g = new Enemy;
	Enemy * e = static_cast<Enemy*>(g);
	e->setObjectType(tipo);
	e->setPosition(posicion);
	e->createPhysicsBody(DYNAMIC_BODY);
	e->attachSensor(3.0f);
	e->inicializar(ID);
}

void ObjectFactory::initObject(int ID, dvector3D posicion,ObjectType tipo,const BodyObject body){
    g->setObjectType(tipo);
	g->setPosition(posicion);
	g->createPhysicsBody(body);
    g->inicializar(ID);
}

void ObjectFactory::initRehen(int ID, dvector3D posicion, ObjectType tipo, const BodyObject body){
    g = new Rehen;
    Rehen * e = static_cast<Rehen*>(g);
    e->setObjectType(tipo);
    e->setPosition(posicion);
    e->createPhysicsBody(DYNAMIC_BODY);
    e->attachSensor(6.0f);
    e->inicializar(ID);
}

PhysicObject * ObjectFactory::PObject( dvector3D posicion, ObjectType tipo){
    Clean();
    g = new PlayerObjects;
    initObject(0,posicion,tipo,STATIC_BODY);
    PlayerObjects * gg = static_cast<PlayerObjects*>(g);
    if(tipo==LLAVE){
        gg->inicializar(Valor_llaves);
        Valor_llaves--;
    }else
        gg->inicializar(0);
    return g;
}

void ObjectFactory::Clean(){if (g) g = nullptr;}

PhysicObject * ObjectFactory::Actores(int ID, dvector3D posicion, ObjectType tipo){
    Clean();
    if(tipo==REHEN)
        initRehen(ID, posicion, tipo, DYNAMIC_BODY);
	else if(tipo==ENEMIGOS)
		initEnemy(ID, posicion, tipo, DYNAMIC_BODY);
	else
        return nullptr;
    
    return g;
}

PhysicObject * ObjectFactory::Escape(int ID, dvector3D posicion, ObjectType tipo){
	Clean();
	if(tipo==SALIDA)
		g = new Salida;
	else{
		return nullptr;
	}
	initObject(ID,posicion,tipo,STATIC_BODY);
	return g;
}

PhysicObject * ObjectFactory::WObject(int ID, dvector3D posicion, ObjectType tipo){
    Clean();
    if(tipo==FUENTE) g = new Fuente;
    else if(tipo==ALARMA) g = new Alarm;
    else if(tipo==COMIDA) g = new Comida;
    else if(tipo==BOTIQUIN) g = new Botiquin;
    else if(tipo==PUERTA) {
        g = new Puerta;
        Puerta * gg = static_cast<Puerta*>(g);
        gg->inicializar(ID, palarma);
        gg->setKey(puerta);
    }
    else{
        return nullptr;
    }
    initObject( ID, posicion, tipo,STATIC_BODY);
    return g;
}

PhysicObject * ObjectFactory::Decora(int ID, dvector3D posicion, ObjectType tipo){
    g = new Decoracion;
    g->setPosition(posicion);
    Decoracion * d = static_cast<Decoracion*>(g);
    d->inicializar(ID, tipo);
    return g;
}


ObjectFactory::ObjectFactory() : g(nullptr){Valor_llaves=puerta=0;}

