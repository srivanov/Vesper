//
//  NodoDarAlarma.cpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "NodoDarAlarma.hpp"


NodoDarAlarma::NodoDarAlarma(){}

NodoDarAlarma::~NodoDarAlarma(){}

short NodoDarAlarma::run(int &id){
    //cout << " NODO DAR ALARMA" << endl;
    
    Record * record = LevelBlackBoard::instance()->getRecord(id, P_ALARMA);
    bool respuesta = false;
    
    if(!record->romper)
        respuesta = true;
    
    
    LevelBlackBoard::instance()->CreateRecord(record->IDRespuesta, P_ALARMA, record->posicionRespuesta);
    LevelBlackBoard::instance()->RemoveRecord(id, P_ALARMA);
    
    
    return respuesta;
}
