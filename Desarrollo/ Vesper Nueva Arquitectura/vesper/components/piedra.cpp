
#include "piedra.hpp"
#include "../Game.hpp"

piedra::piedra(unsigned int pMunicion, float pAlcance, float pTiempo_recarga){
	cadencia = 2;
	alcance = pAlcance;
	municion = pMunicion;
	tiempo_vida = alcance/3.0f;
	tiempo_recarga = pTiempo_recarga;
	tiempo = clock();
	cargador = 6;
    tipo = tPIEDRAc;
}

piedra::~piedra(){
	
}

void piedra::update(){
	
}

void piedra::atacar(){
	if(municion > 0){
		if(cargador > 0 && 2000.0 * (clock()-tiempo) / CLOCKS_PER_SEC >= (1000.0 / cadencia)){
			printf("PIEDRA ");
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

unsigned int piedra::getMunicion(){
	return 1;
}

void piedra::setMunicion(unsigned int n){
	municion = n;
}

void piedra::destructor(){
	this->~piedra();
}

typeArma const* piedra::getType(){
    return &tipo;
}
