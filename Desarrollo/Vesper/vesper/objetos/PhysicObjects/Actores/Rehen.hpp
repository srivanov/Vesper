//
//  Rehen.hpp
//  Arquitectura
//
//  Created by Gaspar Rodriguez Valero on 16/3/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#ifndef Rehen_hpp
#define Rehen_hpp

#include "../PhysicObject.hpp"
#include "../../../Arquitectura IA/RehenIA.hpp"

class Rehen : public PhysicObject {
    RehenIA * m_brain;
    dvector3D lastM;
public:
    void setSalida(dvector3D* salida);
    void asustado();
    void update();
    Rehen();
    ~Rehen();
    void contacto(PhysicObject *);
    void contactoEnd(PhysicObject*);
};

#endif /* Rehen_hpp */
