//
//  ShaderManager.cpp
//  motor
//
//  Created by Stoycho Ivanov Atanasov on 5/3/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "ShaderManager.hpp"

ShaderManager::ShaderManager(){
	activo=NULL;
}

ShaderManager::~ShaderManager(){
	shaders.clear();
}

void ShaderManager::cargarShader(std::string s, const GLchar* vertexPath, const GLchar* fragmentPath){
	shaders.insert(std::pair<std::string, Shader>(s, Shader(vertexPath, fragmentPath)));
}

