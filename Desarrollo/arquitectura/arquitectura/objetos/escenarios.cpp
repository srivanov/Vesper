
#include "escenarios.hpp"

escenarios::escenarios(){
	component* aux = new class render();
	this->insertComponent((char*)"render", aux);
	aux = new physics();
    this->insertComponent((char*)"physics", aux);
	
	std::map<char*,component*>::iterator iter = this->getIteradorBegin();
	while(iter != this->getIteradorEnd()){
		iter->second->setFather(this);
		iter++;
	}
	
	mapa_nivel = NULL;
	cargador = new cargarMapa();
}

escenarios::~escenarios(){
    
}

bool escenarios::cargarNivel(int numero){
	char* ruta = new char[30];
	char* num;
	sprintf(num, "%d", numero);
	strcat(ruta, "../../../arquitectura/tiled/mapa");
	strcat(ruta, num);
	strcat(ruta, ".tmx");
//	printf("%s\n", ruta);
	if(!cargador->leerMapa(ruta))
		printf("Ha habido un problema al leer el mapa del fichero. Comprueba la ruta y el acceso.\n");
	ancho = cargador->getWidth();
	alto = cargador->getHeight();
	if(ancho == 0 || alto == 0)
		return false;
	else{
		mapa_nivel = cargador->getMatriz();
		return true;
	}
}

int escenarios::getAncho(){
	return ancho;
}

int escenarios::getAlto(){
	return alto;
}

int*** escenarios::getMapa(){
	return mapa_nivel;
}
