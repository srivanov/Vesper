//
//  Enemy.hpp
//  Arquitectura
//
//  Created by Gaspar Rodriguez Valero on 16/3/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#ifndef Enemy_hpp
#define Enemy_hpp

#include "../PhysicObject.hpp"
#include <vector>
#include "../../../Arquitectura IA/LevelBlackBoard.hpp"
#include "../../../Arquitectura IA/gestor_eventos.hpp"
#include "../../../Arquitectura IA/ObjectsMemory.hpp"
#include "../../../Sistema de Decision/Behaviour_tree2.hpp"

class Bala;

struct patrulla {
    dvector3D * getNextPosPatrulla();
    patrulla(){}
    ~patrulla(){}
    void addPosPatrulla(dvector3D * pos);
private:
    vector<dvector3D*> posiciones;
    size_t posicion_actual;
};

enum EEnemyAnimations {
    REPOSO = 0,
    ANDAR,
    COMER,
    REP_DISP,
    ZARPAZO,
    MUERTE
};



class Enemy : public PhysicObject {
protected:
    NpcBook * book;
    Nodo_base * Arbol;
    MemoryObjects * memory;
    patrulla * patrullar;
    dvector3D * posP;
    dvector3D lastView;
    void comprobar_vision();
    void updateStats();
    void STD();
    void NextAnimation(EEnemyAnimations e);
private:
    dvector3D direccion;
    tiempo t;
    bool dead;
public:
    Enemy();
    ~Enemy();
    bool activarAlarma() {return book->ACTalarma;}
    dvector3D* getDireccion();
    void update();
    void inicializar(int& ID , bool pat = false, vector<dvector3D*> pos = vector<dvector3D*>());
    void contacto(PhysicObject *g);
    void contactoEnd(PhysicObject *g){}
};

#endif /* Enemy_hpp */
