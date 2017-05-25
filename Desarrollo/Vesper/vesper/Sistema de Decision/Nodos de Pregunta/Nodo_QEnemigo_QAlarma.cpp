//
//  Nodo_QEnemigo_QAlarma.cpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 22/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Nodo_QEnemigo_QAlarma.hpp"

short Nodo_QEnemigo_QAlarma::run(const int &ID){
    cout << "ENEMIGO O ALARMA?" << endl;
    if(activado)
        return runHijos(ID);
    NpcBook * book = NpcLibrary::instancia()->recover_book(ID);
    if(book->Enemigo || book->Alarma){
        activado = true;
        return RUNNING;
    }
    
    return FALLO;
}
