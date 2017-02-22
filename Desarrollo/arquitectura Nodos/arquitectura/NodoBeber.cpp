//
//  NodoBeber.cpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "NodoBeber.hpp"

#define AGUA_HIDATRA 70


NodoBeber::NodoBeber(){}

NodoBeber::~NodoBeber(){}

short NodoBeber::run(int &id){
    cout << " NODO BEBER" <<endl;
    
    Record * record = LevelBlackBoard::instance()->getRecord(id, P_SED);
    
    if(!NpcLibrary::instancia()->recover_book(id) || !record) return false;
    
    LevelBlackBoard::instance()->CreateRecord(record->IDRespuesta, P_SED, record->posicionRespuesta);
   
    LevelBlackBoard::instance()->RemoveRecord(id, P_SED);
    
    NpcLibrary::instancia()->recover_book(id)->sed-=AGUA_HIDATRA;
    return true;
}
