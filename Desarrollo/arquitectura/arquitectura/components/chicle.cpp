
#include "chicle.hpp"
#include "../Game.hpp"

chicle::chicle(unsigned int pMunicion, float pAlcance, float pTiempo_recarga){
	cadencia = 1;
	alcance = pAlcance;
	municion = pMunicion;
	tiempo_vida = alcance/3.0f;
	tiempo_recarga = pTiempo_recarga;
	tiempo = clock();
	cargador = 6;
}

chicle::~chicle(){
	
}

void chicle::update(){
	
}

void chicle::atacar(){
	if(municion > 0){
		if(cargador > 0 && 2000.0 * (clock()-tiempo) / CLOCKS_PER_SEC >= (1000.0 / cadencia)){
			printf("CHICLE ");
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

unsigned int chicle::getMunicion(){
	return 1;
}

void chicle::setMunicion(unsigned int n){
	municion = n;
}

void chicle::destructor(){
	this->~chicle();
}
