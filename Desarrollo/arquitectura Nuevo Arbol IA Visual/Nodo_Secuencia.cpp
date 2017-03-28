//
//  Nodo_Secuencia.cpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 22/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Nodo_Secuencia.hpp"

short Nodo_Secuencia::run(const int &ID){
    for (;hijo<hijos.size();hijo++) {
        
        short respuesta = hijos[hijo]->run(ID);
        
        if(respuesta==FUNCIONO) continue;
        else if(respuesta==RUNNING) return RUNNING;
        
        hijo = 0;
        return FALLO;
    }
    
    hijo = 0;
    return FUNCIONO;
}

void Nodo_Secuencia::reset(){
    for (int i=0; i<hijos.size(); i++)
        hijos[i]->reset();
    hijo = 0;
}

void Nodo_Secuencia::addHijo(Nodo_base * nHijo){hijos.push_back(nHijo);}

Nodo_Secuencia::~Nodo_Secuencia(){
    for(int i=0;i<hijos.size();i++)
        delete hijos[i];
}
