//
//  Decoracion.cpp
//  vesper
//
//  Created by Gaspar Rodriguez Valero on 17/5/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Decoracion.hpp"

void Decoracion::inicializar(int &ID, ObjectType type){
    switch (type) {
        case ABETO:
            setTexture("");
            addNodo("");
            break;
        case ARBOL:
            setTexture("");
            addNodo("");
            break;
        case BARRIL:
            setTexture("");
            addNodo("");
            break;
        case PALE:
            setTexture("");
            addNodo("");
            break;
        case PAPELERA:
            setTexture("");
            addNodo("");
            break;
        case PARQUE:
            setTexture("");
            addNodo("");
            break;
        case VALLA_METALICA:
            setTexture("");
            addNodo("");
            break;
        case VALLA_MADERA:
            setTexture("");
            addNodo("");
            break;
        default:break;
    }
    if(type!=PARQUE)
        createPhysicsBody(STATIC_BODY);
}
