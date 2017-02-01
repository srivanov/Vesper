//
//  NodoSecuenciaPositiva.cpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "NodoSecuenciaPositiva.hpp"

#define FAILURE 0
#define SUCCESS 1
#define RUNNING 2

NodoSecuenciaPositiva::NodoSecuenciaPositiva(){hijo=0;}

short NodoSecuenciaPositiva::run(int &id){
    cout << "NODO SECUENCIA POSITIVA" <<endl;
    for(;hijo<m_hijos.size();hijo++){
        short answer = m_hijos[hijo]->run(id);
        if(answer==SUCCESS){hijo=0;return SUCCESS;}
        else if (answer==RUNNING){return RUNNING;}
    }
    hijo=0;
    return FAILURE;
}

void NodoSecuenciaPositiva::anyadirHijo(Nodo * hijo){m_hijos.push_back(hijo);}

NodoSecuenciaPositiva::~NodoSecuenciaPositiva(){
    for (int i=0; i<m_hijos.size(); i++) {
        if(m_hijos[i]!=NULL){
            delete m_hijos[i];
            m_hijos[i]=NULL;
        }
    }
    m_hijos.clear();
}

void NodoSecuenciaPositiva::reset(){
    for (int i=0; i<m_hijos.size(); i++) {
        m_hijos[i]->reset();
    }
    hijo = 0;
}
