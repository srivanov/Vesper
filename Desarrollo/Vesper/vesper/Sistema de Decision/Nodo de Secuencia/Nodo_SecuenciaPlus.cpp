//
//  Nodo_SecuenciaPlus.cpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 22/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Nodo_SecuenciaPlus.hpp"

short Nodo_SecuenciaPlus::run(const int &ID){
    for (;hijo<hijos.size();hijo++) {
        
        short respuesta = hijos[hijo]->run(ID);
        
        if(respuesta==FALLO) continue;
        else if(respuesta==RUNNING) return RUNNING;
        
        hijo = 0;
        return FUNCIONO;
    }
    
    hijo = 0;
    return FALLO;
}
