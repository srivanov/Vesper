//
//  TRecursoTextura.cpp
//  motor
//
//  Created by Stoycho Ivanov Atanasov on 21/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "TRecursoTextura.hpp"

TRecursoTextura::TRecursoTextura(){
	
}

TRecursoTextura::~TRecursoTextura(){
	
}

void TRecursoTextura::cargarFichero(std::string &name){
	int tex_width, tex_height;
	std::size_t amp = name.find_last_of('&');
	std::string typeName;
	if(amp != std::string::npos){
		typeName = name.substr(amp+1, name.size());
		name = name.substr(0, amp);
	}else
		typeName = "texture_diffuse";
	
	unsigned char* image = SOIL_load_image(name.c_str(), &tex_width, &tex_height, 0, SOIL_LOAD_RGB);
	
	texture.id = tex2OpenGL(image, tex_width, tex_height);
	texture.path = name;
	texture.type = typeName;
	
}

GLuint TRecursoTextura::tex2OpenGL(unsigned char* image, int &tex_width, int &tex_height){
	
	GLuint textureID;
	
	//generamos la textura en OpenGL
	glGenTextures(1, &textureID);
	
	//linkamos la textura al objeto en el primer parametro
	glBindTexture(GL_TEXTURE_2D, textureID);
	
	/*
	 * asignamos la imagen a la textura de OpenGL
	 * el primer argumento especifica a que textura queremos asignar la imagen
	 * el segundo indica el nivel de mipmap, se pone a 0 porque las generamos automaticamente en la siguiente linea
	 * el tercero indica el tipo en el que queremos almacenar la textura
	 * el quinto y sexto indica el ancho y alto de la imagen
	 * el siguiente siempre tiene que ser 0
	 * el septimo y octavo especifican el tipo y el formato de la imagen fuente cargada
	 * el ultimo es la imagen
	 */
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, tex_width, tex_height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	
	//hacemos que OpenGL genere el mipmap de la textura automaticamente
	glGenerateMipmap(GL_TEXTURE_2D);
	
	// poniendo ajustes para la textura si nos salimos para que se repita
	// o lo que queramos que haga
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	
	// Set texture filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);
	return textureID;
}
