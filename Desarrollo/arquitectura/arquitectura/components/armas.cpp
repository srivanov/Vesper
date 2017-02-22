
#include "armas.hpp"
#include "../objetos/GameObject.hpp"

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
    
    interface.push_back(new gun(10, 0.2f, 4.0f, 2, 6, tMARTILLO));
    interface.push_back(new gun(8, 2.0f, 2.0f, 1, 6, tPISTOLA));
	
	seleccionada = interface.begin();
    
}

//TO DO: revisar destructor y corregir
armas::~armas(){
	seleccionada = interface.begin();
	while(seleccionada != interface.end()){
        delete (*seleccionada);
		seleccionada++;
	}
	interface.clear();
}

void armas::update(){
	//TO DO: Hacer la gestion de las balas aqui y en la clase bala
    (*seleccionada)->update();
}

void armas::render(){
    (*seleccionada)->render();
}

void armas::shoot(){
//	Game::Instance()->insertBala();
    if(interface.size() > 0)
        (*seleccionada)->atacar(*getFather()->getPosicion(), *getFather()->getDirDisparo());
    //pasarle a atacar dos Dvector que seran la posicion y la direccion de disparo
}

void armas::changeGun(){
	if(seleccionada == interface.end().operator--())
		seleccionada = interface.begin();
	else
		seleccionada++;
}

void armas::insertarArma(int a){
    gun* aux = *seleccionada;
    if(a < 1 || a > 9){
    	
    }else if(a == 1){
    	printf("pistola de agua");
    }else if(a == 2){
        interface.push_back(new gun(10, 0.2f, 4.0f, 1, 2, tESCOPETAc));
        printf("escopeta");
    }else if(a == 3){
        interface.push_back(new gun(30, 3.0f, 4.0f, 5, 6, tLANZACARAMELOSc));
        printf("lanzacaramelos");
    }else if(a == 4){
        interface.push_back(new gun(5, 5.0f, 4.0f, 2, 6, tPIEDRAc));
        printf("piedra");
    }else if(a == 5){
        interface.push_back(new gun(3, 2.5f, 4.0f, 1, 6, tGLOBOAGUAc));
        printf("globoagua");
    }else if(a == 6){
        interface.push_back(new gun(3, 2.5f, 4.0f, 1, 6, tCHICLEc));
        printf("chicle");
    }else if(a == 7){
        interface.push_back(new gun(3, 2.5f, 4.0f, 1, 6, tBOMBAHUMOc));
        printf("bombahumo");
    }else if(a == 8){
        printf("martillo");
    }else if(a == 9){
        interface.push_back(new gun(10, 0.2f, 4.0f, 1, 6, tPALAc));
        printf("pala");
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

void armas::eliminarArma(std::vector<gun *>::iterator iter){
    interface.erase(iter);
}

gun* armas::getArmaActual(){
    return *seleccionada;
}


