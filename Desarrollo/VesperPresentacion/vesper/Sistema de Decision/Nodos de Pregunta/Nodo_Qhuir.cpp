//
//  Nodo_Qhuir.cpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 22/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Nodo_Qhuir.hpp"

short Nodo_Qhuir::run(const int &ID){
    //cout << "HUIR?" << endl;
    if(activado)
        return runHijos(ID);
    NpcBook * book = NpcLibrary::instancia()->recover_book(ID);
    if(book->getMoral()<RUNAWAY){
        activado = true;
        return RUNNING;
    }
    return FALLO;
}
