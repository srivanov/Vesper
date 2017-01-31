
#include "BlackBoards.hpp"
#include <math.h>

float World_BlackBoard::absolute(float p){
    float aux = 0;
    if(p<0) aux=-p;
    else aux = p;
    return aux;
}

record::record(dvector3D* info){
    _info = info;
    answer = false;
    _idResponse = NULL;
    _answerInfo = NULL;
}

record::~record(){
    _info = NULL;
    delete _info;
    _idResponse = NULL;
    delete _idResponse;
    _answerInfo = NULL;
    delete _answerInfo;
}

World_BlackBoard::World_BlackBoard(){}

World_BlackBoard::~World_BlackBoard(){
    for(it = _map.begin();it!=_map.end();it++){
        delete it->second;
    }
    _map.clear();
}

World_BlackBoard * World_BlackBoard::_blackboard = 0;

World_BlackBoard * World_BlackBoard::instance(){
    if(_blackboard==0) _blackboard = new World_BlackBoard;
    return _blackboard;
}

void World_BlackBoard::addRecord(TypeRecords& type, int& id, dvector3D * info){
    std::string key = std::to_string(id)+"-"+std::to_string(type);
    record * _record = new record(info);
    _map.insert(std::pair<std::string , record *> (key,_record));
    _record = NULL; delete _record;
}

void World_BlackBoard::AnswerRecord(TypeRecords& type, int& id, dvector3D* info){
    it = _map.begin();
    std::string Stype = std::to_string(type);
    while (it!=_map.end()) {
        std::string TypeR = it->first.substr(it->first.find("-"));
        TypeR.erase(TypeR.begin());
        if(TypeR==Stype){
            if(it->second->isAnswer() && regulator(info)){
                it->second->_answerInfo = info;
                it->second->_idResponse = &id;
            }
            else if(!it->second->isAnswer()){
                it->second->_answerInfo = info;
                it->second->_idResponse = &id;
                it->second->addAnswer();
            }
        }
        it++;
    }
}

bool World_BlackBoard::regulator(dvector3D* info) {
    float targetX = it->second->_info->x, targetY = it->second->_info->y;
    float Answer1X = it->second->_answerInfo->x, Answer1Y = it->second->_answerInfo->y;
    float Answer2X = info->x, Answer2Y = info->y;
    float dist1, dist2;
    dist1 = absolute((targetX-Answer1X)+(targetY-Answer1Y));
    dist2 = absolute((targetX-Answer2X)+(targetY-Answer2Y));
    if(dist1<dist2) return false;
    return true;
}

unsigned long World_BlackBoard::countType(TypeRecords& type) {
    unsigned long count = 0;
    std::string Stype = std::to_string(type);
    for(it = _map.begin();it!=_map.end();it++){
        std::string TypeR = it->first.substr(it->first.find("-"));
        TypeR.erase(TypeR.begin());
        if(TypeR==Stype) count++;
    }
    return count;
}

bool World_BlackBoard::hasAnswer(TypeRecords& type, int& id) {
    std::string Key = std::to_string(id)+"-"+std::to_string(type);
    it = _map.find(Key);
    if(it!=_map.end() && it->second->isAnswer()){
        return true;
    }
    return false;
}

record * World_BlackBoard::getAnswer(TypeRecords& type, int& id) {
    std::string Key = std::to_string(id)+"-"+std::to_string(type);
    it = _map.find(Key);
    return it->second;
}

void World_BlackBoard::CleanByID(int& id){
    std::string clean = std::to_string(id)+"-";
    it = _map.begin();
    for (int i=0; i<R_Ntipos; i++) {
        std::string value = clean+std::to_string(i);
        it = _map.find(value);
        if(it!=_map.end()){
            delete it->second;
            _map.erase(it);
        }
    }
}

void World_BlackBoard::removeRecord(TypeRecords& type, int& id){
    std::string Key = std::to_string(id)+"-"+std::to_string(type);
    it = _map.find(Key);
    if(it!=_map.end()){
        delete it->second;
        _map.erase(it);
    }
    return;
}

bool World_BlackBoard::existRecord(TypeRecords& type, int& id){
    std::string Key = std::to_string(id)+"-"+std::to_string(type);
    it = _map.find(Key);
    if(it!=_map.end()){
        return true;
    }
    return false;
}

/* PERSONAL BLACKBOARD AND LIBRARY*/


void Personal_BlackBoard::EventPosObjetivo(int type){
    for (int i=0; i<eventos.size(); i++) {
        if (eventos[i]->_type==type) {
            _posObjetivo = &eventos[i]->_position;
        }
    }
}

NPC_library * NPC_library::_library = 0;

NPC_library * NPC_library::instance(){
    if(_library==0) _library = new NPC_library;
    return _library;
}

bool NPC_library::ExistMyBook(int* id){
    it = _values.find(id);
    if(it!=_values.end()) return true;
    return false;
}

void NPC_library::AddBook(int* id, unsigned int& life, unsigned int& hungry, unsigned int& thirst,unsigned int& state, dvector3D* position){
    it = _values.find(id);
    if(it!=_values.end()) return;
    Personal_BlackBoard * _book = new Personal_BlackBoard(life,hungry,thirst,state,position);
    _values.insert(std::pair<int *,Personal_BlackBoard*>(id,_book));
}

void NPC_library::RemoveBook(int* id){
    it = _values.find(id);
    if(it==_values.end()) return;
    delete it->second;
    _values.erase(it);
}

void NPC_library::updateMyBook(int* id, unsigned int& life, unsigned int& hungry, unsigned int& thirst, unsigned int& state, dvector3D* position){
    it = _values.find(id);
    if(it==_values.end()) return;
    it->second->update(life,hungry,thirst,state,position);
}

Personal_BlackBoard * NPC_library::getMyBook(int* id){
    it = _values.find(id);
    if(it==_values.end()) return NULL;
    return it->second;
}
void Personal_BlackBoard::setThirst(int thirst){*_thirst-=thirst;}
void Personal_BlackBoard::setLife(int life){*_life+=life;}
void Personal_BlackBoard::setHungry(int hungry){*_hungry-=hungry;}
void Personal_BlackBoard::setPosObjetivo(dvector3D * position){_posObjetivo = position;}
Personal_BlackBoard::Personal_BlackBoard(unsigned int& life, unsigned int& hungry, unsigned int& thirst, unsigned int& state, dvector3D* position) :
_life(&life), _hungry(&hungry), _thirst(&thirst), _position(position), _state(&state){
    _posObjetivo = new dvector3D(2,2,0);_Vmov= new dvector3D(0,0,0);
}

Personal_BlackBoard::~Personal_BlackBoard(){
    _position=NULL;delete _position;
    _posObjetivo=NULL;delete _posObjetivo;
    _Vmov=NULL; delete _Vmov;
    _life=NULL; delete _life;
    _hungry=NULL; delete _hungry;
    _thirst=NULL; delete _thirst;
    _state=NULL; delete _state;
}

void Personal_BlackBoard::update(unsigned int& life, unsigned int& hungry, unsigned int& thirst, unsigned int& state, dvector3D* position){
    _life = &life; _hungry = &hungry; _thirst = &thirst; _position = position;
}
void Personal_BlackBoard::setVMovement(dvector3D *Vmov){_Vmov=Vmov;}
void Personal_BlackBoard::notify(dvector3D& position, int type){
eventos.push_back(new Events(position,type));
}
bool Personal_BlackBoard::EventUsed(int type){
    for (int i=0; i<eventos.size(); i++)
        if(eventos[i]->_type==type) return true;
    return false;
}

float Personal_BlackBoard::CalcularDistancia(dvector3D a, dvector3D b){
    float x = fabs(a.x-b.x);
    float y = fabs(a.y-b.y);
    return x+y;
}

float Personal_BlackBoard::absolute(float p){
    float aux = 0;
    if(p<0) aux=-p;
    else aux = p;
    return aux;
}

void Personal_BlackBoard::updateEvent(){
    for (int i=0; i<eventos.size(); i++){
        if(eventos[i]->_type>98)
            continue;
        if(CalcularDistancia(eventos[i]->_position, *_position)<0.5){
            delete eventos[i];
            eventos.erase(eventos.begin()+i);
        }
    }
}

NPC_library::NPC_library(){}
NPC_library::~NPC_library(){
    for(it = _values.begin();it!=_values.end();it++){
        delete it->second;
        delete it->first;
    }_values.clear();
}
