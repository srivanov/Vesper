//
//  BlackBoard.cpp
//  vesper
//
//  Created by Gaspar Rodriguez Valero on 1/12/16.
//  Copyright © 2016 Skyscrapers. All rights reserved.
//

#include "BlackBoard.hpp"

BlackBoard::BlackBoard(){posicion = new vector3D{-1,-1,-1};}
BlackBoard::~BlackBoard(){}
void BlackBoard::cleanBool(){
    comprobadaAlarma = false;
    comprobadaFuente = false;
    estadoAlarma = false;
    estadofuente = false;
}
void BlackBoard::vaciarVectores(){
    posicionesNPC.clear();
    Botiquines.clear();
    Fuente.clear();
    Comida.clear();
    Alarma.clear();
    posicion->clear();
}
