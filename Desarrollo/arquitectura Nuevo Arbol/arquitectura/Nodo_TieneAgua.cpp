//
//  Nodo_TieneAgua.cpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Nodo_TieneAgua.hpp"


Nodo_TieneAgua::Nodo_TieneAgua(){}

Nodo_TieneAgua::~Nodo_TieneAgua(){}

short Nodo_TieneAgua::run(int &id){
    //cout << " NODO FUENTE TIENE AGUA?" << endl;
    if(LevelBlackBoard::instance()->getRecord(id, P_SED)->romper){
        LevelBlackBoard::instance()->CreateRecord(LevelBlackBoard::instance()->getRecord(id, P_SED)->IDRespuesta, P_SED,true);
        LevelBlackBoard::instance()->RemoveRecord(id, P_SED);
        return false;
    }
    
    return true;
}
