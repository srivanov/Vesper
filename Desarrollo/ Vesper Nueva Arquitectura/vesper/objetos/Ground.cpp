//
//  ground.cpp
//  vesper
//
//  Created by Gaspar Rodriguez Valero on 23/3/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Ground.hpp"

void Ground::inicializar(float alto, float ancho){
    class render * r = static_cast<class render*>(componentes.find(RENDER)->second);
    r->CreateGround(alto, ancho);
}
