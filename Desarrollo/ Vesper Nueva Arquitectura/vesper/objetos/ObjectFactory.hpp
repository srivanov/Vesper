//
//  ObjectFactory.hpp
//  Arquitectura
//
//  Created by Gaspar Rodriguez Valero on 20/3/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#ifndef ObjectFactory_hpp
#define ObjectFactory_hpp

#include "Objects.hpp"
#include "../tinyxml2.h"

using namespace tinyxml2;



class ObjectFactory {
    void initObject(int ID, dvector3D posicion,ObjectType tipo,const BodyObject body);
    PhysicObject * g;
    void Clean();
public:
    ObjectFactory();
    ~ObjectFactory(){}
    PhysicObject * PObject(int ID, dvector3D posicion,ObjectType tipo);
    PhysicObject * WObject(int ID, dvector3D posicion,ObjectType tipo);
    PhysicObject * Actores(int ID, dvector3D posicion,ObjectType tipo);
};

#endif /* ObjectFactory_hpp */
