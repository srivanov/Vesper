
#include "habilidadEspecial.hpp"
#include "../objetos/player.hpp"

habilidadEspecial::habilidadEspecial() : numMonedas(3){
    actual = 0;
    numUsos = 0;
	activada = false;
	//TO DO: cambiar duracion acorde al DocEspecificacion
	duracion = 3;
	tipo = NO_TYPE;
}

habilidadEspecial::~habilidadEspecial(){
    
}

void habilidadEspecial::update(){
	if(activada){
		if(2000.0 * (clock()-tiempo) / CLOCKS_PER_SEC >= (1000.0 * duracion)){
			if(tipo == tHabINVISIBLE){
				((player*)getFather())->setVelocidad(1);
				printf(" desactivada\n");
				activada = false;
			}
		}
	}
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

void habilidadEspecial::activar(){
	activada = true;
	tiempo = clock();
	((player*)getFather())->setVelocidad(2);
}

bool const* habilidadEspecial::estaActivada(){
	return &this->activada;
}

bool habilidadEspecial::puedoUsar(){
	if(numUsos>0 && !activada)
		return true;
	return false;
}

void habilidadEspecial::setTipo(tipoHab t){
	tipo = t;
}

