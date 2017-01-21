
#include "armas.hpp"

armas::armas(){

	aux = new pistola(8, 2.0f, 2.0f);
	interface.insert(interface.end(), aux);
	
	aux = new escopeta(10, 0.2f, 4.0f);
	interface.insert(interface.end(), aux);
	
	aux = new lanzaCaramelos(30, 3.0f, 4.0f);
	interface.insert(interface.end(), aux);
	
	aux = new piedra(5, 5.0f, 4.0f);
	interface.insert(interface.end(), aux);
	
	aux = new globoAgua(3, 2.5f, 4.0f);
	interface.insert(interface.end(), aux);
	
	aux = new chicle(3, 2.5f, 4.0f);
	interface.insert(interface.end(), aux);
	
	aux = new bombaHumo(3, 2.5f, 4.0f);
	interface.insert(interface.end(), aux);
	
	aux = new martilloDeJuguete(10, 0.2f, 4.0f);
	interface.insert(interface.end(), aux);
	
	seleccionada = interface.begin();
}

//TO DO: revisar destructor y corregir
armas::~armas(){
	aux = NULL;
    delete aux;
	seleccionada = interface.begin();
	while(seleccionada != interface.end()){
        delete (*seleccionada);
	}
	interface.clear();
}

void armas::update(){
	
}

void armas::shoot(){
//	Game::Instance()->insertBala();
	aux = *seleccionada;
	aux->atacar();
}

void armas::changeGun(){
	if(seleccionada == interface.end().operator--())
		seleccionada = interface.begin();
	else
		seleccionada++;
}

