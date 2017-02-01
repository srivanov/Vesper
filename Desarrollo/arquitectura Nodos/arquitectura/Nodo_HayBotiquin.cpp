//
//  Nodo_HayBotiquin.cpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Nodo_HayBotiquin.hpp"
#include "BlackBoards.hpp"


//#############################
//#    NODOS DE CONDICION     #
//#############################

// NODO HAY BOTIQUIN ?
Nodo_HayBotiquin::Nodo_HayBotiquin(){}

Nodo_HayBotiquin::~Nodo_HayBotiquin(){}

short Nodo_HayBotiquin::run(int &id){
    cout << "NODO HAY BOTIQUIN" << endl;
    TypeRecords botiquin = R_BOTIQUIN;
    if (World_BlackBoard::instance()->existRecord(botiquin, id)) {
        if (World_BlackBoard::instance()->hasAnswer(botiquin, id)) {
            NPC_library::instance()->getMyBook(&id)->setPosObjetivo(World_BlackBoard::instance()->getAnswer(botiquin, id)->_answerInfo);
            return true;
        }
    }
    World_BlackBoard::instance()->addRecord(botiquin, id, NPC_library::instance()->getMyBook(&id)->getPosition());
    return false;
}
