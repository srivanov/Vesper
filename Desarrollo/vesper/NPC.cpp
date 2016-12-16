//
//  NPC.cpp
//  vesper
//
//  Created by Gaspar Rodriguez Valero on 7/12/16.
//  Copyright © 2016 Skyscrapers. All rights reserved.
//

#include "NPC.hpp"

NPC::NPC(int ntipo, vector3D * posinicial, short rutina){
    DeciSys = new estados;
    datosPropios = new datos(ntipo, posinicial,rutina);
}
NPC::~NPC(){
    delete datosPropios;
    delete DeciSys;
}
void NPC::update(BlackBoard * worldINFO){
    if(f%120==0){
        datosPropios->Alimentarse(-1);
        cout <<"VIDA:"<<datosPropios->getLife() << " | HAMBRE:" << datosPropios->getHambre() << " | SED:" << datosPropios->getSed() << endl;
    }
    if (f%240==0) {
        datosPropios->Beber(-1);
        
    }
    if (f%300==0) {
        datosPropios->Curarse(-1);
        f=0;
    }
    f++;
    DeciSys->run(datosPropios,worldINFO);
}
datos NPC::getNPCinfo(){return *datosPropios;}
vector3D * NPC::getPosition(){return datosPropios->getPosActual();}
void NPC::setPosition(vector3D * posicion){datosPropios->newPosition(posicion);}
