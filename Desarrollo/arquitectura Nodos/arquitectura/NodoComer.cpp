//
//  NodoComer.cpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "NodoComer.hpp"

#define COMIDA_ALIMENTA 45

NodoComer::NodoComer(){}

short NodoComer::run(int &id){
    //cout << " NODO COMER" <<endl;
    
    
    Record * record = LevelBlackBoard::instance()->getRecord(id, P_HAMBRE);
    
    
    if(!NpcLibrary::instancia()->recover_book(id) || !record) return false;
    
    LevelBlackBoard::instance()->CreateRecord(record->IDRespuesta, P_HAMBRE, record->posicionRespuesta);
    
    LevelBlackBoard::instance()->RemoveRecord(id, P_HAMBRE);
    
    NpcLibrary::instancia()->recover_book(id)->hambre-=COMIDA_ALIMENTA;
    return true;
}

NodoComer::~NodoComer(){}

