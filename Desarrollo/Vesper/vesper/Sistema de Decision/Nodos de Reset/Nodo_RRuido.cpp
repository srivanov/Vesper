//
//  Nodo_RRuido.cpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 22/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Nodo_RRuido.hpp"

short Nodo_RRuido::run(const int &ID){
    NpcLibrary::instancia()->recover_book(ID)->Ruido=false;
    return FUNCIONO;
}
