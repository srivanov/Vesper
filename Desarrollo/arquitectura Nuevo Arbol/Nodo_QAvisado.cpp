//
//  Nodo_QAvisado.cpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 22/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Nodo_QAvisado.hpp"

short Nodo_QAvisado::run(const int &ID){
    cout << "AVISADO?" << endl;
    if(activado){
        short answer = runHijos(ID);
        if(answer==FUNCIONO) activado = false;
        return answer;
    }
    if(NpcLibrary::instancia()->recover_book(ID)->Aviso){
        activado = true;
        return RUNNING;
    }
    return FALLO;
}
