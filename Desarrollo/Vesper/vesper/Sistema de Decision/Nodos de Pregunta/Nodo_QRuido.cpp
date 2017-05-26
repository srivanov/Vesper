//
//  Nodo_QRuido.cpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 22/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Nodo_QRuido.hpp"

short Nodo_QRuido::run(const int &ID){
    
    cout << "RUIDO?" << endl;
    
    if(activado)
        return runHijos(ID);
    NpcBook * book = NpcLibrary::instancia()->recover_book(ID);
    if(book->Ruido){
        cout << "HAY RUIDO" << endl;
        activado = true;
        return RUNNING;
    }
    return FALLO;
}
