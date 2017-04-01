//
//  TRecursoMalla.hpp
//  motor
//
//  Created by Stoycho Ivanov Atanasov on 18/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef TRecursoMalla_hpp
#define TRecursoMalla_hpp

#include <assimp/scene.h>
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>

#include "TRecurso.hpp"
#include "Mesh.hpp"

class TGestorRecursos;

class TRecursoMalla : public TRecurso{
public:
	TRecursoMalla();
	~TRecursoMalla();
	void cargarFichero(std::string &ruta);
	void Draw(Shader *shader);
	void setTexture(std::string &ruta);
	void imprimirDatos();
//	void asignarMatrix(glm::mat4 *m);
private:
	
	void processNode(aiNode* node, const aiScene* scene);
	Mesh* processMesh(aiMesh* mesh, const aiScene* scene);
	void loadMaterialTextures(Texture **tex, aiMaterial* mat, aiTextureType type, std::string typeName, int &index);
	
	Texture* pedirTextura(std::string &ruta);
	
//	std::vector<Mesh*> meshes;
	Mesh* meshes[10];
	std::string rFile, rTextura, directorio;
//	glm::mat4 modelMatrix;
//	glm::vec3 position, rotation;
	//variables para imprimir por consolar datos
	unsigned int nVertices, nNormales, nCaras, nIndices, numMeshes;
	bool bTex;
	TGestorRecursos* gestor;
};

#endif /* TRecursoMalla_hpp */
