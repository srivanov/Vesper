//
//  Nodo_QPedir_Ayuda.cpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 23/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Nodo_QPedir_Ayuda.hpp"

short Nodo_QPedir_Ayuda::run(const int &ID){
    //cout << "PEDIR AYUDA?" << endl;
    //TO DO: POR DEFINIR FUNCION
    /*
    if(activado && !CONGELADO){
         //cout << "NECESITO AYUDA" << endl;
        short answer = runHijos(ID);
        if(!activado)
            CONGELADO=true;
        return answer;
    }
    NpcBook * book = NpcLibrary::instancia()->recover_book(ID);
    if(book->getMoral()<NEEDHELP && !CONGELADO){
        //cout << "MORAL: " << book->getMoral() << endl;
        activado = true;
        return RUNNING;
    }
     */
    return FALLO;
}
