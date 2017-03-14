//
//  Nodo_RAyudar.cpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 23/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Nodo_RAlarma_Cercana.hpp"

short Nodo_RAlarma_Cercana::run(const int &ID){
    NpcLibrary::instancia()->recover_book(ID)->Alarma = false;
    return FUNCIONO;
}
