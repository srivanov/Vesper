//
//  ShaderManager.hpp
//  motor
//
//  Created by Stoycho Ivanov Atanasov on 5/3/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef ShaderManager_hpp
#define ShaderManager_hpp

#include "Shader.h"
#include <map>

class ShaderManager {
public:
	static ShaderManager* Instance(){static ShaderManager pinstance; return &pinstance;}
	~ShaderManager(){ shaders.clear(); }
	
	void cargarShader(std::string s, const GLchar* vertexPath, const GLchar* fragmentPath){
		shaders.insert(std::pair<std::string, Shader>(s, Shader(vertexPath, fragmentPath)));
	}
	
	Shader* setActiveShader(std::string s) {
		it = shaders.find(s);
		if(it!=shaders.end()){
			if(activo)
				activo->activar(false);
			activo = &it->second;
			name = it->first;
			activo->Use();
		}
		return activo;
	}
	
	Shader* getActivo() { return activo; }
	const char* getActivoNombre() { return name.c_str(); }
	void Usar(){ activo->Use(); }
	Shader* getShaderbyName(char* nombre) {
		auto s = shaders.find(nombre);
		if(s != shaders.end())
			return &s->second;
		return nullptr;
	}
	
protected:
	ShaderManager(){ activo=NULL; }
	
private:
	std::map<std::string, Shader> shaders;
	Shader* activo;
	std::string name;
	std::map<std::string, Shader>::iterator it;
};

#endif /* ShaderManager_hpp */
