//
//  Nodo_QHidratarse.cpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 23/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Nodo_QHidratarse.hpp"

short Nodo_QHidratarse::run(const int &ID){
    if(activado)
        return runHijos(ID);
    
    NpcBook * book = NpcLibrary::instancia()->recover_book(ID);
    if(book->ExistEventByType(P_SED)){
        activado = true;
        return RUNNING;
    }
    
    LevelBlackBoard * Level = LevelBlackBoard::instance();
    Record * record = Level->getRecord(ID, P_SED);
    if (book->sed>UMBRALSED) {
        if(!record)
            Level->CreateRecord(ID,P_SED,book->getPosition());
        else if(record->HasAnswer()){
            book->notify(record->IDRespuesta,P_SED, record->posicionRespuesta);
            return RUNNING;
        }
    }
    return FALLO;
}
