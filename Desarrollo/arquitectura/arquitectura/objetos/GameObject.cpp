//
//  GameObject.cpp
//  arquitectura
//
//  Created by Nerea Castellanos Rodríguez on 29/11/16.
//  Copyright © 2016 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "GameObject.hpp"
#include "component.hpp"


GameObject::GameObject(){
    renderizable = false;
    posicion = new float[3]{0,0,0};
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

component* GameObject::findComponent(char *nombre){
    std::map<char*,component>::iterator iter = components.find(nombre);
    if(iter->first != NULL)
		return &iter->second;
    return NULL;
}

bool GameObject::getRenderizable(){
    return renderizable;
}

void GameObject::setRenderizable(bool r){
    renderizable = r;
}

float* GameObject::getPosicion(){
    return posicion;
}

void GameObject::setPosicion(float* p3D){
    if(p3D != NULL){
        posicion[0] = p3D[0];
        posicion[1] = p3D[1];
        posicion[2] = p3D[2];
    }
}

void GameObject::render(){
    if(renderizable){
        
    }
}

void GameObject::update(){
    
}

void GameObject::addNodo(char* filename){
    class render* ren = (class render*)findComponent("render");
    if(ren != NULL)
        ren->setNode(filename);
}






