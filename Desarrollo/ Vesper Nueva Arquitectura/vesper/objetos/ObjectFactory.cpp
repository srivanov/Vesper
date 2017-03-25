//
//  ObjectFactory.cpp
//  Arquitectura
//
//  Created by Gaspar Rodriguez Valero on 20/3/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#include "ObjectFactory.hpp"

void ObjectFactory::initObject(int ID, dvector3D posicion,ObjectType tipo,const BodyObject body){
    if(tipo!=ENEMIGOS)
        g->inicializar(ID);
    g->setObjectType(tipo);
    g->createPhysicsBody(body);
    g->setPosition(posicion);
    g->addNodo("");
    g->setTexture("3d/letraE.png");
}

PhysicObject * ObjectFactory::PObject(int ID, dvector3D posicion, ObjectType tipo){
    Clean();
    g = new PlayerObjects;
    initObject(ID,posicion,tipo,STATIC_BODY);
    
    return g;
}

void ObjectFactory::Clean(){if (g) g = nullptr;}

PhysicObject * ObjectFactory::Actores(int ID, dvector3D posicion, ObjectType tipo){
    Clean();
    if(tipo==REHEN)
        g = new Rehen;
    else if(tipo==ENEMIGOS){
        g = new Enemy;
        Enemy * e = static_cast<Enemy*>(g);
        e->inicializar(ID);
    }
    else{
        return nullptr;
    }
    initObject(ID,posicion,tipo,DYNAMIC_BODY);
    return g;
}

PhysicObject * ObjectFactory::WObject(int ID, dvector3D posicion, ObjectType tipo){
    Clean();
    if(tipo==FUENTE) g = new Fuente;
    else if(tipo==ALARMA) g = new Alarm;
    else if(tipo==COMIDA) g = new Comida;
    else if(tipo==BOTIQUIN) g = new Botiquin;
    else if(tipo==PUERTA) g = new Puerta;
    else{
        return nullptr;
    }
    initObject( ID, posicion, tipo,STATIC_BODY);
    return g;
}

ObjectFactory::ObjectFactory() : g(nullptr){}


/*

obj_mapping mapping[] = {
    
    {	1		,	""					,		0		},
    {	2		,	"3d/alarmita.jpg"	,	accion2		},
    {	3		,	"3d/moneda.jpg"		,	accion3		},
    {	4		,	"3d/texture.png"	,	accion4		},
    {	5		,	"3d/pala.jpg"		,	accion5		},
    {	6		,	"3d/piedra.jpg"		,	accion6		},
    {	7		,	"3d/naranja.jpg"	,	accion7		},
    {	8		,	"3d/llave.jpg"		,	accion8		},
    {	9		,	"3d/fuenten.jpg"	,	accion9		},
    {	10		,	"3d/botiquin.jpg"	,	accion10	},
    {	11		,	"3d/puerta.jpg"		,	accion11	},
    {	12		,	"3d/pizza.jpg"		,	accion12	},
    {	13		,	""					,		0		},
    {	14		,	"3d/rehen.jpg"		,	accion21	},
    {	15 		,	"3d/letraE.png"		,	accion15	},
    {	16 		,	"3d/letraL.png"		,	accion16	},
    {	17 		,	"3d/globoagua.png"	,	accion17	},
    {	18 		,	"3d/chicle.png"		,	accion18	},
    {	19 		,	"3d/bombahumo.png"	,	accion19	},
    {	20 		,	""                  ,       0       },
    {	0		,	""					,		0		}
*/
