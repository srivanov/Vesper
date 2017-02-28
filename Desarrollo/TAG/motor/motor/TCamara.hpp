//
//  TCamara.hpp
//  motor
//
//  Created by Stoycho Ivanov Atanasov on 7/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef TCamara_hpp
#define TCamara_hpp

#include <stack>
#include <stdio.h>
//#include <GL/glew.h>
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>

#include "Shader.h"
#include "TEntidad.hpp"

class TNodo;

const GLfloat ZOOM = 45.0f;

class TCamara : public TEntidad{
public:
	TCamara();
	~TCamara();
	void setPerspectiva();
	void setParalela();
	void setNearValue(float n);
	void setFarValue(float f);
	
	void setID(int id) { ID = id; }
	int getID(){ return ID; }
	
	void Draw(TNodo* n);
	
	void beginDraw(){}
	void endDraw(){}
	
	//sucia
	Shader* sh;
	int w, h;
private:
	int ID;
	bool esPerspectiva;
	float nearV, farV;
	std::stack<glm::mat4> trans;
	glm::mat4 matriz, projection;
	GLfloat Zoom;
};

#endif /* TCamara_hpp */
