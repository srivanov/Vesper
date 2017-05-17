//
//  Decoracion.cpp
//  vesper
//
//  Created by Gaspar Rodriguez Valero on 17/5/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Decoracion.hpp"

void Decoracion::inicializar(int &ID, ObjectType type){
    class render * r = static_cast<class render*>(componentes.find(RENDER)->second);
    
    switch (type) {
        case ABETO:
            addNodo("3d/abeto.obj");
            setTexture("3d/abeto_diffuse.png");
            createPhysicsBody(STATIC_BODY,dvector3D(1.7,1.2,0));
            break;
        case ARBOL:
            addNodo("3d/arbol.obj");
            setTexture("3d/arbol_diffuse.png");
            createPhysicsBody(STATIC_BODY);
            break;
        case BARRIL:
            addNodo("3d/barril.obj");
            setTexture("3d/barril_diffuse.png");
            createPhysicsBody(STATIC_BODY);
            break;
        case PALE:
            addNodo("3d/pale.obj");
            setTexture("3d/pale_diffuse.png");
            createPhysicsBody(STATIC_BODY,dvector3D(2,1,0));
            break;
        case PAPELERA:
            addNodo("3d/papelera.obj");
            setTexture("3d/papelera_diffuse.png");
            createPhysicsBody(STATIC_BODY);
            break;
        case PARQUE:
            addNodo("3d/abeto.obj");
            setTexture("3d/abeto_diffuse.png");
            createPhysicsBody(STATIC_BODY);
            break;
        case VALLA_METALICA:
            addNodo("3d/valla_hierro.obj");
            setTexture("3d/valla_hierro_diffuse.png");
            createPhysicsBody(STATIC_BODY,dvector3D(2,0.01,0));
            break;
        case VALLA_MADERA:
            addNodo("3d/valla_madera.obj");
            setTexture("3d/valla_madera_diffuse.png");
            createPhysicsBody(STATIC_BODY,dvector3D(1,0.2,0));
            break;
        default:break;
    }
    
    
}
