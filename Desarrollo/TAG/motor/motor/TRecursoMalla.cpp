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
}

TRecursoMalla::~TRecursoMalla(){
	gestor = nullptr;
//	std::vector<Mesh*>::iterator it = meshes.begin();
//	while (it != meshes.end()) {
//		delete *it;
//		++it;
//	}
//	meshes.clear();
	
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
//		meshes.push_back(processMesh(mesh, scene));
		meshes[numMeshes] = processMesh(mesh, scene);
		numMeshes++;
	}
	for (GLuint i=0; i<node->mNumChildren; i++) {
		this->processNode(node->mChildren[i], scene);
	}
}

Mesh* TRecursoMalla::processMesh(aiMesh *mesh, const aiScene *scene){
	
//	std::vector<Vertex> vertices;
//	std::vector<GLuint> indices;
//	std::vector<Texture*> texturas;
	
	aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];
	GLint numVertices = mesh->mNumVertices,
		numIndices = mesh->mNumFaces * mesh->mFaces->mNumIndices,
		numTexturas = material->GetTextureCount(aiTextureType_DIFFUSE)+material->GetTextureCount(aiTextureType_SPECULAR)+material->GetTextureCount(aiTextureType_NORMALS);
	
	Vertex *vertices2 = new Vertex[numVertices];
	GLuint *indices2 = new GLuint[numIndices];
	Texture **texturas2 = new Texture*[numTexturas];
	
//	printf("%s: %d\n",mesh->mName.C_Str(), mesh->mNumVertices);
	
	
	for (GLuint i=0; i<mesh->mNumVertices; i++){
		Vertex vertex;
		
		// procesamos las coordenadas de los vertices, normales y texturas
//		glm::vec3 vector;
//		vector.x = mesh->mVertices[i].x;
//		vector.y = mesh->mVertices[i].y;
//		vector.z = mesh->mVertices[i].z;
//		vertex.Position = vector;
		
		vertex.Position[0] = mesh->mVertices[i].x;
		vertex.Position[1] = mesh->mVertices[i].y;
		vertex.Position[2] = mesh->mVertices[i].z;
		
		if(mesh->mNormals != NULL){
//			vector.x = mesh->mNormals[i].x;
//			vector.y = mesh->mNormals[i].y;
//			vector.z = mesh->mNormals[i].z;
//			vertex.Normal = vector;
			
			vertex.Normal[0] = mesh->mNormals[i].x;
			vertex.Normal[1] = mesh->mNormals[i].y;
			vertex.Normal[2] = mesh->mNormals[i].z;
		}
		
		if(mesh->mTextureCoords[0]){
//			glm::vec2 vec;
//			vec.x = mesh->mTextureCoords[0][i].x;
//			vec.y = mesh->mTextureCoords[0][i].y;
//			vertex.TexCoords = vec;
			
			vertex.TexCoords[0] = mesh->mTextureCoords[0][i].x;
			vertex.TexCoords[1] = mesh->mTextureCoords[0][i].y;
			
			if(!bTex)
				bTex=true;
		}
		else
			vertex.TexCoords[0] = vertex.TexCoords[1] = 0.0f;
//			vertex.TexCoords = glm::vec2(0.0f, 0.0f);
		
//		vertices.push_back(vertex);
		vertices2[i] = vertex;
	}
	
	for(GLuint i = 0; i < mesh->mNumFaces; i++){
		aiFace face = mesh->mFaces[i];
		for (GLuint j=0; j<face.mNumIndices; j++){
//			indices.push_back(face.mIndices[j]);
			indices2[i*face.mNumIndices+j] = face.mIndices[j];
		}
	}
	
	//	if(mesh->mMaterialIndex >= 0){
	
	
	int llenado = 0;
	// 1. Diffuse maps
	loadMaterialTextures(texturas2, material, aiTextureType_DIFFUSE, "texture_diffuse", llenado);
//	texturas.insert(texturas.end(), diffuseMaps.begin(), diffuseMaps.end());
	
	// 2. Specular maps
	loadMaterialTextures(texturas2, material, aiTextureType_SPECULAR, "texture_specular", llenado);
//	texturas.insert(texturas.end(), specularMaps.begin(), specularMaps.end());
	
	//3. Normal maps
	loadMaterialTextures(texturas2, material, aiTextureType_NORMALS, "texture_normal", llenado);
//	texturas.insert(texturas.end(), normalMaps.begin(), normalMaps.end());
	//	}
	return new Mesh(vertices2, indices2, texturas2, numVertices, numIndices, numTexturas);
}

void TRecursoMalla::loadMaterialTextures(Texture **tex, aiMaterial *mat, aiTextureType type, std::string typeName, int &index){
//	std::vector<Texture*> textures;
	for(GLuint i = 0; i < mat->GetTextureCount(type); i++){
		aiString str;
		mat->GetTexture(type, i, &str);
		std::string dir = directorio+'/'+str.C_Str();
//		textures.push_back(pedirTextura(dir));
		tex[index] = pedirTextura((char*)dir.c_str());
		index++;
	}
//	textures.shrink_to_fit();
//	return textures;
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
//	meshes.at(0).texturas.clear();
//	meshes.at(0).texturas.push_back(pedirTextura(ruta));
//	meshes.at(0)->texturas[0] = pedirTextura(ruta);
	meshes[0]->texturas[0] = pedirTextura(ruta);
}

Texture* TRecursoMalla::pedirTextura(char* ruta){
	return static_cast<TRecursoTextura*>(gestor->getRecurso(ruta, tRTextura))->getTexture();
}


