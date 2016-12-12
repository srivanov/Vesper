//
//  BlackBoard.cpp
//  vesper
//
//  Created by Gaspar Rodriguez Valero on 1/12/16.
//  Copyright © 2016 Skyscrapers. All rights reserved.
//

#include "BlackBoard.hpp"

BlackBoard::BlackBoard(){}
BlackBoard::~BlackBoard(){}
void BlackBoard::clean(){
    ObjetosCercanos.clear();
    posicionesNPC.clear();
    comprobadaAlarma = false;
    comprobadaFuente = false;
    estadoAlarma = false;
    estadoFuente = false;
}
