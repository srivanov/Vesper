//
//  Puerta.hpp
//  Arquitectura
//
//  Created by Gaspar Rodriguez Valero on 16/3/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#ifndef Puerta_hpp
#define Puerta_hpp

#include "../PhysicObject.hpp"

class Puerta : public PhysicObject {
    
    
public:
    Puerta(){addNodo("3d/muro.3ds");setTexture("3d/puerta.jpg");}
    ~Puerta(){}
    void contacto(PhysicObject *g){}
    void contactoEnd(PhysicObject *g){}
};

#endif /* Puerta_hpp */
