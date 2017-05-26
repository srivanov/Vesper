//
//  Nodo_AAlimentarse.cpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 23/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Nodo_AAlimentarse.hpp"

short Nodo_AAlimentarse::run(const int &ID){
    cout << "ME ALIMENTO" << endl;
    NpcBook * book = NpcLibrary::instancia()->recover_book(ID);
    book->remove_EventsByType(P_HAMBRE);
    book->hambre-=ALIMENTACION;
    return FUNCIONO;
}
