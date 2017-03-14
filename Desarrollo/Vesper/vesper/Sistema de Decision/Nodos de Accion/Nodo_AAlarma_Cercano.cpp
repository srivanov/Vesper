//
//  Nodo_AAlarma_Cercano.cpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 23/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Nodo_AAlarma_Cercano.hpp"

short Nodo_AAlarma_Cercano::run(const int &ID){
    //cout << "FUI A LA ALARMA" << endl;
    NpcLibrary::instancia()->
    recover_book(ID)->Alarma = false;
    return FUNCIONO;
}
