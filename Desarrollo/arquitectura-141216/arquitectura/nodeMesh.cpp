//
//  nodeMesh.cpp
//  mapa
//
//  Created by Julia Martínez Valera on 17/11/16.
//  Copyright © 2016 Julia Martínez Valera. All rights reserved.
//

#include "nodeMesh.hpp"


nodeMesh::nodeMesh(ISceneNode* node){
	object = node;
}

nodeMesh::~nodeMesh(){
//	object->drop();
//	texture->drop();int* rotation
	object->remove();
	free(texture);
}

bool nodeMesh::_setMaterialTexture(ITexture* tex){
	if(tex == NULL)
		return false;
	object->setMaterialTexture(0, tex);
	return true;
}

void nodeMesh::_setNodePosition(float* posicion){
	if(posicion != NULL)
		object->setPosition(vector3df(posicion[0],posicion[1],posicion[2]));
}

void nodeMesh::_setNodeRotation(float* rotacion){
	if(rotacion != NULL){
		object->setRotation(vector3df(rotacion[0],rotacion[1],rotacion[2]));
	}
}

void nodeMesh::_setMaterialFlag(video::E_MATERIAL_FLAG flag, bool trigger){
	object->setMaterialFlag(flag, trigger);
}

float* nodeMesh::_getNodePosition(){
	vector3df p =  object->getAbsolutePosition();
	return new float[3]{p.X, p.Y, p.Z};
}

float* nodeMesh::_getNodeRotation(){
	vector3df r =  object->getRotation();
	return new float[3]{r.X, r.Y, r.Z};
}
