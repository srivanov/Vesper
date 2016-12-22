
#include "component.hpp"
//#include "GameObject.hpp"


component::component(){
	
}

void component::setFather(GameObject *p){
	padre = p;
}

component::~component(){

}

GameObject* component::getFather(){
	return padre;
}
