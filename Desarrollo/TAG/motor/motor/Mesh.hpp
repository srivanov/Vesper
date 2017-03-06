
#ifndef Mesh_hpp
#define Mesh_hpp

#include <stdio.h>
#include <vector>

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "Shader.h"

struct Vertex {
	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec2 TexCoords;
};

struct Texture {
	GLuint id;
	std::string type;
	std::string path;
};

class Mesh{
public:
	
	std::vector<Vertex> vertices;
	std::vector<GLuint> indices;
	std::vector<Texture*> texturas;
	
	Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices, std::vector<Texture*> texturas);
	void Draw(Shader *shader);
	
private:
	
	GLuint VAO, VBO, EBO;
	void setupMesh();
};

#endif /* Mesh_hpp */
