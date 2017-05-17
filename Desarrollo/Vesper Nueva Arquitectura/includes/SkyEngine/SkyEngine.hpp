//
//  SkyEngine.hpp
//  motor
//
//  Created by Stoycho Ivanov Atanasov on 2/3/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef SkyEngine_hpp
#define SkyEngine_hpp

#include "TNodo.hpp"
#include "SkyNodo.hpp"
#include "SkyMalla.hpp"
#include "SkyCamara.hpp"
#include "SkyLuz.hpp"
#include <map>

class SkyEngine {
public:
	static SkyEngine* Instance() { static SkyEngine p; return &p; }
	~SkyEngine();
	SkyMalla* crearMalla(TNodo* padre, tipoMalla t);
	SkyCamara* crearCamara(TNodo* padre);
	SkyLuz* crearLuz(TNodo* padre);
	void Draw();
	bool setActiveCam(int i);
	int getActiveCam() { return active_cam; }
	void initShaders(){
		shMan->cargarShader("shadow_map", "../Shaders/shadow_map.vs", "../Shaders/shadow_map.frag");
		shMan->cargarShader("debug_shadow", "../Shaders/debug_quad.vs", "../Shaders/debug_quad.frag");
		shMan->cargarShader("render", "../Shaders/texDirect.vs", "../Shaders/texDirect.frag");
		shMan->setActiveShader("render");
		Shader* s = shMan->getShaderbyName((char*)"render");
		//		glUniform1i(glGetUniformLocation(s->Program, "texture_diffuse1"), 0);
		glUniform1i(glGetUniformLocation(s->Program, "shadowMap"), 2);
	}
	
private:
	SkyEngine() : num_c(0), num_l(0), active_cam(0) {
		root = new TNodo();
		root->setEntidad(new TTransform());
		shMan = ShaderManager::Instance();
	}
	TNodo* root;
	std::map<int, SkyCamara*> camaras;
	std::map<int, SkyLuz*> luces;
	int num_c, num_l, active_cam;
	ShaderManager* shMan;
};


#endif /* SkyEngine_hpp */

