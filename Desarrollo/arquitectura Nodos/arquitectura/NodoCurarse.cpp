//
//  NodoCurarse.cpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "NodoCurarse.hpp"

#define BOTIQUIN_CURA 40

NodoCurarse::NodoCurarse(){}
NodoCurarse::~NodoCurarse(){}
short NodoCurarse::run(int &id){
    //cout << " NODO CURARSE" << endl;
    Record * record = LevelBlackBoard::instance()->getRecord(id, P_VIDA);
    
    //CONDICIONES CRITICAS
    if(!NpcLibrary::instancia()->recover_book(id) || !record)
        return false;
    
    
    LevelBlackBoard::instance()->CreateRecord(record->IDRespuesta, P_VIDA, record->posicionRespuesta);
    LevelBlackBoard::instance()->RemoveRecord(id, P_VIDA);
    NpcLibrary::instancia()->recover_book(id)->salud+=BOTIQUIN_CURA;
    record = nullptr;
    delete record;
    return true;
}
