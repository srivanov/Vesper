
#include "nodeMesh.hpp"


nodeMesh::nodeMesh(ISceneNode* node){
	object = node;
    gun = NULL;
}

void nodeMesh::setPortatil(ISceneNode* node){
    gun = node;
}

nodeMesh::~nodeMesh(){
	object->remove();
	object = NULL;
}

bool nodeMesh::_setMaterialTexture(ITexture* tex){
	if(tex == NULL)
		return false;
	object->setMaterialTexture(0, tex);
	return true;
}

void nodeMesh::_setNodePosition(dvector3D &posicion){
//	if(posicion != NULL)
    object->setPosition(vector3df(posicion.x,posicion.z,posicion.y));
//    if(gun != NULL)
//        gun->setPosition(vector3df(posicion.x,posicion.y,posicion.z-3));
}

void nodeMesh::_setNodeRotation(dvector3D &rotacion){
//	if(rotacion != NULL)
    object->setRotation(vector3df(rotacion.x,rotacion.y,rotacion.z));
}

void nodeMesh::_setMaterialFlag(video::E_MATERIAL_FLAG flag, bool trigger){
	object->setMaterialFlag(flag, trigger);
}

dvector3D* nodeMesh::_getNodePosition(){
	dvector3D p(object->getAbsolutePosition().X, object->getAbsolutePosition().Y, object->getAbsolutePosition().Z);
	return &p;
}

dvector3D* nodeMesh::_getNodeRotation(){
	dvector3D r(object->getRotation().X, object->getRotation().Y, object->getRotation().Z);
	return &r;
}

ISceneNode* nodeMesh::_getNode(){
	return object;
}

void nodeMesh::_setNode(ISceneNode* node){
	object = node;
}

