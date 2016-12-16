
#include "armas.hpp"

armas::armas(){

	interface = new pistola(8);
}

armas::~armas(){
	
}

void armas::atacar(){
//	Game::Instance()->insertBala();
	
	interface->atacar();
}

