//
//  NodoSecuencia.cpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "NodoRaiz.hpp"

#define FAILURE 0
#define SUCCESS 1
#define RUNNING 2


NodoRaiz::NodoRaiz(){}

NodoRaiz::~NodoRaiz(){
    for (int i=0; i<m_hijos.size(); i++) {
        if(m_hijos[i]!=NULL){
            delete m_hijos[i];
            m_hijos[i] = NULL;
        }
    }
    m_hijos.clear();
}

short NodoRaiz::run(int &id){
    //cout << "NODO RAIZ" << endl;
    for (int i=0;i<m_hijos.size(); i++) {
        if (m_hijos[i]->run(id))
            return SUCCESS;
    }
    return FAILURE;
}

void NodoRaiz::reset(){
    for (int i=0; i<m_hijos.size(); i++) {
        m_hijos[i]->reset();
    }
}

void NodoRaiz::anyadirHijo(Nodo * hijo){NodoRaiz::m_hijos.push_back(hijo);}
