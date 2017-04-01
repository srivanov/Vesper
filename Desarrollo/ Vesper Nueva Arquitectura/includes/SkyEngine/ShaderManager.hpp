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
	static ShaderManager* Instance() { static ShaderManager pinstance; return &pinstance; }
	~ShaderManager();
	
	void cargarShader(std::string s, const GLchar* vertexPath, const GLchar* fragmentPath);
	Shader* setActiveShader(std::string s) {
		it = shaders.find(s);
		if(it!=shaders.end()){
			if(activo)
				activo->activar(false);
			activo = &it->second;
			activo->Use();
		}
		return activo;
	}
	
	Shader* getActivo() { return activo; }
	
protected:
	ShaderManager();
	
private:
	std::map<std::string, Shader> shaders;
	Shader* activo;
	std::map<std::string, Shader>::iterator it;
};

#endif /* ShaderManager_hpp */
