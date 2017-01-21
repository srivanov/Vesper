
#include "component.hpp"
//#include "GameObject.hpp"


component::component(){
	
}

void component::setFather(GameObject *p){
	padre = p;
}

GameObject* component::getFather(){
	return padre;
}

