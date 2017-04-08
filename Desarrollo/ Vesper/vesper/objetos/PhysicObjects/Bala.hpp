//
//  Bala.hpp
//  Arquitectura
//
//  Created by Gaspar Rodriguez Valero on 16/3/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#ifndef Bala_hpp
#define Bala_hpp

#include "PhysicObject.hpp"
#include <iostream>

class Bala : public PhysicObject {
    float velocidad, tiempo_vida;
    dvector3D direccion;
    tiempo temp;
public:
    void update();
    dvector3D& getDireccion() {return direccion;}
    void contacto(PhysicObject* g);
    void contactoEnd(PhysicObject* g){}
    Bala(dvector3D &pos, dvector3D &dir, float vel, float tVida);
    ~Bala();
};

#endif /* Bala_hpp */
