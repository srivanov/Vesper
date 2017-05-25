//
//  Nodo_QAyudar.cpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 22/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Nodo_QAyudar.hpp"

short Nodo_QAyudar::run(const int &ID){
    cout << "AYUDAR?" << endl;
    if(activado){
       
        return runHijos(ID);
    }
    if(NpcLibrary::instancia()->recover_book(ID)->Aviso){
        activado = true;
        return RUNNING;
    }
    return FALLO;
}
