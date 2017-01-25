
#include "habilidadEspecial.hpp"

habilidadEspecial::habilidadEspecial() : numMonedas(3){
    actual = 0;
    numUsos = 0;
}

habilidadEspecial::~habilidadEspecial(){
    
}

void habilidadEspecial::update(){
	
}

void habilidadEspecial::aumentarMoneda(){
    actual++;
    if(actual == numMonedas){
        numUsos++;
        resetear();
    }
}

void habilidadEspecial::resetear(){
    actual = 0;
}
