//
//  Nodo_APatrullar.cpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 23/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Nodo_APatrullar.hpp"

short Nodo_APatrullar::run(const int &ID){
    
    NpcLibrary::instancia()->recover_book(ID)->Patrullar = false;
    
    return FUNCIONO;
}
