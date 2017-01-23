
#include "enemigos.hpp"
#include "BlackBoards.hpp"

enemigos::enemigos(int& ID){
	this->ID = ID;
	
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
	setType(tENEMIGOS);
	
    k = 0;
	salud = 100;
	srand(time(NULL));
	sed = rand()%20 + 1;
	hambre = rand()%20 + 1;
    estado = 0;
    STD = new estados();
}

enemigos::~enemigos(){
	if(NPC_library::instance()->ExistMyBook(&ID))
		NPC_library::instance()->RemoveBook(&ID);
    delete STD;
}

void enemigos::update(){
	GameObject::update();
    if(k%600){
        hambre++;
//        std::cout << hambre << std::endl;
        k = 0;
    }
    k++;
	
	if(!NPC_library::instance()->ExistMyBook(&ID))
		NPC_library::instance()->AddBook(&ID, salud, hambre, sed,estado, getPosicion());
	else
		NPC_library::instance()->updateMyBook(&ID, salud, hambre, sed, getPosicion());
    STD->run(ID);
    if(NPC_library::instance()->getMyBook(&ID)->getVMovement()!=NULL){
        this->mover(*NPC_library::instance()->getMyBook(&ID)->getVMovement());
    }
    
	
}
