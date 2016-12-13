
#include "GameObject.hpp"
#include "component.hpp"


GameObject::GameObject(){
    renderizable = false;
    posicion = new float[3]{0,0,0};
	rotacion = new float[2]{0,0};
	anguloDisparo = new float[2]{0,0};
}

GameObject::~GameObject(){
	components.clear();
}


void GameObject::insertComponent(char* nombre, component *comp){
//    printf("%d\n", (int)components.size());
    components.insert(pair<char*, component*>(nombre,comp));
//    printf("%d\n", (int)components.size());
}

void GameObject::eraseComponent(char* nombre){
    components.erase(nombre);
}

component* GameObject::findComponent(char *nombre){
    std::map<char*,component*>::iterator iter = components.find(nombre);
    if(iter->first != NULL)
		return iter->second;
    return NULL;
}

std::map<char*,component*>::iterator GameObject::getIteradorBegin(){
	return components.begin();
}

std::map<char*,component*>::iterator GameObject::getIteradorEnd(){
	return components.end();
}

void GameObject::clearComponents(){
	components.clear();
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

void GameObject::setRotacion(float* rot){
	physics* go = (physics*)this->findComponent("physics");
	go->update(NULL, NULL, rotacion, anguloDisparo, rot);
//	printf("%.2f %.2f\n", anguloDisparo[0], anguloDisparo[1]);
}

float* GameObject::getRotacion(){
	return rotacion;
}

void GameObject::mover(float *vel){
	if(vel != NULL){
        physics* go = (physics*)this->findComponent("physics");
        go->update(vel, posicion, NULL, anguloDisparo, NULL);
	}
}

void GameObject::render(){
    if(renderizable){
        class render* ren = (class render*)findComponent("render");
		if(ren != NULL)
			ren->actualizarRender();
    }
}

void GameObject::update(){
//	std::map<char*, component>::iterator iter = components.begin();
//	while (iter != components.end()) {
//		iter->second.update();
//		iter++;
//	}
    
//	physics* go = (physics*)this->findComponent("physics");
//    if(go != NULL)
//        go->update();
    
    
    
}

void GameObject::addNodo(char* filename){
    class render* ren = (class render*)findComponent("render");
	if(ren != NULL){
		ren->setNode(filename);
	}
}

void GameObject::setTexture(char* filename){
	class render* ren = (class render*)findComponent("render");
	if(ren != NULL){
		ren->setNodeTexture(filename);
	}
}


float* GameObject::getDirDisparo(){
	return anguloDisparo;
}
