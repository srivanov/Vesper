//
//  NPC.cpp
//  vesper
//
//  Created by Gaspar Rodriguez Valero on 7/12/16.
//  Copyright © 2016 Skyscrapers. All rights reserved.
//

#include "NPC.hpp"

NPC::NPC(){
    DeciSys = new estados;
    datosPropios.inicializar();
}
NPC::~NPC(){
    
}
void NPC::update(BlackBoard * worldINFO){DeciSys->run(datosPropios,worldINFO);}
datos NPC::getNPCinfo(){return datosPropios;}
vector3D NPC::getPosition(){return datosPropios.getPosActual();}
