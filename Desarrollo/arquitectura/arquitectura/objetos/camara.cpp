
#include "camara.hpp"

camara::camara(){
	component* aux = new class render();
	renderizador = (class render*)aux;
	this->insertComponent((char*)"render", aux);
	aux = new transform3D();
    this->insertComponent((char*)"transform3D", aux);
	aux = new physics();
    this->insertComponent((char*)"physics", aux);
	aux = new IACamara();
    this->insertComponent((char*)"IACamara", aux);
}

camara::~camara(){
    
}

void camara::addCamara(float* p, float* l){
	renderizador->addCamera(p, l);
}
