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
#include "../../../estados/estados.h"

enum Action_Priority {
    QUIETO = 0,
    ANDANDO,
    ATACANDO,
    DISTANCIA
};

class Player : public PhysicObject {
//    std::map<const Keys,int> keyFunction;
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
	states* estado;
	tiempo t, t2;
	InputManager* input;
    Action_Priority prior;
	ventana* vent;
    bool action;
    void object_colision_update();
    bool isDead();
    void Animaciones();
public:
    void inicializar(int ID,int LLaves);
    unsigned int * getVel() {return &velocidad;}
    void setVelocidad(unsigned int vel);
    int getActiveKey(){return llaves[activa];}
    void activarHab();
    void accionar();
    bool habActiva();
    void contacto(PhysicObject*);
	void contactoEnd(PhysicObject*){ obj_colisionado = nullptr; }
    void update();
    void render(float &interpolation);
    void atacar();
    void cambiarArma();
    void cuerpoacuerpo();
    void addArma();
    
    Player();
    ~Player();
};

#endif /* Player_hpp */
