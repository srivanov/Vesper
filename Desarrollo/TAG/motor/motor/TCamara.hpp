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

#include "ShaderManager.hpp"
#include "TEntidad.hpp"
#include "Dvector.hpp"

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
	
	int w, h;
private:
	int ID;
	Shader* sh;
	bool esPerspectiva;
	const dvector2D *tam;
	float nearV, farV;
	std::stack<glm::mat4> trans;
	glm::mat4 matriz, projection;
	GLfloat Zoom;
};

#endif /* TCamara_hpp */
