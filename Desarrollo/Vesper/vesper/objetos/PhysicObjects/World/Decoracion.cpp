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
        case ARBUSTOS:
            setTexture("");
            addNodo("");
            break;
            
        default:break;
    }
    createPhysicsBody(STATIC_BODY);
}
