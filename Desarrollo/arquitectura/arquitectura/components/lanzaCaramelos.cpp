

#include "lanzaCaramelos.hpp"
#include "../Game.hpp"

lanzaCaramelos::lanzaCaramelos(unsigned int pMunicion, float pAlcance, float pTiempo_recarga){
	cadencia = 5;
	alcance = pAlcance;
	municion = pMunicion;
	tiempo_vida = alcance/3.0f;
	tiempo_recarga = pTiempo_recarga;
	tiempo = clock();
	cargador = 6;
}

lanzaCaramelos::~lanzaCaramelos(){
	
}

void lanzaCaramelos::update(){
	
}

void lanzaCaramelos::atacar(){
	if(municion > 0){
		if(cargador > 0 && 2000.0 * (clock()-tiempo) / CLOCKS_PER_SEC >= (1000.0 / cadencia)){
			printf("CARAMELOS ");
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

unsigned int lanzaCaramelos::getMunicion(){
	return 1;
}

void lanzaCaramelos::setMunicion(unsigned int n){
	municion = n;
}

void lanzaCaramelos::destructor(){
	this->~lanzaCaramelos();
}
