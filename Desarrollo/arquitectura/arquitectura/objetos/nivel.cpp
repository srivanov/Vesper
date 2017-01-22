
#include "nivel.hpp"

nivel::nivel(){
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
	aux = NULL;
}

nivel::~nivel(){
	delete cargador;
}

bool nivel::cargarNivel(char* numero){
	char ruta[30] = "";
	
	strcat(ruta, "tiled/mapa");
	strcat(ruta, numero);
	strcat(ruta, ".tmx");
	printf("\n%s\n", ruta);
	if(!cargador->leerMapa(ruta))
		printf("Ha habido un problema al leer el mapa del fichero. Comprueba la ruta y el acceso.\n");
	ancho = cargador->getWidth();
	alto = cargador->getHeight();
	
	dvector3D pos(5,17,0);
	pala.addNodo("");
	pala.setTexture("3d/pala.jpg");
	pala.setPosicion(pos);
	
	if(ancho == 0 || alto == 0)
		return false;
	else{
		mapa_nivel = cargador->getMatriz();
		return true;
	}
}

int nivel::getAncho(){
	return ancho;
}

int nivel::getAlto(){
	return alto;
}

std::vector<int>* nivel::getMapa(){
	return mapa_nivel;
}

void nivel::dibujarMapa(){
	static_cast<class render*>(findComponent("render"))->dibujarMapa();
}

void nivel::update(){
	pala.update();
}

