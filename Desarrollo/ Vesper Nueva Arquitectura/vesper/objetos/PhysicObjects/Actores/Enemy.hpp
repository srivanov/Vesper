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
#include "../../../Sistema de Decision/Behaviour_tree2.hpp"

class Enemy : public PhysicObject {
protected:
     NpcBook * book;
     Nodo_base * Arbol;
private:
    float tiempo_vida, velocidad;
    dvector3D direccion;
    tiempo temp,t;
    
public:
    Enemy();
    ~Enemy();
    dvector3D* getDireccion();
    void update();
    void inicializar(int& ID);
    void contacto(PhysicObject *g);
    void contactoEnd(PhysicObject *g){}
};

#endif /* Enemy_hpp */
