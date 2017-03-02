
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
    
    interface.push_back(new martilloDeJuguete(10, 0.2f, 4.0f));
    interface.push_back(new pistola(8, 2.0f, 2.0f));
	
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
	//TO DO: Hacer la gestion de las balas aqui y en la clase bala
}

void armas::shoot(){
//	Game::Instance()->insertBala();
    if(interface.size() > 0)
		(*seleccionada)->atacar();
}

void armas::changeGun(){
	if(seleccionada == interface.end().operator--())
		seleccionada = interface.begin();
	else
		seleccionada++;
}

void armas::insertarArma(int a){
    armaInterface* aux = *seleccionada;
    if(a < 1 || a > 9){
    	
    }else if(a == 1){
        
    }else if(a == 2){
        interface.push_back(new escopeta(10, 0.2f, 4.0f));
    }else if(a == 3){
        interface.push_back(new lanzaCaramelos(30, 3.0f, 4.0f));
    }else if(a == 4){
        interface.push_back(new piedra(5, 5.0f, 4.0f));
    }else if(a == 5){
        interface.push_back(new globoAgua(3, 2.5f, 4.0f));
    }else if(a == 6){
        interface.push_back(new chicle(3, 2.5f, 4.0f));
    }else if(a == 7){
        interface.push_back(new bombaHumo(3, 2.5f, 4.0f));
    }else if(a == 8){
        
    }else if(a == 9){
        interface.push_back(new pala(10, 0.2f, 4.0f));
    }
    bool busca = true;
    seleccionada = interface.begin();
    while(seleccionada != interface.end() && busca){
        if((*seleccionada) == aux)
            busca = false;
        else
        	++seleccionada;
    }
}

void armas::eliminarArma(std::vector<armaInterface *>::iterator iter){
    interface.erase(iter);
}

armaInterface* armas::getArmaActual(){
    return *seleccionada;
}


