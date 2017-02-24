
#include "alarma.hpp"
#include "trigger_system.hpp"
#include "BlackBoards.hpp"

#define RADIOALARMA 40.f
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
    TypeRecords alarma = R_ALARMA;
    gestorTiempo();
	if(World_BlackBoard::instance()->hasAnswer(alarma, ID)){
		if (World_BlackBoard::instance()->getAnswer(alarma, ID)->_idResponse<0) {rota=true;}
		else if(rota){NPCKnows=true;}
		else if(!activado){
			World_BlackBoard::instance()->removeRecord(alarma, ID);
			_time = time(NULL)+TIEMPOALARMA;
			trigger_system::_instance()->add_trigger(E_alarma, ID, *getPosicion(), RADIOALARMA, TIEMPOALARMA);
			this->activado = true;
		}
	}
	else if(World_BlackBoard::instance()->countType(alarma)>0 && !NPCKnows){
		World_BlackBoard::instance()->AnswerRecord(alarma, ID, getPosicion());
	}
}

void alarma::contacto(GameObject *g){
    if(*g->getType() == tPLAYER){
//        muero = true;
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
}

bool alarma::estaActivado(){
    return activado;
}

//TO DO: implementar en todos los objetos, hacerlo virtual
void alarma::muere(){
    muero = true;
}
