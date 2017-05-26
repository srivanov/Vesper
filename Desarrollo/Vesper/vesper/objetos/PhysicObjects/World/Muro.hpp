//
//  Muro.hpp
//  Arquitectura
//
//  Created by Gaspar Rodriguez Valero on 18/3/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#ifndef Muro_hpp
#define Muro_hpp

#include "../PhysicObject.hpp"

class Muro : public PhysicObject {
public:
    Muro(){}
    ~Muro(){}
    void update(){}
    void contacto(PhysicObject*){}
    void contactoEnd(PhysicObject*){}
    void construirMuros(int * tilemap,std::vector<dvector2D> &v, std::vector<dvector2D> &p, int ancho, int alto,int anchoMapa,int altoMapa);
};

#endif /* Muro_hpp */
