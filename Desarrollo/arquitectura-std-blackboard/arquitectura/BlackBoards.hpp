/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BlackBoards.hpp
 * Author: Gaspar
 *
 * Created on 28 de diciembre de 2016, 11:08
 */

#ifndef BLACKBOARDS_HPP
#define BLACKBOARDS_HPP
#include <map>
#include <stdlib.h>
#include "Dvector.hpp"
#include <string>



enum TypeRecords{
    R_NONE = -1,
    R_BOTIQUIN,
    R_ALARMA,
    R_COMIDA,
    R_FUENTE,
    R_Ntipos
};
struct record {
    int * _idResponse;
    dvector3D * _info;
    dvector3D * _answerInfo;
    void addAnswer() {answer = true;}
    record(dvector3D * info);
    ~record();
    bool isAnswer() const {return answer;}
private:
    bool answer;
};


typedef std::map<std::string,record*> BLACKBOARD_MAP;
class World_BlackBoard {
    static World_BlackBoard * _blackboard;
    BLACKBOARD_MAP _map;
    BLACKBOARD_MAP::iterator it;
    float absolute(float p);
public:
    static World_BlackBoard * instance();
    void AnswerRecord(TypeRecords& type, int& id, dvector3D * info);
    void addRecord(TypeRecords& type, int& id, dvector3D * info);
    void removeRecord(TypeRecords& type, int& id);
    unsigned long countType(TypeRecords& type);
    bool hasAnswer(TypeRecords& type, int& id);
    record * getAnswer(TypeRecords& type, int& id);
    void CleanByID(int& id);
    bool regulator(dvector3D* info);
    World_BlackBoard();
    World_BlackBoard(const World_BlackBoard& orig);
    bool existRecord(TypeRecords& type, int& id);
    virtual ~World_BlackBoard();  
};
class Personal_BlackBoard{
    unsigned int *_life,*_hungry,*_thirst,*_state;
    dvector3D * _position, *_posObjetivo;
    dvector3D * _Vmov;
public:
    Personal_BlackBoard(unsigned int& life,unsigned int& hungry,unsigned int& thirst, unsigned int& state,dvector3D * position);
    ~Personal_BlackBoard();
    unsigned int getLife() const {return *_life;}
    unsigned int getHungry() const {return *_hungry;}
    unsigned int getThirst() const {return *_thirst;}
    unsigned int getState() const {return *_state;}
    dvector3D * getPosition() const {return _position;}
    dvector3D * getPosObjetivo() const {return _posObjetivo;}
    void setPosObjetivo(dvector3D * position);
    void setLife(int life);
    void setHungry(int hungry);
    void setThirst(int thirst);
    void setState(unsigned int NewState);
    dvector3D * getVMovement() const {return _Vmov;}
    void setVMovement(dvector3D * Vmov);
    void update(unsigned int& life,unsigned int& hungry,unsigned int& thirst, unsigned int& state,dvector3D * position);
};
typedef std::map<int *,Personal_BlackBoard*> NPC_VALUES;
class NPC_library{
    NPC_VALUES _values;
    NPC_VALUES::iterator it;
    static NPC_library * _library;
public:
    static NPC_library * instance();
    bool ExistMyBook(int * id);
    void AddBook(int * id,unsigned int& life,unsigned int& hungry,unsigned int& thirst,unsigned int& state,dvector3D * position);
    void RemoveBook(int * id);
    void updateMyBook(int * id,unsigned int& life,unsigned int& hungry,unsigned int& thirst, unsigned int& state,dvector3D * position);
    Personal_BlackBoard * getMyBook(int * id);
    NPC_library();
    ~NPC_library();
};

#endif /* BLACKBOARDS_HPP */

