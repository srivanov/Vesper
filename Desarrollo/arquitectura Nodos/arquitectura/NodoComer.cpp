//
//  NodoComer.cpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "NodoComer.hpp"
#include "BlackBoards.hpp"

#define COMIDA_ALIMENTA 45

NodoComer::NodoComer(){}

short NodoComer::run(int &id){
    cout << " NODO COMER" <<endl;
    TypeRecords comida = R_COMIDA;
    World_BlackBoard::instance()->addRecord(
                                            comida,
                                            *World_BlackBoard::instance()->getAnswer(comida,id)->_idResponse,
                                            World_BlackBoard::instance()->getAnswer(comida, id)->_answerInfo
                                            );
    //World_BlackBoard::instance()->AnswerRecord(const TypeRecords &type, int *id, dvector3D *info)
    World_BlackBoard::instance()->removeRecord(comida,id);
    NPC_library::instance()->getMyBook(&id)->setHungry(COMIDA_ALIMENTA);
    
    return true;
}

NodoComer::~NodoComer(){}

