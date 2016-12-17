
#include "component.hpp"
//#include "GameObject.hpp"


component::component(){
	
}

void component::setFather(GameObject *p){
	padre = p;
}

component::~component(){
	//delete padre;
	padre = NULL;
}

GameObject* component::getFather(){
	return padre;
}

void component::update(){
	printf("MAL\n");
}
