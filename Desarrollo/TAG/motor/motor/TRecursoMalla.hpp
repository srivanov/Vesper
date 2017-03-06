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
#include <SOIL/SOIL.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

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
	void asignarMatrix(glm::mat4 *m);
private:
	
	void processNode(aiNode* node, const aiScene* scene);
	Mesh processMesh(aiMesh* mesh, const aiScene* scene);
	std::vector<Texture*> loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName);
	
	Texture* pedirTextura(std::string &ruta);
	
	std::vector<Mesh> meshes;
	std::string rFile, rTextura, directorio;
	glm::mat4 modelMatrix;
	glm::vec3 position, rotation;
	//variables para imprimir por consolar datos
	unsigned int nVertices, nNormales, nCaras, nIndices;
	bool bTex;
	TGestorRecursos* gestor;
};

#endif /* TRecursoMalla_hpp */
