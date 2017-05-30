//
//  Nodo_QCombatir.cpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 23/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Nodo_QCombatir.hpp"

short Nodo_QCombatir::run(const int &ID){
    if(activado)
        return runHijos(ID);
    NpcBook * book = NpcLibrary::instancia()->recover_book(ID);
    if(book->getMoral()>NEEDHELP && book->Enemigo){
        activado = true;
        return RUNNING;
    }
    
    return FALLO;
}
