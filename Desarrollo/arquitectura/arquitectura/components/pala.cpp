
#include "pala.hpp"
#include "../Game.hpp"

pala::pala(unsigned int pMunicion, float pAlcance, float pTiempo_recarga){
        
    cadencia = 1;
    alcance = pAlcance;
    municion = pMunicion;
    tiempo_vida = alcance/3.0f;
    tiempo_recarga = pTiempo_recarga;
    tiempo = clock();
    cargador = 6;
}

pala::~pala(){
    
}

void pala::update(){
	
}

void pala::atacar(){
    if(cargador > 0 && 2000.0 * (clock()-tiempo) / CLOCKS_PER_SEC >= (1000.0 / cadencia)){
        printf("PALA ");
        Game::Instance()->insertBala(tiempo_vida);
        tiempo = clock();
    }
}

unsigned int pala::getMunicion(){
    return 1;
}

void pala::setMunicion(unsigned int n){
    municion = n;
}

void pala::destructor(){
    this->~pala();
}
