//
//  NodoBeber.cpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "NodoBeber.hpp"
#include "BlackBoards.hpp"

#define AGUA_HIDATRA 70


NodoBeber::NodoBeber(){}

NodoBeber::~NodoBeber(){}

short NodoBeber::run(int &id){
    cout << " NODO BEBER" <<endl;
    TypeRecords fuente = R_FUENTE;
    World_BlackBoard::instance()->addRecord(fuente,
                                            *World_BlackBoard::instance()->getAnswer(fuente, id)->_idResponse,
                                            World_BlackBoard::instance()->getAnswer(fuente, id)->_answerInfo);
    //World_BlackBoard::instance()->AnswerRecord(const TypeRecords &type, int *id, dvector3D *info)
    World_BlackBoard::instance()->removeRecord(fuente, id);
    NPC_library::instance()->getMyBook(&id)->setThirst(AGUA_HIDATRA);
    return true;
}
