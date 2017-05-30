//
//  Nodo_QVigilar.cpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 23/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Nodo_QVigilar.hpp"

short Nodo_QVigilar::run(const int &ID){
    //cout << "VIGILAR?" << endl;
    if(activado)
        return runHijos(ID);
    NpcBook * book = NpcLibrary::instancia()->recover_book(ID);
    if(book->ExistEventByType(P_VIGILAR)){
        activado = true;
        return RUNNING;
    }
    return FALLO;
}
