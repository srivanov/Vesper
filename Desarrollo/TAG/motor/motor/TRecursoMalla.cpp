//
//  TRecursoMalla.cpp
//  motor
//
//  Created by Stoycho Ivanov Atanasov on 18/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include <iostream>

#include "TRecursoMalla.hpp"
#include "TGestorRecursos.hpp"
#include "TRecursoTextura.hpp"

TRecursoMalla::TRecursoMalla(){
	gestor = TGestorRecursos::Instance();
	numMeshes = 0;
	for (int i=0; i<10; i++) {
		meshes[i]=nullptr;
	}
}

TRecursoMalla::~TRecursoMalla(){
	gestor = nullptr;
	for (int i=0; i<numMeshes; i++) {
		if(meshes[i])
			delete meshes[i];
	}
}

void TRecursoMalla::cargarFichero(std::string &ruta){
	Assimp::Importer importer;
	const aiScene* scene = importer.ReadFile(ruta, aiProcess_Triangulate);
	
	if(!scene || scene->mFlags == AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode){
		std::cout << "ERROR::ASSIMP::" << importer.GetErrorString() << std::endl;
	}
	this->directorio = ruta.substr(0, ruta.find_last_of('/'));
	this->rFile = ruta.substr(ruta.find_last_of('/')+1, ruta.size());
	this->processNode(scene->mRootNode, scene);
}

void TRecursoMalla::Draw(Shader *shader, Texture* textura){
//	std::vector<Mesh*>::iterator it = meshes.begin();
//	while(it != meshes.end()){
//		(*it)->Draw(shader);
//		it++;
//	}
	for (int i=0; i<numMeshes; ++i) {
		meshes[i]->Draw(shader, textura);
	}
}

void TRecursoMalla::processNode(aiNode *node, const aiScene *scene){
	
	for (GLuint i=0; i<node->mNumMeshes; i++) {
		//cojo de la escena entera los meshes del nodo
		aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
		meshes[numMeshes] = processMesh(mesh, scene);
		numMeshes++;
	}
	for (GLuint i=0; i<node->mNumChildren; i++) {
		this->processNode(node->mChildren[i], scene);
	}
}

Mesh* TRecursoMalla::processMesh(aiMesh *mesh, const aiScene *scene){
	
	aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];
	GLint numVertices = mesh->mNumVertices,
		numIndices = mesh->mNumFaces * mesh->mFaces->mNumIndices,
		numTexturas = material->GetTextureCount(aiTextureType_DIFFUSE)+
					  material->GetTextureCount(aiTextureType_SPECULAR)+
					  material->GetTextureCount(aiTextureType_NORMALS);
	
	Vertex *vertices2 = new Vertex[numVertices];
	GLuint *indices2 = new GLuint[numIndices];
	Texture **texturas2 = new Texture*[numTexturas];
	
	for (GLuint i=0; i<mesh->mNumVertices; i++){
		Vertex vertex;
		
		vertex.Position[0] = mesh->mVertices[i].x;
		vertex.Position[1] = mesh->mVertices[i].y;
		vertex.Position[2] = mesh->mVertices[i].z;
		
		//comparar la menor y la mayor
		takeMin(&minBB, vertex.Position);
		takeMax(&maxBB, vertex.Position);
		
		
		if(mesh->mNormals != NULL){
			vertex.Normal[0] = mesh->mNormals[i].x;
			vertex.Normal[1] = mesh->mNormals[i].y;
			vertex.Normal[2] = mesh->mNormals[i].z;
		}
		
		if(mesh->mTextureCoords[0]){
			vertex.TexCoords[0] = mesh->mTextureCoords[0][i].x;
			vertex.TexCoords[1] = mesh->mTextureCoords[0][i].y;
			
			if(!bTex)
				bTex=true;
		}
		else
			vertex.TexCoords[0] = vertex.TexCoords[1] = 0.0f;
		vertices2[i] = vertex;
	}
	
	for(GLuint i = 0; i < mesh->mNumFaces; i++){
		aiFace face = mesh->mFaces[i];
		for (GLuint j=0; j<face.mNumIndices; j++){
			indices2[i*face.mNumIndices+j] = face.mIndices[j];
		}
	}
	
	
	int llenado = 0;
	// 1. Diffuse maps
	loadMaterialTextures(texturas2, material, aiTextureType_DIFFUSE, "texture_diffuse", llenado);
	
	// 2. Specular maps
	loadMaterialTextures(texturas2, material, aiTextureType_SPECULAR, "texture_specular", llenado);
	
	//3. Normal maps
	loadMaterialTextures(texturas2, material, aiTextureType_NORMALS, "texture_normal", llenado);
	
	Mesh* m = new Mesh(vertices2, indices2, texturas2, numVertices, numIndices, numTexturas);
	return m;
}

void TRecursoMalla::loadMaterialTextures(Texture **tex, aiMaterial *mat, aiTextureType type, std::string typeName, int &index){
	for(GLuint i = 0; i < mat->GetTextureCount(type); i++){
		aiString str;
		mat->GetTexture(type, i, &str);
		std::string dir = directorio+'/'+str.C_Str();
		tex[index] = pedirTextura((char*)dir.c_str());
		index++;
	}
}

void TRecursoMalla::imprimirDatos(){
	std::cout << "Archivo: " << this->rFile << std::endl;
	
	if(this->rTextura.length()==0)
		std::cout << "Textura: Sin textura" << std::endl;
	else
		std::cout << "Textura: " << this->rTextura << std::endl;
	
	std::cout << "Vertices: " << this->nVertices << std::endl;
	std::cout << "Normales: " << this->nNormales << std::endl;
	std::cout << "Caras: " << this->nCaras << std::endl;
	std::cout << "Indices: " << this->nIndices << std::endl;
	
	if(bTex)
		std::cout << "Coordenadas de textura: True" << std::endl;
	else
		std::cout << "Coordenadas de textura: False" << std::endl;
}

void TRecursoMalla::setTexture(char* ruta){
	meshes[0]->texturas[0] = pedirTextura(ruta);
}

Texture* TRecursoMalla::pedirTextura(char* ruta){
	return static_cast<TRecursoTextura*>(gestor->getRecurso(ruta, tRTextura))->getTexture();
}

void TRecursoMalla::takeMin(glm::vec3 *d, float *p){
	if(d->x > p[0])
		d->x = p[0];
	if(d->y > p[1])
		d->y = p[1];
	if(d->z > p[2])
		d->z = p[2];
}

void TRecursoMalla::takeMax(glm::vec3 *d, float *p){
	if(d->x < p[0])
		d->x = p[0];
	if(d->y < p[1])
		d->y = p[1];
	if(d->z < p[2])
		d->z = p[2];
}

void TRecursoMalla::initBB(){
	minBB.x = 1000;		minBB.y = 1000;		minBB.z = 1000;
	maxBB.x = -1000;	maxBB.y = -1000;	maxBB.z = -1000;
}


