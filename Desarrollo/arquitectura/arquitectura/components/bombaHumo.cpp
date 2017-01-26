
#include "bombaHumo.hpp"
#include "../Game.hpp"

bombaHumo::bombaHumo(unsigned int pMunicion, float pAlcance, float pTiempo_recarga){
	cadencia = 1;
	alcance = pAlcance;
	municion = pMunicion;
	tiempo_vida = alcance/3.0f;
	tiempo_recarga = pTiempo_recarga;
	tiempo = clock();
	cargador = 6;
    tipo = tBOMBAHUMO;
}

bombaHumo::~bombaHumo(){
	
}

void bombaHumo::update(){
	
}

void bombaHumo::atacar(){
	if(municion > 0){
		if(cargador > 0 && 2000.0 * (clock()-tiempo) / CLOCKS_PER_SEC >= (1000.0 / cadencia)){
			printf("BOMBA DE HUMO ");
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

unsigned int bombaHumo::getMunicion(){
	return 1;
}

void bombaHumo::setMunicion(unsigned int n){
	municion = n;
}

void bombaHumo::destructor(){
	this->~bombaHumo();
}

typeArma const* bombaHumo::getType(){
    return &tipo;
}
