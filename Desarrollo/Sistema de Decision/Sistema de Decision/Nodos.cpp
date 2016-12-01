//
//  Nodos.cpp
//  Sistema de Decision
//
//  Created by Gaspar Rodriguez Valero on 29/11/16.
//  Copyright © 2016 Gaspar Rodriguez Valero. All rights reserved.
//


#include "Nodos.hpp"

NodoSecuencia::NodoSecuencia(){}
void NodoSecuencia::anyadirHijo(Nodo * hijo){NodoSecuencia::m_hijos.push_back(hijo);}
bool NodoSecuencia::run(){
    for (int i=0; i<m_hijos.size(); i++) {
        if(!m_hijos[i]->run()){return false;}
    }
    return true;
}
