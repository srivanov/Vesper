//
//  Nodo_QAlimentarse.cpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 23/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Nodo_QAlimentarse.hpp"

short Nodo_QAlimentarse::run(const int &ID){
    //cout << "ALIMENTARSE?" << endl;
    
    
    // BUSCA SI EXISTE PETICION SI NO LA CREA
    if(activado)
        return runHijos(ID);
    
    
    NpcBook * book = NpcLibrary::instancia()->recover_book(ID);
    
    if(book->ExistEventByType(P_HAMBRE)){
        activado = true;
        return RUNNING;
    }
    LevelBlackBoard * Level = LevelBlackBoard::instance();
    Record * record = Level->getRecord(ID, P_HAMBRE);
    if (book->hambre>UMBRALHAMBRE) {
        if(!record)
            Level->CreateRecord(
                                ID,
                                P_HAMBRE,
                                book->getPosition()
                                );
        else if(record && record->HasAnswer()){
            
            book->notify(record->IDRespuesta,P_HAMBRE, record->posicionRespuesta);
            return RUNNING;
        }
    }
    return FALLO;
}
