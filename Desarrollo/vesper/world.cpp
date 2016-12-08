//
//  world.cpp
//  vesper
//
//  Created by Gaspar Rodriguez Valero on 8/12/16.
//  Copyright © 2016 Skyscrapers. All rights reserved.
//

#include "world.hpp"

void world::anyadirBotiquin(){
    botiquin * obj_hijo = new botiquin;
    objetos_mundo.push_back(obj_hijo);
}
void world::anyadirFuente(){
    fuente * obj_hijo = new fuente;
    objetos_mundo.push_back(obj_hijo);
}
void world::anyadirComida(){
    comida * obj_hijo = new comida;
    objetos_mundo.push_back(obj_hijo);
}
