
#ifndef Modelo_hpp
#define Modelo_hpp

#include <stdio.h>
#include <vector>

#include <GL/glew.h>
#include <assimp/scene.h>
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <SOIL/SOIL.h>

#include "Shader.h"
#include "Mesh.hpp"

class Modelo{
public:
	Modelo(GLchar* ruta);
	void Draw(Shader shader);
	void imprimirDatos();
	
private:
	std::vector<Mesh> meshes;
	std::string directorio;
	
	void loadModel(std::string ruta);
	void processNode(aiNode* node, const aiScene* scene);
	Mesh processMesh(aiMesh* mesh, const aiScene* scene);
	std::vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName);
	GLuint TextureFromFile(const char* ruta, std::string directorio);
	
	unsigned int nVertices, nNormales, nCaras, nIndices;
	bool bTex;
	std::string rFile, rTextura;
};

#endif /* Modelo_hpp */
