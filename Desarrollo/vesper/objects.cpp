//
//  objects.cpp
//  vesper
//
//  Created by Gaspar Rodriguez Valero on 8/12/16.
//  Copyright © 2016 Skyscrapers. All rights reserved.
//

#include "objects.hpp"

void botiquin::usar(){
    num_usos--;
    if(num_usos==0)
        gastado=!gastado;
}
botiquin::botiquin(){}
comida::comida(){}
fuente::fuente(){}
botiquin::~botiquin(){}
comida::~comida(){}
fuente::~fuente(){}
