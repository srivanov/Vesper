
#include "Mesh.hpp"
#include "Shader.h"

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices, std::vector<Texture*> texturas){
	this->vertices = vertices;
	this->indices = indices;
	this->texturas = texturas;
	this->setupMesh();
}

void Mesh::Draw(Shader* shader){
	
	GLuint diffuseNr = 1;
	GLuint specularNr = 1;
	
	for(GLuint i = 0; i < this->texturas.size(); i++){
		
		// activamos la textura antes de linkarla
		glActiveTexture(GL_TEXTURE0 + i);
		
		// recogemos el numero de la textura
		std::stringstream ss;
		std::string number;
		std::string name = this->texturas[i]->type;
		
		if(name == "texture_diffuse")
			// cambiamos de GLuint a stream
			ss << diffuseNr++;
		else if(name == "texture_specular")
			// cambiamos de GLuint a stream
			ss << specularNr++;
		
		number = ss.str();
		
		glUniform1f(glGetUniformLocation(shader->Program, (name + number).c_str()), i);
		glBindTexture(GL_TEXTURE_2D, this->texturas[i]->id);
	}
	
	glActiveTexture(GL_TEXTURE0);
	
	// dibujamos el mesh
	glBindVertexArray(this->VAO);
	glDrawElements(GL_TRIANGLES, (GLint)this->indices.size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
	
	// liberamos la memoria de las texturas
	for (GLuint i = 0; i < this->texturas.size(); i++){
		glActiveTexture(GL_TEXTURE0 + i);
		glBindTexture(GL_TEXTURE_2D, 0);
	}
	glActiveTexture(GL_TEXTURE0);
}

void Mesh::setupMesh(){
	//generamos el Vertex Array Object
	glGenVertexArrays(1, &this->VAO);
	glGenBuffers(1, &this->VBO);
	glGenBuffers(1, &this->EBO);
	
	//linkamos el VAO
	glBindVertexArray(this->VAO);
	
	//linkamos el buffer GL_ARRAY_BUFFER al puntero VBO
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
	
	//copiamos los datos de los vertices a buffer GL_ARRAY_BUFFER
	glBufferData(GL_ARRAY_BUFFER, this->vertices.size() * sizeof(Vertex), &this->vertices[0], GL_STATIC_DRAW);
	
	//linkamos el array de elementos al EBO
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
	
	//copiamos los indices en el array de elementos
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->indices.size() * sizeof(GLuint), &this->indices[0], GL_STATIC_DRAW);
	
	glEnableVertexAttribArray(0);
	
	/*
	 * aqui le decimos a OpenGL como interpretar el buffer de vertices cuando tenga que dibujar
	 * el primer parametro es el indice del vertice que queremos configurar
	 * el segundo es el numero de ejes que contiene cada vertice, 1 2 3 o 4
	 * el tercero especifica el tipo de dato que vamos a manejar
	 * el cuarto indica si queremos normalizar los valores o no
	 * el quinto especifica el tamaño de que tiene cada vertice en el buffer, ahora son 3 floats
	 * el sexto es un puntero a la posicion que queremos empezar la figura, esto sirve para cuando tengamos mas de uno
	 * en la otra funcion activamos los atributos de vertices ya que estan desactivados por defecto
	 */
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);
	
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, Normal));
	
	// atributos de las texturas
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, TexCoords));
	
	//deslinkamos el VAO por seguridad
	glBindVertexArray(0);
}




