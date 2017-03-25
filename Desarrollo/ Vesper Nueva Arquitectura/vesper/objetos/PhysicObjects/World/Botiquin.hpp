//
//  Botiquin.hpp
//  Arquitectura
//
//  Created by Gaspar Rodriguez Valero on 16/3/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#ifndef Botiquin_hpp
#define Botiquin_hpp

#include "../PhysicObject.hpp"

class Botiquin : public PhysicObject {
    unsigned int usos;
    bool gastado;
public:
    Botiquin();
    ~Botiquin();
    void update();
    virtual void contacto(PhysicObject*){}
    virtual void contactoEnd(PhysicObject*){}
};


#endif /* Botiquin_hpp */
