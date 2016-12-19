//
//  NPC.cpp
//  vesper
//
//  Created by Gaspar Rodriguez Valero on 7/12/16.
//  Copyright © 2016 Skyscrapers. All rights reserved.
//

#include "NPC.hpp"

#define BOLASdeFUEGO 1
#define LANZApinchos 2
#define ESCUPEacido 3
#define CUERPOaCUERPO 4

NPC::NPC(int ntipo, vector3D * posinicial, short rutina){
    DeciSys = new class estados;
    //datosPropios = new datos(ntipo, posinicial,rutina);
    life= 100;
    srand(static_cast<int>(time(NULL)));
    sed = rand() % 40;
    hambre = rand() % 40;
    tipo = ntipo;
    if (tipo<=ESCUPEacido) {
        velocidad = 1.f;
        if(tipo==BOLASdeFUEGO) velcorriendo = 1.5f;
        else if(tipo==LANZApinchos) velcorriendo = 1.2f;
        else velcorriendo = 1.7f;
    }else{
        velocidad = 0.8f;
        velcorriendo = 2.f;
    }
    posDestino = posActual = posinicial;
    // CODIGO PARA PRUEBAS DEL SISTEMA DE DECISION
    paso=0;
    if(rutinas==0)// PATRULLAR
    {
        PosRutina.push_back(new vector3D(20,10,0));
        PosRutina.push_back(new vector3D(30,10,0));
        PosRutina.push_back(new vector3D(30,30,0));
        PosRutina.push_back(new vector3D(10,30,0));
    }else{ //VIGILAR
        PosRutina.push_back(new vector3D(10,10,0));
    }
    //EPropios.resize(3);
}
NPC::~NPC(){
    //delete datosPropios;
    delete DeciSys;
}
bool NPC::getFlags(int event){
    for (size_t i=0; i<EPropios.size(); i++) {
        if (EPropios[i]!=NULL && EPropios[i]->type==event) return true;
    }
    return false;
}
void NPC::setEventFlag(vector3D posicion,Event_type Etype){
    bool existe = false;
    for (size_t i=0 ; i<EPropios.size(); i++) {
        if(EPropios[i]->type==Etype) existe=true;
    }
    if(!existe) {
        EPropios.push_back(new DT_evento(Etype,posicion));
    }
}
void NPC::update(BlackBoard * worldINFO){
    /*if(f%120==0){
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
    DeciSys->run(datosPropios,worldINFO);*/
    for (size_t i=0; i<EPropios.size(); i++) {
        if(EPropios[i]->type==tE_Sound && vector3D::CalcularDistancia(EPropios[i]->posEvent, *this->getPosition())<=10) {
            
            cout << "ESCUCHO A " << vector3D::CalcularDistancia(EPropios[i]->posEvent, *this->getPosition())<< endl;
        }
    }
    
}
//datos NPC::getNPCinfo(){return *datosPropios;}

void NPC::setPosition(vector3D * posicion){posActual=posicion;}
