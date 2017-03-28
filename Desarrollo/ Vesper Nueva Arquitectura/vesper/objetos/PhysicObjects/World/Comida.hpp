//
//  Comida.hpp
//  Arquitectura
//
//  Created by Gaspar Rodriguez Valero on 16/3/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#ifndef Comida_hpp
#define Comida_hpp

#include "../PhysicObject.hpp"
#include "../../../Arquitectura IA/LevelBlackBoard.hpp"

class Comida : public PhysicObject {
    void gestorTiempo();
    bool consumido;
    tiempo time;
public:
    Comida();
    ~Comida();
    void update();
    virtual void contacto(PhysicObject*){}
    virtual void contactoEnd(PhysicObject*){}
};

#endif /* Comida_hpp */
