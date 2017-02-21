//
//  Nodo_HayBotiquin.cpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Nodo_HayBotiquin.hpp"


Nodo_HayBotiquin::Nodo_HayBotiquin(){}

Nodo_HayBotiquin::~Nodo_HayBotiquin(){}

short Nodo_HayBotiquin::run(int &id){
    //cout << "NODO HAY BOTIQUIN" << endl;
    
    // CONDICION CRITICA
    if(!NpcLibrary::instancia()->recover_book(id)) return false;
    
    
    if(NpcLibrary::instancia()->recover_book(id)->ExistEventByType(P_VIDA))
        return true;
    
    if (LevelBlackBoard::instance()->exist_record(id, P_VIDA)) {
        Record * record = LevelBlackBoard::instance()->getRecord(id, P_VIDA);
        
        if(!record) return false; //CONDICION CRITICA
        
        else if(record->HasAnswer())
            NpcLibrary::instancia()->recover_book(id)->notify(record->IDRespuesta,P_VIDA, record->posicionRespuesta);
        
        record = nullptr;
        return RUNNING;
    }
    LevelBlackBoard::instance()->CreateRecord(id, P_VIDA, NpcLibrary::instancia()->recover_book(id)->getPosition());
    return false;
}
