//
//  LevelBlackBoard.hpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 10/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef LevelBlackBoard_hpp
#define LevelBlackBoard_hpp

#include "Dvector.hpp"
#include "EasyMath.hpp"
#include <map>
#include <stdlib.h>
#include <string>
#include "Types.h"

class Record{
    int IDSolicitante;
    dvector3D * posicionSolicitante;
public:
    bool romper;
    int IDRespuesta;
    dvector3D * posicionRespuesta;
    dvector3D * const getPosition() const{return posicionSolicitante;}
    Record(const int&,dvector3D*);
    Record(const int&,bool);
    bool HasAnswer();
    ~Record();
};

class LevelBlackBoard{
    static LevelBlackBoard * blackboard;
    LevelBlackBoard();
    std::map<std::string,Record*>::iterator it;
    std::map<std::string,Record*> m_peticiones;
    std::string key_converter(const int& ID,const Prioridades& tipo);
    bool regulator(dvector3D*);
public:
    ~LevelBlackBoard();
    Record * getRecord(const int&,const Prioridades&);
    bool exist_record(const int&,const Prioridades&);
    bool AnswerRecord(const Prioridades&,int&,dvector3D*);
    bool CreateRecord(const int&,const Prioridades&,dvector3D*);
    bool CreateRecord(const int&,const Prioridades&,bool);
    bool RemoveRecord(const int&,const Prioridades&);
    static LevelBlackBoard * instance();
};



#endif /* LevelBlackBoard_hpp */
