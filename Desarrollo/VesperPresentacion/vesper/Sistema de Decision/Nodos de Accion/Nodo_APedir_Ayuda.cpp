//
//  Nodo_APedir_Ayuda.cpp
//  vesper
//
//  Created by Gaspar Rodriguez Valero on 8/4/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Nodo_APedir_Ayuda.hpp"

short Nodo_APedir_Ayuda::run(const int &ID){
    
    
    NpcBook * book = NpcLibrary::instancia()->recover_book(ID);
    gestor_eventos * gestor = gestor_eventos::instance();
    
    /*
    if(!alarma && (gestor->revisadoEvento(P_AVISO, ID) || gestor->revisadoEvento(P_AYUDA, ID))){
        return FUNCIONO;
    }
    
    if(!primera_ayuda){
        primera_ayuda=true;
        gestor->addEvento(ID, P_AVISO, book->getPosition());
    }
    
    if((primera_ayuda && !segunda_ayuda) && !gestor->existeEvento(P_AVISO, ID)){
        segunda_ayuda=true;
        gestor->addEvento(ID, P_AYUDA, book->getPosition());
    }
    
    if((primera_ayuda && segunda_ayuda && !alarma) && !gestor->existeEvento(P_AYUDA, ID)){
        alarma=true;
        LevelBlackBoard::instance()->CreateRecord(ID, P_ALARMA, book->getPosition());
        return FUNCIONO;
    }

    if(primera_ayuda && segunda_ayuda && alarma)
        return FUNCIONO;
     */
    
    if(!gestor->existeEvento(P_AYUDA, ID)){
        gestor->addEvento(ID, P_AYUDA, book->getPosition());
        LevelBlackBoard::instance()->CreateRecord(ID, P_ALARMA, book->getPosition());
        return RUNNING;
    }
    cout << "HOLA" << endl;
    Record * r =  LevelBlackBoard::instance()->getRecord(ID, P_ALARMA);
    if(r->HasAnswer()){
        return FUNCIONO;
    }
    
    
    return FALLO;
}
