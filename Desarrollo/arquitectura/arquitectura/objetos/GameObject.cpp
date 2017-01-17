
#include "GameObject.hpp"
#include "../components/component.hpp"


GameObject::GameObject(){
    renderizable = false;
    posicion = new float[3]{0,0,0};
	rotacion = new float[3]{0,0,0};
	anguloDisparo = new float[2]{0,0};
}

GameObject::~GameObject(){
	std::map<char*, component*>::iterator iter = components.begin();
	while (iter != components.end()) {
		delete iter->second;
		iter++;
	}
	components.clear();
	delete posicion;
    //delete rotacion;
	delete anguloDisparo;
	//TODO: borrar variables
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
    if(iter != components.end())
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
		transform3D* go = (transform3D*)this->findComponent("transform3D");
		if(go != NULL)
			go->setPosition(posicion);
		class render* ren = (class render*)findComponent("render");
		if(ren != NULL)
			ren->setNodePosition(posicion);
    }
}

void GameObject::setRotacion(float rot){
	rotacion[2] = rot;
	transform3D* go = (transform3D*)this->findComponent("transform3D");
	if(go != NULL)
		go->rotar(rotacion[2]);
	
	class render* ren = (class render*)findComponent("render");
	if(ren != NULL)
		ren->setNodeRotation(rotacion);
	
//	go->update(NULL, NULL, rotacion, anguloDisparo, rot);
//	printf("%.2f %.2f\n", anguloDisparo[0], anguloDisparo[1]);
}

void GameObject::rotarConRaton(float* posRaton){
	transform3D* go = (transform3D*)this->findComponent("transform3D");
	if(go != NULL)
		rotacion[2] = go->rotarConRaton(posRaton);
	class render* ren = (class render*)findComponent("render");
	if(ren != NULL)
		ren->setNodeRotation(rotacion);
}

float* GameObject::getRotacion(){
	return rotacion;
}

void GameObject::mover(float *vel){
	if(vel != NULL){
        transform3D* go = (transform3D*)findComponent("transform3D");
		if(go != NULL)
			go->mover(vel);
//		class render* ren = (class render*)findComponent("render");
//		if(ren != NULL)
//			ren->setNodePosition(posicion);
	}
}

void GameObject::render(){
//    if(renderizable){
//        class render* ren = (class render*)findComponent("render");
//		if(ren != NULL)
//			ren->actualizarRender();
//    }
}

void GameObject::update(){
	std::map<char*, component*>::iterator iter = components.begin();
	while (iter != components.end()) {
		iter->second->update();
		iter++;
	}
	
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

void GameObject::setDirDisparo(float *dir){
	anguloDisparo[0] = dir[0];
	anguloDisparo[1] = dir[1];
}

