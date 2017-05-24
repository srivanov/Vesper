//
//  TLuz.hpp
//  motor
//
//  Created by Stoycho Ivanov Atanasov on 7/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef TLuz_hpp
#define TLuz_hpp

#include <stdio.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "TEntidad.hpp"
#include "ShaderManager.hpp"

class TNodo;

class TLuz : public TEntidad{
public:
	TLuz();
	~TLuz();
	
	void setID(int id) { ID = id; }
	int getID(){ return ID; }
	
	void setIntensidad(glm::vec4 c){ color = c; }
	glm::vec4 getIntensidad(){ return color; }
    
    void setAmbient (float lamb) {lambient = lamb;}
	void setSpecular(float spec) {lspecular = spec;}
	void setDiffuse(float ldif) {ldiffuse = ldif;}
	
	float getAmbient(){return lambient;}
    float getDiffuse(){return ldiffuse;}
	float getSpecular(){return lspecular;}

	void Draw(TNodo* n);
	void shadowDraw(TNodo* n);
	void DebugDraw(Shader* s);
	void ClearScreen();
	
	void setLightDirection(glm::vec3 d) { direction = d; }
	glm::vec3 getLightDirection() { return direction; }
	
	void beginDraw(){}
	void endDraw(){}

private:
	int ID;
	glm::vec4 color;
	glm::vec3 pos, target, direction;
	std::stack<glm::mat4> trans;
	glm::mat4 matriz, lightSpaceMatrix;
    float lambient, ldiffuse, lspecular;
	GLuint depthMapFBO, depthMap, quadVAO = 0, quadVBO, SHADOW_WIDTH = 2048, SHADOW_HEIGHT = 2048;
	
	void setupLight();
	void calcularTransformaciones(TNodo* n);
	void dibujar_luz_puntual();
	void dibujar_luz_direccional();
	void configureMatrices();
	void RenderQuad();
};

#endif /* TLuz_hpp */
