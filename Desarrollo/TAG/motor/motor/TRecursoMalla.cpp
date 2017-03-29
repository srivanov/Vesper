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
}

TRecursoMalla::~TRecursoMalla(){
	gestor = nullptr;
	meshes.clear();
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

//void TRecursoMalla::asignarMatrix(glm::mat4 *m){
//	modelMatrix = *m;
//}

void TRecursoMalla::Draw(Shader *shader){
	std::vector<Mesh>::iterator it = meshes.begin();
	while(it != meshes.end()){
		it->Draw(shader);
		it++;
	}
}

void TRecursoMalla::processNode(aiNode *node, const aiScene *scene){
	
	for (GLuint i=0; i<node->mNumMeshes; i++) {
		//cojo de la escena entera los meshes del nodo
		aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
		this->meshes.push_back(this->processMesh(mesh, scene));
	}
	for (GLuint i=0; i<node->mNumChildren; i++) {
		this->processNode(node->mChildren[i], scene);
	}
}

Mesh TRecursoMalla::processMesh(aiMesh *mesh, const aiScene *scene){
	
	std::vector<Vertex> vertices;
	std::vector<GLuint> indices;
	std::vector<Texture*> texturas;
	
//	Vertex vertices[mesh->mNumVertices];
//	GLuint indices[mesh->]
	
//	printf("%s: %d\n",mesh->mName.C_Str(), mesh->mNumVertices);
	unsigned int n=0;
	for (GLuint i=0; i<mesh->mNumVertices; i++){
		Vertex vertex;
		
		// procesamos las coordenadas de los vertices, normales y texturas
		glm::vec3 vector;
		vector.x = mesh->mVertices[i].x;
		vector.y = mesh->mVertices[i].y;
		vector.z = mesh->mVertices[i].z;
		vertex.Position = vector;
		
		if(mesh->mNormals != NULL){
			vector.x = mesh->mNormals[i].x;
			vector.y = mesh->mNormals[i].y;
			vector.z = mesh->mNormals[i].z;
			vertex.Normal = vector;
			n++;
		}
		
		if(mesh->mTextureCoords[0]){
			glm::vec2 vec;
			vec.x = mesh->mTextureCoords[0][i].x;
			vec.y = mesh->mTextureCoords[0][i].y;
			vertex.TexCoords = vec;
			if(!bTex)
				bTex=true;
		}
		else
			vertex.TexCoords = glm::vec2(0.0f, 0.0f);
		
		vertices.push_back(vertex);
	}
	
	this->nVertices+=mesh->mNumVertices;
	this->nNormales+=n;
	this->nCaras+=mesh->mNumFaces;
	
	n=0;
	for(GLuint i = 0; i < mesh->mNumFaces; i++){
		aiFace face = mesh->mFaces[i];
		for (GLuint j=0; j<face.mNumIndices; j++)
			indices.push_back(face.mIndices[j]);
		n+=face.mNumIndices;
	}
	this->nIndices+=n;
	//	if(mesh->mMaterialIndex >= 0){
	
	aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];
	
	// 1. Diffuse maps
	std::vector<Texture*> diffuseMaps = this->loadMaterialTextures(material, aiTextureType_DIFFUSE, "texture_diffuse");
	texturas.insert(texturas.end(), diffuseMaps.begin(), diffuseMaps.end());
	
	// 2. Specular maps
	std::vector<Texture*> specularMaps = this->loadMaterialTextures(material, aiTextureType_SPECULAR, "texture_specular");
	texturas.insert(texturas.end(), specularMaps.begin(), specularMaps.end());
	
	//3. Normal maps
	std::vector<Texture*> normalMaps = this->loadMaterialTextures(material, aiTextureType_NORMALS, "texture_normal");
	texturas.insert(texturas.end(), normalMaps.begin(), normalMaps.end());
	//	}
	return Mesh(vertices, indices, texturas);
}

std::vector<Texture*> TRecursoMalla::loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName){
	std::vector<Texture*> textures;
	for(GLuint i = 0; i < mat->GetTextureCount(type); i++){
		aiString str;
		mat->GetTexture(type, i, &str);
		std::string dir = directorio+'/'+str.C_Str();
		textures.push_back(pedirTextura(dir));
	}
	textures.shrink_to_fit();
	return textures;
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

void TRecursoMalla::setTexture(std::string &ruta){
	meshes.at(0).texturas.clear();
	meshes.at(0).texturas.push_back(pedirTextura(ruta));
}

Texture* TRecursoMalla::pedirTextura(std::string &ruta){
	return static_cast<TRecursoTextura*>(gestor->getRecurso(ruta, tRTextura))->getTexture();
}


