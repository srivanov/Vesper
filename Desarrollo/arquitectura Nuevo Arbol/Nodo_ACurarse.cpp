//
//  Nodo_ACurarse.cpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 23/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Nodo_ACurarse.hpp"

short Nodo_ACurarse::run(const int &ID){
    cout << "ME CURO" << endl;
    NpcBook * book = NpcLibrary::instancia()->recover_book(ID);
    book->remove_Events(P_VIDA);
    book->salud+=CURACION;
    return FUNCIONO;
}
