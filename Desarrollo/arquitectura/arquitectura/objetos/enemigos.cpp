
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
	fisica->crearBodyDinamico(new float[2]{1,1}, new float[2]{0,0});
	
	aux = NULL;
	delete aux;
	
	salud = 100;
	srand(time(NULL));
	sed = rand()%20 + 1;
	hambre = rand()%20 + 1;
}

enemigos::~enemigos(){
	if(NPC_library::instance()->ExistMyBook(&ID))
		NPC_library::instance()->RemoveBook(&ID);
}

void enemigos::update(){
	dvector3D *posi = new dvector3D(getPosicion()[0], getPosicion()[1], getPosicion()[2]);
	
	if(!NPC_library::instance()->ExistMyBook(&ID))
		NPC_library::instance()->AddBook(&ID, salud, hambre, sed, posi);
	else
		NPC_library::instance()->updateMyBook(&ID, salud, hambre, sed, posi);
	
	GameObject::update();
}
