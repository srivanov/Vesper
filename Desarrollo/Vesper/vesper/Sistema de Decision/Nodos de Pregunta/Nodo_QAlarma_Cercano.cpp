//
//  Nodo_QAlarma_Cercano.cpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 23/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Nodo_QAlarma_Cercano.hpp"

short Nodo_QAlarma_Cercano::run(const int &ID){
    if(activado)
        return runHijos(ID);
    if(NpcLibrary::instancia()->recover_book(ID)->Alarma){
        activado = true;
        return RUNNING;
    }
    
    return FALLO;
}
