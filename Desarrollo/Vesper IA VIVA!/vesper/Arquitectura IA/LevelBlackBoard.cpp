//
//  LevelBlackBoard.cpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 10/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "LevelBlackBoard.hpp"

/*
 RECORDS
 */

Record::Record(const int&ID , dvector3D* posicion) : posicionRespuesta(nullptr){
    romper = false;
    IDRespuesta = -1;
    IDSolicitante = ID;
    posicionSolicitante = posicion;
}

Record::Record(const int& ID, bool b) : posicionSolicitante(nullptr) , posicionRespuesta(nullptr){
    romper = b;
    IDRespuesta = -1;
    IDSolicitante = ID;
}

bool Record::HasAnswer(){
    if(IDRespuesta!=-1) return true;
    return false;
}
Record::~Record(){}

/*
 LEVEL_BLACKBOARD
 
*/



LevelBlackBoard * LevelBlackBoard::instance(){
    static LevelBlackBoard blackboard;
    return &blackboard;
}

LevelBlackBoard::LevelBlackBoard(){}

LevelBlackBoard::~LevelBlackBoard(){
    if(m_peticiones.size()>0){
        it=m_peticiones.begin();
        while (it!=m_peticiones.end()) {
            delete it->second;
            it++;
        }
    }
    m_peticiones.clear();
}


std::string LevelBlackBoard::key_converter(const int &ID, const Prioridades &tipo){
    return std::to_string(ID)+"-"+std::to_string(tipo);
}

bool LevelBlackBoard::exist_record(const int &ID, const Prioridades& tipo){
    it = m_peticiones.find(key_converter(ID,tipo));
    if(it!=m_peticiones.end()) return true;
    return false;
}

bool LevelBlackBoard::AnswerRecord(const Prioridades &tipo,int& ID_Res, dvector3D *posicion){
    
    bool respuesta = false;
    
    it = m_peticiones.begin();
    std::string Stype = std::to_string(tipo);
    while (it!=m_peticiones.end()) {
        std::string TypeR = it->first.substr(it->first.find("-"));
        TypeR.erase(TypeR.begin());
        if(TypeR==Stype && regulator(posicion)){
            it->second->posicionRespuesta = posicion;
            it->second->IDRespuesta = ID_Res;
            respuesta = true;
        }
        it++;
    }
    
    return respuesta;
}

bool LevelBlackBoard::CreateRecord(const int &ID, const Prioridades &tipo, dvector3D * posicion){
    if (exist_record(ID, tipo)) return false;
    
    m_peticiones.insert(std::pair<std::string, Record*>(key_converter(ID, tipo),new Record(ID,posicion)));
    return true;
}

bool LevelBlackBoard::CreateRecord(const int &ID, const Prioridades &tipo, bool accion){
    if (exist_record(ID, tipo)) return false;
    
    m_peticiones.insert(std::pair<std::string, Record*>(key_converter(ID, tipo),new Record(ID,accion)));
    return true;
}

bool LevelBlackBoard::RemoveRecord(const int &ID, const Prioridades &tipo){
    if (exist_record(ID, tipo)) {
        delete it->second;
        m_peticiones.erase(it);
        return true;
    }
    return false;
}

Record * LevelBlackBoard::getRecord(const int &ID, const Prioridades &tipo){
    if(!exist_record(ID, tipo)) return nullptr;
    return it->second;
}

bool LevelBlackBoard::regulator(dvector3D * posicion){
    if (it->second->IDRespuesta == -1) return true;
    
    float distanciaActual = EasyMath::CalcularDistancia(*posicion, *it->second->getPosition());
    float distanciaNueva = EasyMath::CalcularDistancia(*it->second->posicionRespuesta, *it->second->getPosition());
    
    if (distanciaNueva<distanciaActual) return true;
    return false;
    
}
