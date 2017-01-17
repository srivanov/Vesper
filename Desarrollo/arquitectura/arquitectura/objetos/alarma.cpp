
#include "alarma.hpp"
#include "trigger_system.hpp"
#include "BlackBoards.hpp"

#define RADIOALARMA 40.f
#define TIEMPOALARMA 20.f

alarma::alarma(int &ID){
    this->activado = false;
    this->ID = ID;
    this->rota = false;
	component* aux = new class render();
	this->insertComponent((char*)"render", aux);
	aux = new transform3D();
	this->insertComponent((char*)"transform3D", aux);
	aux = new physics();
	this->insertComponent((char*)"physics", aux);
    
    
    std::map<char*,component*>::iterator iter = this->getIteradorBegin();
    while(iter != this->getIteradorEnd()){
        iter->second->setFather(this);
        iter++;
    }
    setRenderizable(true);
	
	physics* fisica = (physics*)findComponent("physics");
	fisica->crearBodyEstatico(new float[2]{1,1}, new float[2]{0,0}, 90.f);
	
    _time = 0;
    posi = new dvector3D();
    NPCKnows = false;
    aux = NULL;
    delete aux;
}

alarma::~alarma(){
    delete posi;
}
void alarma::gestorTiempo(){
    if(time(NULL)>_time){
        activado = false;
    }
}
void alarma::update(){
	GameObject::update();
//    TypeRecords alarma = R_ALARMA;
//    posi->x = getPosicion()[0]; posi->y = getPosicion()[1]; posi->z = getPosicion()[2];
//    gestorTiempo();
//    if(World_BlackBoard::instance()->hasAnswer(alarma, &ID)){
//        if (World_BlackBoard::instance()->getAnswer(alarma, &ID)->_idResponse<0) {rota=true;}
//        else if(rota){NPCKnows=true;}
//        else if(!activado){
//            World_BlackBoard::instance()->removeRecord(alarma, &ID);
//            _time = time(NULL)+TIEMPOALARMA;
//            trigger_system::_instance()->add_trigger(E_alarma, &ID, posi, RADIOALARMA, TIEMPOALARMA);
//            this->activado = true;
//        }
//    }
//    else if(World_BlackBoard::instance()->countType(alarma)>0 && !NPCKnows){
//        World_BlackBoard::instance()->AnswerRecord(alarma, &ID, posi);
//    }
}
