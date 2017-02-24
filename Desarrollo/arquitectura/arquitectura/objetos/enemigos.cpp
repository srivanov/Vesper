
#include "enemigos.hpp"
#include "BlackBoards.hpp"
#include "trigger_system.hpp"

enemigos::enemigos(){
	setType(tENEMIGOS);
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
	
	aux = NULL;
	
    muero = false;
    k = 0;
	salud = 100;
	srand(time(NULL));
	sed = rand()%20 + 1;
	hambre = rand()%20 + 1;
    estado = 0;
    STD = new estados();
	trigger_system::_instance()->subs(this);
}

enemigos::~enemigos(){
	if(NPC_library::instance()->ExistMyBook(&ID))
		NPC_library::instance()->RemoveBook(&ID);
    delete STD;
}

void enemigos::notify(dvector3D& position, int type){
	book->notify(position, type);
}
bool enemigos::EventUsed(int type){return book->EventUsed(type);}
void enemigos::update(){
	// CODIGO GUARRO
	if(k%30==0){
		hambre++;
//		std::cout << hambre << std::endl;
//		std::cout << getPosicion()->x << "|" << getPosicion()->y << std::endl;
		k = 0;
	}
	k++;
	// FIN CODIGO GUARRO
	
	if(!NPC_library::instance()->ExistMyBook(&ID)){
		NPC_library::instance()->AddBook(&ID, salud, hambre, sed,estado, getPosicion());
		book = NPC_library::instance()->getMyBook(&ID);
		dvector3D yi = dvector3D(10,10,0);
		this->notify(yi, 99);
	}
	
	
	STD->run(ID);
	this->mover(*book->getVMovement());
	this->rotarConRaton(*getPosicion() + *book->getVMovement());
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
