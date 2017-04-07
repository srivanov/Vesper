//
//  Nodo_AAtacar.cpp
//  vesper
//
//  Created by Gaspar Rodriguez Valero on 7/4/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Nodo_AAtacar.hpp"

short Nodo_AAtacar::run(const int &ID){
    
    NpcLibrary::instancia()->recover_book(ID)->ATACAR = true;
    return FUNCIONO;
    
}
