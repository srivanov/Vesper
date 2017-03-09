
#include "martilloDeJuguete.hpp"
#include "../Game.hpp"

martilloDeJuguete::martilloDeJuguete(unsigned int pMunicion, float pAlcance, float pTiempo_recarga){
	cadencia = 2;
	alcance = pAlcance;
	municion = pMunicion;
	tiempo_vida = alcance/3.0f;
	tiempo_recarga = pTiempo_recarga;
	tiempo = clock();
	cargador = 6;
    tipo = tMARTILLO;
}

martilloDeJuguete::~martilloDeJuguete(){
	
}

void martilloDeJuguete::update(){
	
}

void martilloDeJuguete::atacar(){
	if(cargador > 0 && 2000.0 * (clock()-tiempo) / CLOCKS_PER_SEC >= (1000.0 / cadencia)){
		printf("MARTILLO ");
		Game::Instance()->insertBala(tiempo_vida);
		tiempo = clock();
	}
}

unsigned int martilloDeJuguete::getMunicion(){
	return 1;
}

void martilloDeJuguete::setMunicion(unsigned int n){
	municion = n;
}

void martilloDeJuguete::destructor(){
	this->~martilloDeJuguete();
}

typeArma const* martilloDeJuguete::getType(){
    return &tipo;
}
