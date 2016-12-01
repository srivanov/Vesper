//
//  GameObject.cpp
//  arquitectura
//
//  Created by Nerea Castellanos Rodríguez on 29/11/16.
//  Copyright © 2016 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "GameObject.hpp"



GameObject::GameObject(){
    
}

GameObject::~GameObject(){
    
}

void GameObject::insertComponent(char* nombre, component comp){
//    printf("%d\n", (int)components.size());
    components.insert(pair<char*, component>(nombre,comp));
//    printf("%d\n", (int)components.size());
}

void GameObject::eraseComponent(char* nombre){
    components.erase(nombre);
}

bool GameObject::findComponent(char *nombre){
    map<char*,component>::iterator iter = components.find(nombre);
    if(iter->first != NULL)
		return true;
    return false;
}

