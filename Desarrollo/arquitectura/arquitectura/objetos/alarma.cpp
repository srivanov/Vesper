
#include "alarma.hpp"

alarma::alarma(){
	component* aux = new class render();
	this->insertComponent((char*)"render", aux);
	aux = new transform3D();
	this->insertComponent((char*)"transform3D", aux);
	
}

alarma::~alarma(){
    
}
