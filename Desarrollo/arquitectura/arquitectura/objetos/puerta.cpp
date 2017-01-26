
#include "puerta.hpp"

puerta::puerta(){
	component* aux = new class render();
	this->insertComponent((char*)"render", aux);
	aux = new transform3D();
    this->insertComponent((char*)"transform3D", aux);
	aux = new conPuzzle();
    this->insertComponent((char*)"conPuzzle", aux);
	aux = new bloqueada();
    this->insertComponent((char*)"bloqueada", aux);
	aux = new blindada();
    this->insertComponent((char*)"blindada", aux);
	aux = new conLlave();
    this->insertComponent((char*)"conLlave", aux);
	aux = new destructiva();
    this->insertComponent((char*)"destructiva", aux);
	aux = new conAlarma();
    this->insertComponent((char*)"conAlarma", aux);
	aux = new chirriante();
    this->insertComponent((char*)"chirriante", aux);
	
    muero = false;
	aux = NULL;
	setType(tPUERTA);
}

puerta::~puerta(){
    
}

void puerta::contacto(GameObject *g){
    if(*g->getType() == tPLAYER){
        muero = true;
    }
}

bool const* puerta::getmuero(){
    return &muero;
}

void puerta::contactoEnd(GameObject *g){
    
}
