
#include "enemigos.hpp"
#include "BlackBoards.hpp"
#include "trigger_system.hpp"

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
	hambre = rand()%30 + 1;
    estado = 0;
    STD = new estados();
    trigger_system::_instance()->subs(this);
    
    
}

enemigos::~enemigos(){
    book = NULL;
	if(NPC_library::instance()->ExistMyBook(&ID))
		NPC_library::instance()->RemoveBook(&ID);
    delete STD;
}

void enemigos::notify(dvector3D& position, int type){book->notify(position, type);}
bool enemigos::EventUsed(int type){return book->EventUsed(type);}
void enemigos::update(){
    // CODIGO GUARRO
    if(k%15==0){
        hambre++;
        std::cout << hambre << std::endl;
        std::cout << getPosicion()->x << "|" << getPosicion()->y << std::endl;
        k = 0;
    }
    k++;
    // FIN CODIGO GUARRO
    if(!NPC_library::instance()->ExistMyBook(&ID)){
        NPC_library::instance()->AddBook(&ID, salud, hambre, sed,estado, getPosicion());
        book = NPC_library::instance()->getMyBook(&ID);
    }
    
    
    STD->run(ID);
    
    this->mover(*book->getVMovement());
    
    dvector3D aux;
    aux = *getPosicion() + *book->getVMovement();
    this->rotarConRaton(aux);
    GameObject::update();
	
}
