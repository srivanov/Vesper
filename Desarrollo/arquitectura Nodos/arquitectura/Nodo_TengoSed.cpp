//
//  Nodo_TengoSed.cpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Nodo_TengoSed.hpp"

#define UMBRAL_SED 70

Nodo_TengoSed::Nodo_TengoSed(){}
Nodo_TengoSed::~Nodo_TengoSed(){}
short Nodo_TengoSed::run(int &id){
    //cout << "NODO TENGO SED" << endl;
    
    //CONDICION CRITICA
    if(!NpcLibrary::instancia()->recover_book(id)) return false;
    
    if (NpcLibrary::instancia()->recover_book(id)->ExistEventByType(P_SED)) return true;
    
    NpcBook * book = NpcLibrary::instancia()->recover_book(id);
    
    
    if(book->sed>UMBRAL_SED){
        if (LevelBlackBoard::instance()->exist_record(id, P_SED)) {
            Record * record = LevelBlackBoard::instance()->getRecord(id, P_SED);
            
            if(!record) return false; // CONDICION CRITICA
            
            if (record->HasAnswer()) {
                book->notify(record->IDRespuesta,P_SED, record->posicionRespuesta);
                return RUNNING;
            }
            return false;
        }
        LevelBlackBoard::instance()->CreateRecord(id, P_SED, book->getPosition());
    }
    return false;
}
