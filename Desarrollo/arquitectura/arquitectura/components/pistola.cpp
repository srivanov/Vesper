
#include "pistola.hpp"
#include "../Game.hpp"

pistola::pistola(unsigned int pMunicion, float pAlcance, float pTiempo_recarga){
	cadencia = 1;
	alcance = pAlcance;
	municion = pMunicion;
	tiempo_vida = alcance/3.0f;
	tiempo_recarga = pTiempo_recarga;
	tiempo = clock();
	cargador = 6;
}

pistola::~pistola(){
	
}

void pistola::update(){
	
}

void pistola::atacar(){
	if(municion > 0){
		if(cargador > 0 && 2000.0 * (clock()-tiempo) / CLOCKS_PER_SEC >= (1000.0 / cadencia)){
			printf("PISTOLA ");
			Game::Instance()->insertBala(tiempo_vida);
			municion--;
			cargador--;
			tiempo = clock();
		}else{
			
			if(2000.0 * (clock()-tiempo) / CLOCKS_PER_SEC >= (1000.0 * tiempo_recarga)){
				cargador = 6;
			}
		}
	}
}

unsigned int pistola::getMunicion(){
	return 1;
}

void pistola::setMunicion(unsigned int n){
	municion = n;
}

void pistola::destructor(){
	this->~pistola();
}
