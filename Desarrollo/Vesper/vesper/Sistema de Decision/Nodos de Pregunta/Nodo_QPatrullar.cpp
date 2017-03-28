//
//  Nodo_QPatrullar.cpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 23/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Nodo_QPatrullar.hpp"

short Nodo_QPatrullar::run(const int &ID){
    //cout << "PATRULLAR?" << endl;
    if(NpcLibrary::instancia()->recover_book(ID)->ExistEventByType(P_PATRULLAR))
        return runHijos(ID);
    return FALLO;
}
