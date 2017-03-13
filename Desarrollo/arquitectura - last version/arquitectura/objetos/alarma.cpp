
#include "alarma.hpp"
#include "../Arquitectura IA/trigger_system.hpp"

#define RADIOALARMA -1
#define TIEMPOALARMA 20.f

alarma::alarma(){
    this->activado = false;
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
    
    dvector3D dim(1,1,1);
    dvector3D pos(0,0,0);
    
	fisica->crearBodyEstatico(dim, pos, 90.f);
	
    muero = false;
    _time = 0;
    NPCKnows = false;
    aux = NULL;
	setType(tALARMA);
}

//TO DO: romper la alarma

alarma::~alarma(){
    
}

void alarma::gestorTiempo(){
    if(activado){
        if(2000.0 * (clock()-_time) / CLOCKS_PER_SEC >= (1000.0 * 3)){
            activado = false;
            printf("se ha desactivado");
            this->setTexture("3d/alarmita.jpg");
        }
    }
}

void alarma::update(){
	GameObject::update();
    gestorTiempo();
    
    
	if(LevelBlackBoard::instance()->exist_record(ID, P_ALARMA)){
        if (LevelBlackBoard::instance()->getRecord(ID, P_ALARMA)->romper) rota=true;
		else if(rota)NPCKnows=true;
		else if(estaActivado())
            activar();
			
	}
    if(!NPCKnows){
		LevelBlackBoard::instance()->AnswerRecord(P_ALARMA, ID, getPosicion());
	}
}

void alarma::contacto(GameObject *g){
	if(g != NULL){
		if(*g->getType() == tPLAYER){
//	        muero = true;
		}
	}
}

bool const* alarma::getmuero(){
    return &muero;
}

void alarma::contactoEnd(GameObject *g){
    
}

void alarma::activar(){
    activado = true;
    _time = clock();
    this->setTexture("3d/rojo.png");
    //_time = time(NULL)+TIEMPOALARMA;
    if(trigger_system::_instance()->ExistTrigger(P_ALARMA, ID))
        trigger_system::_instance()->add_trigger(P_ALARMA, ID,getPosicion(), RADIOALARMA, TIEMPOALARMA);
}

bool alarma::estaActivado(){
    return activado;
}

//TO DO: implementar en todos los objetos, hacerlo virtual
void alarma::muere(){
    muero = true;
}
