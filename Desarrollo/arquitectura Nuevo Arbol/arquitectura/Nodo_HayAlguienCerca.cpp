//
//  Nodo_HayAlguienCerca.cpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Nodo_HayAlguienCerca.hpp"


Nodo_HayAlguienCerca::Nodo_HayAlguienCerca(){}
Nodo_HayAlguienCerca::~Nodo_HayAlguienCerca(){}
short Nodo_HayAlguienCerca::run(int &id){
   //cout << "NODO HAY ALGUIEN CERCA " << endl;
    
    if(LevelBlackBoard::instance()->exist_record(id, P_RADIO)) return false;
    
    if (NpcLibrary::instancia()->recover_book(id)->ExistEventByType(P_AVISO)) return true;
    
    if(LevelBlackBoard::instance()->exist_record(id, P_AVISO)){
        if(LevelBlackBoard::instance()->getRecord(id, P_AVISO)->HasAnswer()){
            NpcLibrary::instancia()->recover_book(id)->notify(LevelBlackBoard::instance()->getRecord(id, P_AVISO)->IDRespuesta,P_AVISO, LevelBlackBoard::instance()->getRecord(id, P_AVISO)->posicionRespuesta);
            return RUNNING;
        }
        return false;
    }else
        LevelBlackBoard::instance()->CreateRecord(id, P_AVISO, NpcLibrary::instancia()->recover_book(id)->getPosition());
    
    
    return false;
}
