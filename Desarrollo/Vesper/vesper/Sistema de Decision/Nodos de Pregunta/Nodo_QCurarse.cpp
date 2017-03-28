//
//  Nodo_QCurarse.cpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 23/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Nodo_QCurarse.hpp"

short Nodo_QCurarse::run(const int &ID){
    //cout << "CURARSE?" << endl;
    if(activado){
        short answer = runHijos(ID);
        if(answer==FUNCIONO) activado = false;
        return answer;
    }
    
    NpcBook * book = NpcLibrary::instancia()->recover_book(ID);
    if(book->ExistEventByType(P_VIDA)){
        activado = true;
        return RUNNING;
    }
    
    LevelBlackBoard * Level = LevelBlackBoard::instance();
    Record * record = Level->getRecord(ID, P_VIDA);
    if (book->salud<UMBRALVIDA) {
        if(!record)
            Level->CreateRecord(
                                ID,
                                P_VIDA,
                                book->getPosition()
                                );
        else if(record && record->HasAnswer()){
            
            book->notify(record->IDRespuesta,P_VIDA, record->posicionRespuesta);
            return RUNNING;
        }
    }
    return FALLO;
}
