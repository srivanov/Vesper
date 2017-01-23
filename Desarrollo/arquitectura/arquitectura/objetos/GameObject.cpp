
#include "GameObject.hpp"
#include "../components/component.hpp"


GameObject::GameObject(){
    renderizable = false;
	tipo = NO_TYPE;
}

GameObject::~GameObject(){
	std::map<char*, component*>::iterator iter = components.begin();
	while (iter != components.end()) {
		delete iter->second;
		iter++;
	}
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

dvector3D* GameObject::getPosicion(){
    return &posicion;
}

void GameObject::setPosicion(dvector3D &p3D){
//    if(p3D != NULL){
    posicion = p3D;
    transform3D* go = (transform3D*)this->findComponent("transform3D");
    if(go != NULL)
        go->setPosition(posicion);
    class render* ren = (class render*)findComponent("render");
    if(ren != NULL)
        ren->setNodePosition(posicion);
//    }
}

void GameObject::setRotacion(float rot){
	rotacion.z = rot;
	transform3D* go = (transform3D*)this->findComponent("transform3D");
	if(go != NULL)
		go->rotar(rotacion.z);
	
	class render* ren = (class render*)findComponent("render");
	if(ren != NULL)
		ren->setNodeRotation(rotacion);
	
//	go->update(NULL, NULL, rotacion, anguloDisparo, rot);
//	printf("%.2f %.2f\n", anguloDisparo[0], anguloDisparo[1]);
}

void GameObject::rotarConRaton(dvector3D &posRaton){
	transform3D* go = (transform3D*)this->findComponent("transform3D");
	if(go != NULL)
		rotacion.z = go->rotarConRaton(posRaton);
	class render* ren = (class render*)findComponent("render");
	if(ren != NULL)
		ren->setNodeRotation(rotacion);
}

dvector3D* GameObject::getRotacion(){
	return &rotacion;
}

void GameObject::mover(dvector3D &vel){
	transform3D* go = (transform3D*)findComponent("transform3D");
	if(go != NULL)
		go->mover(vel);
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

dvector3D* GameObject::getDirDisparo(){
	return &anguloDisparo;
}

void GameObject::setDirDisparo(dvector3D &dir){
    anguloDisparo = dir;
}

void GameObject::setType(typeObj t){
	tipo = t;
}

typeObj const* GameObject::getType(){
	return &tipo;
}

