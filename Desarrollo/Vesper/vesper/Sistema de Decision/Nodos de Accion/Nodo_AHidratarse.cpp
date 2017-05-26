//
//  Nodo_ACurarse.cpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 23/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Nodo_AHidratarse.hpp"

short Nodo_AHidratarse::run(const int &ID){
    cout << "ME HIDRATO" << endl;
    NpcBook * book = NpcLibrary::instancia()->recover_book(ID);
    book->remove_EventsByType(P_SED);
    book->sed-=HIDRATACION;
    return FUNCIONO;
}

