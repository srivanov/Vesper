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
            addNodo("3d/abeto.obj");
            setTexture("3d/abeto_diffuse.png");
            break;
        case BARRIL:
            addNodo("3d/abeto.obj");
            setTexture("3d/abeto_diffuse.png");
            break;
        case PALE:
            addNodo("3d/abeto.obj");
            setTexture("3d/abeto_diffuse.png");
            break;
        case PAPELERA:
            addNodo("3d/papelera.obj");
            setTexture("3d/papelera_diffuse.png");
            break;
        case PARQUE:
            addNodo("3d/abeto.obj");
            setTexture("3d/abeto_diffuse.png");
            break;
        case VALLA_METALICA:
            addNodo("3d/abeto.obj");
            setTexture("3d/abeto_diffuse.png");
            break;
        case VALLA_MADERA:
            addNodo("3d/abeto.obj");
            setTexture("3d/abeto_diffuse.png");
            break;
        default:break;
    }
    
    if(type!=PARQUE && type!=ABETO)
        createPhysicsBody(STATIC_BODY);
}
