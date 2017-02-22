//
//  NodoSecuencia.cpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "NodoSecuencia.hpp"

#define FAILURE 0
#define SUCCESS 1
#define RUNNING 2


NodoSecuencia::NodoSecuencia(){hijo=0;}

NodoSecuencia::~NodoSecuencia(){
    for (int i=0; i<m_hijos.size(); i++) {
        if(m_hijos[i]!=NULL){
            delete m_hijos[i];
            m_hijos[i] = NULL;
        }
    }
    m_hijos.clear();
}

short NodoSecuencia::run(int &id){
    //cout << "NODO SECUENCIA" << endl;
    for (;hijo<m_hijos.size(); hijo++) {
        short answer = m_hijos[hijo]->run(id);
        if (answer==FAILURE) {hijo=0;return FAILURE;}
        else if(answer==RUNNING){return RUNNING;}
    }
    hijo=0;
    return SUCCESS;
}

void NodoSecuencia::reset(){
    for (int i=0; i<m_hijos.size(); i++) {
        m_hijos[i]->reset();
    }
    hijo = 0;
}

void NodoSecuencia::anyadirHijo(Nodo * hijo){NodoSecuencia::m_hijos.push_back(hijo);}
