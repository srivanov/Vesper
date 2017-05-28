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
	void Draw(Shader *shader, Texture* textura);
	void setTexture(char* ruta);
	void imprimirDatos();
	glm::vec4& getminBB(){ return minBB; }
	glm::vec4& getmaxBB(){ return maxBB; }
private:
	
	void processNode(aiNode* node, const aiScene* scene);
	Mesh* processMesh(aiMesh* mesh, const aiScene* scene);
	void loadMaterialTextures(Texture **tex, aiMaterial* mat, aiTextureType type, std::string typeName, int &index);
	void takeMin(glm::vec4 *d, float *p);
	void takeMax(glm::vec4 *d, float *p);
	Texture* pedirTextura(char* ruta);
	void initBB();
	void crearBoundingBox();
	void drawBoundingBox();
	
	/*______VARIABLES_______*/
	Mesh* meshes[10];
	std::string rFile, rTextura, directorio;
	//variables para imprimir por consola datos
	unsigned int nVertices, nNormales, nCaras, nIndices, numMeshes;
	bool bTex;
	glm::vec4 minBB, maxBB;
	GLfloat vert[24];
	GLuint indices[12] = { 0,1,3, 1,2,3, 4,5,7, 5,6,7};
	GLuint BB_VAO, BB_VBO, BB_EBO;
	TGestorRecursos* gestor;
};

#endif /* TRecursoMalla_hpp */
