
#ifndef Mesh_hpp
#define Mesh_hpp

#include <stdio.h>
#include <vector>
#include <string>

#include <GL/glew.h>
#include <glm/glm.hpp>

class Shader;

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
	
	Vertex *vertices;
	GLuint *indices;
	Texture **texturas;
	
	GLint numVertices, numIndices, numTexturas;
	
	Mesh(Vertex *vertices, GLuint *indices, Texture **texturas, GLint numV, GLint numI, GLint numT);
	~Mesh();
	void Draw(Shader* shader);
	
private:
	GLuint VAO, VBO, EBO;
	void setupMesh();
};

#endif /* Mesh_hpp */
