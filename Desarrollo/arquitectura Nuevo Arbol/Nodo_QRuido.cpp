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
    
    if(activado){
        short answer = runHijos(ID);
        if(answer==FUNCIONO) activado = false;
        return answer;
    }
    NpcBook * book = NpcLibrary::instancia()->recover_book(ID);
    if(book->Ruido){
        activado = true;
        return RUNNING;
    }
    return FALLO;
}
