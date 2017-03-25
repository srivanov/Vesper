//
//  Weapon.hpp
//  Arquitectura
//
//  Created by Gaspar Rodriguez Valero on 16/3/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#ifndef PlayerObjects_hpp
#define PlayerObjects_hpp

#include "PhysicObject.hpp"

class PlayerObjects : public PhysicObject {
public:
    PlayerObjects();
    ~PlayerObjects();
    void contacto(PhysicObject *);
    void contactoEnd(PhysicObject *);
};

#endif /* Weapon_hpp */
