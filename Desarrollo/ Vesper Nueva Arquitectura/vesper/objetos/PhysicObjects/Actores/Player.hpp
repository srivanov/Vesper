//
//  Player.hpp
//  Arquitectura
//
//  Created by Gaspar Rodriguez Valero on 16/3/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include "../PhysicObject.hpp"
#include "../../../components/armas.hpp"
#include "../../../components/gun.hpp"
#include <buttons.hpp>

class Player : public PhysicObject {
protected:
    //armas* arma;
    unsigned int velocidad;
    GameObject* obj_colisionado;
    armas * arma;
    dvector3D anguloDisparo;
public:
    unsigned int * getVel() {return &velocidad;}
    void setVelocidad(unsigned int vel);
    
    void activarHab();
    void accionar();
    bool habActiva();
    void contacto(PhysicObject*);
    void contactoEnd(PhysicObject*){}
    void update();
    void render();
    void atacar();
    void cambiarArma();
    void cuerpoacuerpo();
    void addArma();
    Player();
    ~Player();
};

#endif /* Player_hpp */
