//
//  TCamara.hpp
//  motor
//
//  Created by Stoycho Ivanov Atanasov on 7/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef TCamara_hpp
#define TCamara_hpp

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
	ShaderManager* sh;
	Pila *pila;
	bool esPerspectiva;
	const dvector2D *tam;
	float nearV, farV;
	std::stack<glm::mat4> trans;
	glm::mat4 matriz, projection;
	GLfloat Zoom;
	
	void calcularProyection() { projection = glm::perspective(glm::radians(Zoom), (GLfloat)tam->x/(GLfloat)tam->y, nearV, farV);
// 		projection = glm::ortho(-100.0f, 100.0f, -100.0f, 100.0f, nearV, farV);
	}
};

#endif /* TCamara_hpp */
