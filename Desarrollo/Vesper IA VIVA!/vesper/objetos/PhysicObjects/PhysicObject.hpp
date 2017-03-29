//
//  PhysicObject.hpp
//  Arquitectura
//
//  Created by Gaspar Rodriguez Valero on 16/3/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#ifndef PhysicObject_hpp
#define PhysicObject_hpp

#include "../GameObject.hpp"
#include "../../tiempo.h"

enum BodyObject {
    STATIC_BODY = 0,
    DYNAMIC_BODY
};

class PhysicObject : public GameObject {
protected:
    dvector3D anguloDisparo;
public:
    void rotarConRaton(dvector3D &posRaton);
    void mover(dvector3D &vel);
    void setDirDisparo(dvector3D &dir);
    dvector3D * getDirDisparo() {return &anguloDisparo;}
    void setPosition(dvector3D&);
    void setRotation(dvector3D &);
    virtual void contacto(PhysicObject*){}
    virtual void contactoEnd(PhysicObject*){}
    void createPhysicsBody(const BodyObject,dvector3D dim = dvector3D(1,1,1));
    
    PhysicObject();
    ~PhysicObject();
};

#endif /* PhysicObject_hpp */
