//
//  TLuz.cpp
//  motor
//
//  Created by Stoycho Ivanov Atanasov on 7/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "TLuz.hpp"
#include "TNodo.hpp"

TLuz::TLuz() : ID(0){
	pos = glm::vec3();
	sh = ShaderManager::Instance()->getActivo();
    lambient = 0.15f;
    ldiffuse = 2.5f;
    lspecular = 1.0f;
	control = false;
	GLuint SHADOW_WIDTH = 1024, SHADOW_HEIGHT = 1024;
	
	glGenFramebuffers(1, &depthMapFBO);
	glGenTextures(1, &depthMap);
	
	glBindTexture(GL_TEXTURE_2D, depthMap);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, SHADOW_WIDTH, SHADOW_HEIGHT, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	GLfloat borderColor[] = { 1.0, 1.0, 1.0, 1.0 };
	glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
	
	glBindFramebuffer(GL_FRAMEBUFFER, depthMapFBO);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, depthMap, 0);
	glDrawBuffer(GL_NONE);
	glReadBuffer(GL_NONE);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	
}

TLuz::~TLuz(){
	sh = nullptr;
}

void TLuz::Draw(TNodo* n){
	sh = ShaderManager::Instance()->getActivo();
	calcularTransformaciones(n);
	if(control)
		dibujar_luz_direccional();
	else
		dibujar_luz_puntual();
}

void TLuz::calcularTransformaciones(TNodo* n){
	while(n->getPadre()){
		n = n->getPadre();
		if(n->getEntidad())
			trans.push(n->getEntidad()->getMT());
	}
	
	glm::mat4 aux;
	matriz = glm::mat4();
	
	while(trans.size() > 0){
		aux = trans.top();
		matriz = matriz * aux;
		trans.pop();
	}
	pos = glm::column(matriz, 3);
}

void TLuz::dibujar_luz_puntual(){
	glUniform3f(glGetUniformLocation(sh->Program, "light.position"), pos.x, pos.y, pos.z);
	//propiedades de la luz
	glUniform3f(glGetUniformLocation(sh->Program, "light.ambient"), lambient, lambient, lambient);
	glUniform3f(glGetUniformLocation(sh->Program, "light.diffuse"), ldiffuse, ldiffuse, ldiffuse);
	glUniform3f(glGetUniformLocation(sh->Program, "light.specular"), lspecular, lspecular, lspecular);
	glUniform1f(glGetUniformLocation(sh->Program, "light.constant"),  1.0f);
	glUniform1f(glGetUniformLocation(sh->Program, "light.linear"),    0.09);
	glUniform1f(glGetUniformLocation(sh->Program, "light.quadratic"), 0.032);
}

void TLuz::dibujar_luz_direccional(){
	glViewport(0, 0, 1024, 1024);
	glBindFramebuffer(GL_FRAMEBUFFER, depthMapFBO);
	configureMatrices();
	glUniformMatrix4fv(glGetUniformLocation(sh->Program, "lightSpaceMatrix"), 1, GL_FALSE, glm::value_ptr(lightSpaceMatrix));
}

void TLuz::configureMatrices(){
	glm::mat4 lightProjection, lightView;
	GLfloat near_plane = 0.1f, far_plane = 20.5f;
	lightProjection = glm::ortho(-10.0f, 10.0f, -10.0f, 10.0f, near_plane, far_plane);
	lightView = glm::lookAt(pos, glm::vec3(0.0f), glm::vec3(0.0, 1.0, 0.0));
	lightSpaceMatrix = lightProjection * lightView;
}

void TLuz::ClearScreen(){
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
//	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBindTexture(GL_TEXTURE_2D, depthMap);
}

void TLuz::DebugDraw(Shader* s){
	glUniform1f(glGetUniformLocation(s->Program, "near_plane"), 0.1f);
	glUniform1f(glGetUniformLocation(s->Program, "far_plane"), 20.5f);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, depthMap);
	RenderQuad();
}

void TLuz::RenderQuad() {
	if (quadVAO == 0){
		GLfloat quadVertices[] = {
			// Positions        // Texture Coords
			-1.0f,  1.0f, 0.0f,  0.0f, 1.0f,
			-1.0f, -1.0f, 0.0f,  0.0f, 0.0f,
			1.0f,  1.0f, 0.0f,  1.0f, 1.0f,
			1.0f, -1.0f, 0.0f,  1.0f, 0.0f,
		};
		// Setup plane VAO
		glGenVertexArrays(1, &quadVAO);
		glGenBuffers(1, &quadVBO);
		glBindVertexArray(quadVAO);
		glBindBuffer(GL_ARRAY_BUFFER, quadVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), &quadVertices, GL_STATIC_DRAW);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	}
	glBindVertexArray(quadVAO);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	glBindVertexArray(0);
}


