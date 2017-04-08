//
//  Nodo_RAvisado.cpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 22/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Nodo_RAvisado.hpp"

short Nodo_RAvisado::run(const int &ID){
    NpcLibrary::instancia()->recover_book(ID)->Aviso = false;
    return FUNCIONO;
}
