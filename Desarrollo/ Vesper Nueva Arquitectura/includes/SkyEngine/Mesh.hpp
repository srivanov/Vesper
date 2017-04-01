
#ifndef Mesh_hpp
#define Mesh_hpp

#include <stdio.h>
#include <vector>
#include <string>

#include <GL/glew.h>
#include <glm/glm.hpp>

class Shader;

struct Vertex {
	float Position[3];
	float Normal[3];
	float TexCoords[2];
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
