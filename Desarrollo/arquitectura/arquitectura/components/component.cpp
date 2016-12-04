//
//  component.cpp
//  arquitectura
//
//  Created by Stoycho Ivanov Atanasov on 29/11/16.
//  Copyright © 2016 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "component.hpp"
#include "GameObject.hpp"


component::component(){
	
}

void component::setFather(GameObject *p){
	padre = p;
}

component::~component(){

}
