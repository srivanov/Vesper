
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
    k = 0;
    posi = new dvector3D();
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
    delete posi;
}

void enemigos::update(){
	GameObject::update();
    if(k%600){
        hambre++;
//        std::cout << hambre << std::endl;
        k = 0;
    }
    k++;
	posi->x = getPosicion()[0]; posi->y = getPosicion()[1]; posi->z = getPosicion()[2];
	
	if(!NPC_library::instance()->ExistMyBook(&ID))
		NPC_library::instance()->AddBook(&ID, salud, hambre, sed,estado, posi);
	else
		NPC_library::instance()->updateMyBook(&ID, salud, hambre, sed, posi);
    STD->run(ID);
    if(NPC_library::instance()->getMyBook(&ID)->getVMovement()!=NULL){
    float x = NPC_library::instance()->getMyBook(&ID)->getVMovement()->x;
    float y = NPC_library::instance()->getMyBook(&ID)->getVMovement()->y;
    float z = NPC_library::instance()->getMyBook(&ID)->getVMovement()->z;
        this->mover(new float[3]{x,y,z});
    }
    
	
}
