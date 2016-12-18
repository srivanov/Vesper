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
botiquin::botiquin(vector3D * posInicial){posicion = posInicial;}
comida::comida(vector3D * posInicial){posicion = posInicial;}
fuente::fuente(vector3D * posInicial, bool Ninfinita){posicion = posInicial;infinita=posInicial;}
void fuente::Comprobacion(){if (destruida && !NPCrota) {NPCrota = true;}}
void alarma::Comprobacion(){if (rota && !NPCrota) {NPCrota = true;}}
botiquin::~botiquin(){}
comida::~comida(){}
fuente::~fuente(){}
alarma::alarma(vector3D * posInicial){posicion = posInicial;}
alarma::~alarma(){}
