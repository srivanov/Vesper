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
private:
    std::map<const Keys,int> keyFunction;
protected:
    void asignarLLave(int value);
    unsigned int velocidad;
    GameObject* obj_colisionado;
    armas * arma;
    dvector3D anguloDisparo;
    int * llaves;
    size_t numLlaves,activa;
    void changeActiveKey();
    int vida;
public:
    void inicializar(int ID,int LLaves);
    unsigned int * getVel() {return &velocidad;}
    void setVelocidad(unsigned int vel);
    int getActiveKey(){return llaves[activa];}
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
