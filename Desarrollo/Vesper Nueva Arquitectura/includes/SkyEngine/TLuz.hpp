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
	void setIntensidad(glm::vec4 c);
	glm::vec4 getIntensidad();
	
    
	void setID(int id) { ID = id; }
	int getID(){ return ID; }
    
    void setAmbient (float lamb) {lambient = lamb;}
	void setSpecular(float spec) {lspecular = spec;}
	void setDiffuse(float ldif) {ldiffuse = ldif;}
	
	float getAmbient(){return lambient;}
    float getDiffuse(){return ldiffuse;}
	float getSpecular(){return lspecular;}

	void Draw(TNodo* n);
	void beginDraw(){}
	void endDraw(){}

private:
	int ID;
	Shader* sh;
	glm::vec4 color;
	glm::vec3 pos;
	std::stack<glm::mat4> trans;
	glm::mat4 matriz;
    float lambient, ldiffuse, lspecular;
};

#endif /* TLuz_hpp */
