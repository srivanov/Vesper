
#include "monedas.hpp"

monedas::monedas(){
	component* aux = new class render();
	this->insertComponent((char*)"render", aux);
	aux = new transform3D();
    this->insertComponent((char*)"transform3D", aux);
	aux = new physics();
	this->insertComponent((char*)"physics", aux);
}

monedas::~monedas(){
    
}
