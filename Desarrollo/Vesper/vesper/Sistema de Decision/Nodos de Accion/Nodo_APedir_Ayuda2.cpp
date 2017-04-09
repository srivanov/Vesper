//
//  Nodo_APedir_Ayuda2.cpp
//  vesper
//
//  Created by Gaspar Rodriguez Valero on 8/4/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Nodo_APedir_Ayuda2.hpp"

short Nodo_APedir_Ayuda2::run(const int &ID){
    LevelBlackBoard * black = LevelBlackBoard::instance();
    NpcBook * book = NpcLibrary::instancia()->recover_book(ID);
    if(black->exist_record(ID, P_ALARMA)){
        Record * rec =  black->getRecord(ID, P_ALARMA);
        t.start();
        if(rec->HasAnswer()){
            book->notify(rec->IDRespuesta, P_ALARMA, rec->posicionRespuesta);
            book->ACTalarma = true;
            return FUNCIONO;
        }
        if(t.tTranscurrido(2.f))
            no_alarmas = true;
        if(no_alarmas)
            return FALLO;
        return RUNNING;
    }
    return FALLO;
}
