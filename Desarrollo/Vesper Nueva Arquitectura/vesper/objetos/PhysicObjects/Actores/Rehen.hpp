//
//  Rehen.hpp
//  Arquitectura
//
//  Created by Gaspar Rodriguez Valero on 16/3/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#ifndef Rehen_hpp
#define Rehen_hpp

#include "PhysicObject.hpp"

class Rehen : public PhysicObject {
    
public:
    Rehen(){addNodo("3d/player2.obj");
//        setTexture("3d/Player2_Diffuse.png");
    }
    ~Rehen(){}
    void contacto(PhysicObject *){}
    void contactoEnd(PhysicObject*){}
};

#endif /* Rehen_hpp */
