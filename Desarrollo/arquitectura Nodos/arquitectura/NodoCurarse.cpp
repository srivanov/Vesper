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
    cout << " NODO CURARSE" << endl;
    TypeRecords botiquin = R_BOTIQUIN;
    World_BlackBoard::instance()->addRecord(botiquin,
                                            *World_BlackBoard::instance()->getAnswer(botiquin, id)->_idResponse,
                                            World_BlackBoard::instance()->getAnswer(botiquin, id)->_answerInfo);
    //World_BlackBoard::instance()->AnswerRecord(const TypeRecords &type, int *id, dvector3D *info)
    World_BlackBoard::instance()->removeRecord(botiquin,id);
    NPC_library::instance()->getMyBook(&id)->setLife(BOTIQUIN_CURA);
    return true;
}
