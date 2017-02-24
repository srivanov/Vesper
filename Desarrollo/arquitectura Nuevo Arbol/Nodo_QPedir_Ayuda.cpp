//
//  Nodo_QPedir_Ayuda.cpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 23/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Nodo_QPedir_Ayuda.hpp"

short Nodo_QPedir_Ayuda::run(const int &ID){
    cout << "PEDIR AYUDA?" << endl;
    //TO DO: POR DEFINIR FUNCION
    return FALLO;
    NpcBook * book = NpcLibrary::instancia()->recover_book(ID);
    if(book->getMoral()<NEEDHELP){
        activado = true;
        return RUNNING;
    }
    return FALLO;
}
