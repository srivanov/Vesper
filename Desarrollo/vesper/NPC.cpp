//
//  NPC.cpp
//  vesper
//
//  Created by Gaspar Rodriguez Valero on 7/12/16.
//  Copyright © 2016 Skyscrapers. All rights reserved.
//

#include "NPC.hpp"

NPC::NPC(int ntipo, vector3D * posinicial){
    DeciSys = new estados;
    datosPropios = new datos(ntipo, posinicial);
}
NPC::~NPC(){
    delete datosPropios;
    delete DeciSys;
}
void NPC::update(BlackBoard * worldINFO){
    cout << datosPropios->getPosActual()->x << "|" << datosPropios->getPosActual()->y << endl;
    cout << worldINFO->Botiquines[0]->x << endl;
    DeciSys->run(datosPropios,worldINFO);
}
datos NPC::getNPCinfo(){return *datosPropios;}
vector3D * NPC::getPosition(){return datosPropios->getPosActual();}
void NPC::setPosition(vector3D * posicion){datosPropios->newPosition(posicion);}
