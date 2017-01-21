
#include "armas.hpp"

armas::armas(){

//	aux = new pistola(8, 2.0f, 2.0f);
//	interface.push_back(aux);
//	
//	aux = new escopeta(10, 0.2f, 4.0f);
//	interface.push_back(aux);
//	
//	aux = new lanzaCaramelos(30, 3.0f, 4.0f);
//	interface.push_back(aux);
//	
//	aux = new piedra(5, 5.0f, 4.0f);
//	interface.push_back(aux);
//	
//	aux = new globoAgua(3, 2.5f, 4.0f);
//	interface.push_back(aux);
//	
//	aux = new chicle(3, 2.5f, 4.0f);
//	interface.push_back(aux);
//	
//	aux = new bombaHumo(3, 2.5f, 4.0f);
//	interface.push_back(aux);
//	
//	aux = new martilloDeJuguete(10, 0.2f, 4.0f);
//	interface.push_back(aux);

	interface.push_back(new pistola(8, 2.0f, 2.0f));
	interface.push_back(new escopeta(10, 0.2f, 4.0f));
	interface.push_back(new lanzaCaramelos(30, 3.0f, 4.0f));
	interface.push_back(new piedra(5, 5.0f, 4.0f));
	interface.push_back(new globoAgua(3, 2.5f, 4.0f));
	interface.push_back(new chicle(3, 2.5f, 4.0f));
	interface.push_back(new bombaHumo(3, 2.5f, 4.0f));
	interface.push_back(new martilloDeJuguete(10, 0.2f, 4.0f));
	
	seleccionada = interface.begin();
}

//TO DO: revisar destructor y corregir
armas::~armas(){
	seleccionada = interface.begin();
	while(seleccionada != interface.end()){
        (*seleccionada)->destructor();
		seleccionada++;
	}
	interface.clear();
}

void armas::update(){
	
}

void armas::shoot(){
//	Game::Instance()->insertBala();
	(*seleccionada)->atacar();
}

void armas::changeGun(){
	if(seleccionada == interface.end().operator--())
		seleccionada = interface.begin();
	else
		seleccionada++;
}

