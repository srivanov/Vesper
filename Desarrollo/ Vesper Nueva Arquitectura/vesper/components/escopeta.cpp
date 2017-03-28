
#include "escopeta.hpp"
#include "../Game.hpp"

escopeta::escopeta(unsigned int pMunicion, float pAlcance, float pTiempo_recarga){
	cadencia = 1;
	alcance = pAlcance;
	municion = pMunicion;
	tiempo_vida = alcance/3.0f;
	tiempo_recarga = pTiempo_recarga;
	tiempo = clock();
	cargador = 2;
    tipo = tESCOPETA;
}

escopeta::~escopeta(){
	
}

void escopeta::update(){
	
}

void escopeta::atacar(){
	if(municion > 0){
		if(cargador > 0 && 2000.0 * (clock()-tiempo) / CLOCKS_PER_SEC >= (1000.0 / cadencia)){
			printf("ESCOPETA ");
			Game::Instance()->insertBala(tiempo_vida);
			municion--;
			cargador--;
			tiempo = clock();
		}else{
			
			if(2000.0 * (clock()-tiempo) / CLOCKS_PER_SEC >= (1000.0 * tiempo_recarga)){
				cargador = 2;
			}
		}
	}
}

unsigned int escopeta::getMunicion(){
	return 1;
}

void escopeta::setMunicion(unsigned int n){
	municion = n;
}

void escopeta::destructor(){
	this->~escopeta();
}

typeArma const* escopeta::getType(){
    return &tipo;
}
