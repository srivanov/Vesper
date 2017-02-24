//
//  Nodo_Condicional_Secuencial.cpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 22/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Nodo_Condicional_Secuencial.hpp"


short Nodo_Condicional_Secuencial::runHijos(const int& ID){
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

void Nodo_Condicional_Secuencial::reset(){
    for (int i=0; i<hijos.size(); i++) {
        hijos[i]->reset();
    }
    activado = false;
    hijo = 0;
}
