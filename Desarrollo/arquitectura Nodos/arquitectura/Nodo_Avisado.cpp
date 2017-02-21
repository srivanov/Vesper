//
//  Nodo_Avisado.cpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Nodo_Avisado.hpp"


//#############################
//#    NODOS DE CONDICION     #
//#############################

Nodo_Avisado::Nodo_Avisado(){};

Nodo_Avisado::~Nodo_Avisado(){}

short Nodo_Avisado::run(int &id){
    //cout << " NODO AVISADO ?" << endl;
    if(NpcLibrary::instancia()->recover_book(id)->ExistEventByType(P_AVISO))
        return true;
    return false;
}
