
#include "armas.hpp"
#include "../objetos/PhysicObjects/Actores/Player.hpp"

armas::armas(){

//	aux = new pistola(8, 2.0f, 2.0f);
//	interfaz.push_back(aux);
//	
//	aux = new escopeta(10, 0.2f, 4.0f);
//	interfaz.push_back(aux);
//	
//	aux = new lanzaCaramelos(30, 3.0f, 4.0f);
//	interfaz.push_back(aux);
//	
//	aux = new piedra(5, 5.0f, 4.0f);
//	interfaz.push_back(aux);
//	
//	aux = new globoAgua(3, 2.5f, 4.0f);
//	interfaz.push_back(aux);
//	
//	aux = new chicle(3, 2.5f, 4.0f);
//	interfaz.push_back(aux);
//	
//	aux = new bombaHumo(3, 2.5f, 4.0f);
//	interfaz.push_back(aux);
//	
//	aux = new martilloDeJuguete(10, 0.2f, 4.0f);
//	interfaz.push_back(aux);
    
    interfaz.push_back(new gun(tPISTOLA));
    interfaz.push_back(new gun(tMARTILLO));
    
	seleccionada = interfaz.begin();
    
}

//TO DO: revisar destructor y corregir
armas::~armas(){
	seleccionada = interfaz.begin();
	while(seleccionada != interfaz.end()){
        delete (*seleccionada);
		seleccionada++;
	}
	interfaz.clear();
}

void armas::update(){
	//TO DO: Hacer la gestion de las balas aqui y en la clase bala
//    (*seleccionada)->update();
    aux = interfaz.begin();
    while(aux != interfaz.end()){
        (*aux)->update();
        aux++;
    }
}

void armas::render(float &interpolation){
    (*seleccionada)->render(interpolation);
}

void armas::shoot(){
//	Game::Instance()->insertBala();
    if(interfaz.size() > 0){
        Player * p = static_cast<Player*>(getFather());
        (*seleccionada)->atacar(*p->getPosition(), *p->getDirDisparo());
    }
    
    //pasarle a atacar dos Dvector que seran la posicion y la direccion de disparo
}

void armas::changeGun(){
	if(seleccionada == interfaz.end().operator--())
		seleccionada = interfaz.begin();
	else
		seleccionada++;
}

void armas::insertarArma(int a){
    gun* aux = *seleccionada;
    
    interfaz.push_back(new gun((typeArma)a));
    
    bool busca = true;
    
    seleccionada = interfaz.begin();
    
    while(seleccionada != interfaz.end() && busca){
        if((*seleccionada) == aux)
            busca = false;
        else
        	++seleccionada;
    }
    
}

void armas::eliminarArma(std::vector<gun *>::iterator iter){
    interfaz.erase(iter);
}

typeArma armas::getArmaActual(){
    return (*seleccionada)->getType();
}


