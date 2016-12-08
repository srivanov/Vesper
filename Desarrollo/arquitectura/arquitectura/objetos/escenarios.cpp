
#include "escenarios.hpp"

escenarios::escenarios(){
	component* aux = new class render();
	this->insertComponent((char*)"render", aux);
	aux = new physics();
    this->insertComponent((char*)"physics", aux);
	
}

escenarios::~escenarios(){
    
}
