//
//  Nodo_TengoHambre.cpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Nodo_TengoHambre.hpp"

#define UMBRAL_HAMBRE 60


Nodo_TengoHambre::Nodo_TengoHambre(){}

Nodo_TengoHambre::~Nodo_TengoHambre(){}

short Nodo_TengoHambre::run(int &id){
    //cout << "NODO TENGO HAMBRE" << endl;
    
    //CONDICION CRITICA
    if(!NpcLibrary::instancia()->recover_book(id)) return false;
    
    if (NpcLibrary::instancia()->recover_book(id)->ExistEventByType(P_HAMBRE))
        return true;
    
    NpcBook * book = NpcLibrary::instancia()->recover_book(id);
    
    if(book->hambre>=UMBRAL_HAMBRE){
        if (LevelBlackBoard::instance()->exist_record(id, P_HAMBRE)) {
            Record * record = LevelBlackBoard::instance()->getRecord(id, P_HAMBRE);
            
            if(!record) return false; // CONDICION CRITICA
            
            if (record->HasAnswer()) {
                book->notify(record->IDRespuesta,P_HAMBRE, record->posicionRespuesta);
                book = nullptr;
                record = nullptr;
                return RUNNING;
            }
            book = nullptr;
            record = nullptr;
            return false;
        }
        LevelBlackBoard::instance()->CreateRecord(id, P_HAMBRE, book->getPosition());
    }
    book = nullptr;
    return false;
}
