//
//  Fuente.hpp
//  Arquitectura
//
//  Created by Gaspar Rodriguez Valero on 16/3/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#ifndef Fuente_hpp
#define Fuente_hpp

#include "../PhysicObject.hpp"
#include "../../../Arquitectura IA/LevelBlackBoard.hpp"

class Fuente : public PhysicObject {
private:
    bool rota, NPCKnows;
public:
    Fuente();
    ~Fuente();
    void update();
    virtual void contacto(PhysicObject*){}
    virtual void contactoEnd(PhysicObject*){}
};

#endif /* Fuente_hpp */
