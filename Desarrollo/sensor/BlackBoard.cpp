//
//  BlackBoard.cpp
//  vesper
//
//  Created by Gaspar Rodriguez Valero on 1/12/16.
//  Copyright © 2016 Skyscrapers. All rights reserved.
//

#include "BlackBoard.hpp"
#include "NPC.hpp"
#include "objects.hpp"

blackboard * blackboard::_instance = 0;

blackboard * blackboard::Instance(){
    if(_instance==0)
        _instance = new blackboard;
    return _instance;
}

int blackboard::countDTRECORD(ENUM_DTRECORD_TYPE type){
    int count = 0;
    for (int i=0; i<m_lstDTRECORD.size(); i++) {
        if(m_lstDTRECORD[i]->eType==type) count++;
    }
    return count;
}
int blackboard::countDTRECORD(ENUM_DTRECORD_TYPE type, int id_Target){
    int count = 0;
    for (int i=0; i<m_lstDTRECORD.size(); i++) {
        if(m_lstDTRECORD[i]->eType==type && m_lstDTRECORD[i]->ID_Target) count++;
    }
    return count;
}
vector3D * blackboard::getDTRECORD_DATA(ENUM_DTRECORD_TYPE type){
    for (int i=0; i<m_lstDTRECORD.size(); i++) {
        if(m_lstDTRECORD[i]->eType == type) return m_lstDTRECORD[i]->V3DData;
    }
    return NULL;
}









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
