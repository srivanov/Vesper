
#ifndef Modelo_hpp
#define Modelo_hpp

#include <stdio.h>
#include <vector>

#include <GL/glew.h>
#include <assimp/scene.h>
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <SOIL/SOIL.h>

//libreria para trabajar con matrices
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Shader.h"
#include "Mesh.hpp"

class Modelo{
public:
	Modelo(GLchar* ruta);
	~Modelo();
	void Draw(Shader shader);
	void imprimirDatos();
	void setTexture(std::string ruta);
	void setPosition(glm::vec3 pos);
	void setRotation(glm::vec3 rot);
	
private:
	void loadModel(std::string ruta);
	void processNode(aiNode* node, const aiScene* scene);
	Mesh processMesh(aiMesh* mesh, const aiScene* scene);
	std::vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName);
	GLuint TextureFromFile(const char* ruta, std::string directorio);
	
	std::vector<Mesh> meshes;
	unsigned int nVertices, nNormales, nCaras, nIndices;
	bool bTex;
	std::string rFile, rTextura, directorio;
	glm::mat4 modelMatrix;
	glm::vec3 position, rotation;
};

#endif /* Modelo_hpp */
