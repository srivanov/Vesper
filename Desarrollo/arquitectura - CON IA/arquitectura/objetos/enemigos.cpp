
#include "enemigos.hpp"
#include "../Arquitectura IA/trigger_system.hpp"

enemigos::enemigos(){
	
	component* aux = new class render();
	this->insertComponent((char*)"render", aux);
	aux = new physics();
	this->insertComponent((char*)"physics", aux);
	aux = new transform3D();
    this->insertComponent((char*)"transform3D", aux);
	aux = new IAEnemigos();
    this->insertComponent((char*)"IAEnemigos", aux);
	aux = new ataque();
    this->insertComponent((char*)"ataque", aux);
	
	std::map<char*,component*>::iterator iter = this->getIteradorBegin();
	while(iter != this->getIteradorEnd()){
		iter->second->setFather(this);
		iter++;
	}
	setRenderizable(true);
	physics* fisica = (physics*)findComponent("physics");
    
    dvector3D dim(1,1,1);
    dvector3D pos(0,0,0);
    fisica->crearBodyDinamico(dim, pos);
	
	setType(tENEMIGOS);
	
    k = -1; // PROVISIONAL
    
    
    muero = false; // VARIABLE ARQUITECTURA
    
    
    
    
    
    tree = Behaviour_tree2::instancia()->ArbolPorDefecto();
}

enemigos::~enemigos(){
    delete tree;
    NpcLibrary::instancia()->remove_book(ID);
}

void enemigos::update(){
    if(k==-1){
        // PERSONAL BLACKBOARD
        book = NpcLibrary::instancia()->add_book(ID, getPosicion());
        //TRIGGER SYSTEM
        trigger_system::_instance()->subs(book);
        //TO DO: VIGILAR Y PATRULLAR
        dvector3D * yi = new dvector3D(10,10,0);
        int a = -1;
        book->notify(a,P_VIGILAR, yi);
    }
	// CODIGO GUARRO
    k++;
	if(k%30==0){
        //book->hambre++;
		cout << "HAMBRE : " << book->hambre << std::endl;
        //book->sed++;
        cout << "SED : " << book->sed << std::endl;
        k = 0;
	}
	// FIN CODIGO GUARRO
    
    
    if (book->Evento) {
        tree->reset();
        book->Evento = false;
    }
    book->updateBook();
    
    tree->run(ID);
    
	mover(*book->VectorMovimiento);
	rotarConRaton(*getPosicion() + *book->VectorMovimiento);
	GameObject::update();
    
    
    
}

void enemigos::contacto(GameObject *g){
    if(*g->getType() == tPLAYER){
//        muero = true;
    }
}

bool const* enemigos::getmuero(){
    return &muero;
}

void enemigos::contactoEnd(GameObject *g){
    
}
