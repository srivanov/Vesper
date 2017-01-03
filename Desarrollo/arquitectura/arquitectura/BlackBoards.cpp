
#include "BlackBoards.hpp"


Key::~Key(){_id=NULL; delete _id;}

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
        delete it->first;
        delete it->second;
    }
    _map.clear();
}

World_BlackBoard * World_BlackBoard::_blackboard = 0;

World_BlackBoard * World_BlackBoard::instance(){
    if(_blackboard==0) _blackboard = new World_BlackBoard;
    return _blackboard;
}

void World_BlackBoard::addRecord(TypeRecords& type, int * id, dvector3D * info){
    Key * _key = new Key(type,id);
    record * _record = new record(info);
    _map.insert(std::pair<Key* , record *> (_key,_record));
}

void World_BlackBoard::addRecord(TypeRecords& type, int* id, int* idTarget, dvector3D* info){
    Key * _aux = new Key(type,idTarget);
    unsigned long cont = _map.count(_aux);
    if(cont!=0){
        it = _map.find(_aux);
        if(it->second->isAnswer() && regulator(info)){
            it->second->_answerInfo = info;
            it->second->_idResponse = id;
        }else{
            it->second->_answerInfo = info;
            it->second->_idResponse = id;
            it->second->addAnswer();
        }
    }
    delete _aux;
}

bool World_BlackBoard::regulator(dvector3D* info) const{
    float targetX = it->second->_info->x, targetY = it->second->_info->y;
    float Answer1X = it->second->_answerInfo->x, Answer1Y = it->second->_answerInfo->y;
    float Answer2X = info->x, Answer2Y = info->y;
    float dist1, dist2;
	dist1 = abs((targetX-Answer1X)+(targetY-Answer1Y));
    dist2 = abs((targetX-Answer2X)+(targetY-Answer2Y));
    if(dist1>dist2) return false;
    return true;
}

unsigned long World_BlackBoard::countType(TypeRecords& type) {
    unsigned long count = 0;
    for(it = _map.begin();it!=_map.end();it++)
        if(it->first->_type==type) count++;
    return count;
}

bool World_BlackBoard::hasAnswer(TypeRecords& type, int* id) {
    Key * _aux = new Key(type,id);
    it = _map.find(_aux);
    delete _aux;
    if(it!=_map.end() && it->second->isAnswer()){
        return true;
    }
    return false;
}

record * World_BlackBoard::getAnswer(TypeRecords& type, int* id) {
    Key * _aux = new Key(type,id);
    it = _map.find(_aux);
    delete _aux;
    return it->second;
}

void World_BlackBoard::CleanByID(int* id){
    for(it = _map.begin();it!=_map.end();it++)
        if(it->first->_id==id){
            delete it->first;
            delete it->second;
            _map.erase(it);
        }
}

void World_BlackBoard::removeRecord(TypeRecords& type, int* id){
    Key * _aux = new Key(type,id);
    it = _map.find(_aux);
    delete _aux;
    if(it!=_map.end()){
        delete it->first;
        delete it->second;
        _map.erase(it);
    }
    return;
}

/* PERSONAL BLACKBOARD AND LIBRARY*/

Personal_BlackBoard::Personal_BlackBoard(unsigned int& life, unsigned int& hungry, unsigned int& thirst, dvector3D* position) :
_life(life), _hungry(hungry), _thirst(thirst), _position(position){}

Personal_BlackBoard::~Personal_BlackBoard(){_position=NULL;delete _position;}

void Personal_BlackBoard::update(unsigned int& life, unsigned int& hungry, unsigned int& thirst, dvector3D* position){
    _life = life; _hungry = hungry; _thirst = thirst; _position = position;
}

NPC_library::NPC_library(){}
NPC_library::~NPC_library(){
    for(it = _values.begin();it!=_values.end();it++){
        delete it->first;
        delete it->second;
    }
    _values.clear();
}

NPC_library * NPC_library::_library = 0;

NPC_library * NPC_library::instance(){
    if(_library==0) _library = new NPC_library;
    return _library;
}

bool NPC_library::ExistMyBook(int* id){
    it = _values.find(id);
    if(it!=_values.end())
        return true;
    return false;
}

void NPC_library::AddBook(int* id, unsigned int& life, unsigned int& hungry, unsigned int& thirst, dvector3D* position){
    it = _values.find(id);
    if(it!=_values.end())
        return;
    Personal_BlackBoard * _book = new Personal_BlackBoard(life,hungry,thirst,position);
    _values.insert(std::pair<int *,Personal_BlackBoard*>(id,_book));
}

void NPC_library::RemoveBook(int* id){
    it = _values.find(id);
    if(it==_values.end())
        return;
    delete it->first;
    delete it->second;
    _values.erase(it);
}

void NPC_library::updateMyBook(int* id, unsigned int& life, unsigned int& hungry, unsigned int& thirst, dvector3D* position){
    it = _values.find(id);
    if(it==_values.end())
        return;
    it->second->update(life,hungry,thirst,position);
}

Personal_BlackBoard * NPC_library::getMyBook(int* id){
    it = _values.find(id);
    if(it==_values.end())
        return NULL;
    return it->second;
}
