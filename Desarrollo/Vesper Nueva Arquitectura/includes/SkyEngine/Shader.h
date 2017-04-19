
#ifndef Shader_h
#define Shader_h

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

//incluimos GLEW para usar sus funciones
#include <GL/glew.h>

class Shader
{
public:
	// el ID del programa
	GLuint Program;
	bool activo;
	
	// constructor que lee y compila los shaders
	Shader(const GLchar* vertexPath, const GLchar* fragmentPath){
		activo=false;
	// 1- Leemos el codigo fuente
		std::string vertexCode;
		std::string fragmentCode;
		std::ifstream vShaderFile;
		std::ifstream fShaderFile;
		
		// ensures ifstream objects can throw exceptions:
		vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		try
		{
			// Open files
			vShaderFile.open(vertexPath);
			fShaderFile.open(fragmentPath);
			std::stringstream vShaderStream, fShaderStream;
			// Read file's buffer contents into streams
			vShaderStream << vShaderFile.rdbuf();
			fShaderStream << fShaderFile.rdbuf();
			// close file handlers
			vShaderFile.close();
			fShaderFile.close();
			// Convert stream into GLchar array
			vertexCode = vShaderStream.str();
			fragmentCode = fShaderStream.str();
		}
		catch(std::ifstream::failure e)
		{
			std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
		}
		const GLchar* vShaderCode = vertexCode.c_str();
		const GLchar* fShaderCode = fragmentCode.c_str();
		
	// 2- Compilamos los shaders
		
		GLuint vertex, fragment;
		GLint success;
		GLchar infoLog[512];
		
		// Vertex Shader
		//creamos un vertex shader y recogemos su ID
		vertex = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex, 1, &vShaderCode, NULL);
		glCompileShader(vertex);
		
		//comprobamos si se ha compilado con exito
		glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
		if(!success)
		{
			glGetShaderInfoLog(vertex, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		};
  
		// Fragment Shader
		fragment = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment, 1, &fShaderCode, NULL);
		
		//compilamos el fragment shader
		glCompileShader(fragment);
		
		//comprobamos si se ha compilado con exito
		glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
		if(!success)
		{
			glGetShaderInfoLog(fragment, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
		};
  
		//creamos el programa de shaders
		this->Program = glCreateProgram();
		glAttachShader(this->Program, vertex);
		glAttachShader(this->Program, fragment);
		
		//linkamos los shaders al programa
		glLinkProgram(this->Program);
		
		//comprobamos que se ha linkado con exito
		glGetProgramiv(this->Program, GL_LINK_STATUS, &success);
		if(!success)
		{
			glGetProgramInfoLog(this->Program, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
		}
  
		//borramos los shader ya que no los vamos a utilizar mas
		glDeleteShader(vertex);
		glDeleteShader(fragment);
		
	}
	
	// Usar el programa
	void Use(){ glUseProgram(this->Program); activo=true;}
	void activar(bool b) { activo=b; }
};

#endif /* Shader_h */
