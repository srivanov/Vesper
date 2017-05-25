//
//  SkyEngine.cpp
//  motor
//
//  Created by Stoycho Ivanov Atanasov on 2/3/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "SkyEngine.hpp"
#include "SkyWindow.hpp"

SkyEngine::SkyEngine() : num_c(0), num_l(0), active_cam(0) {
	root = new TNodo();
	root->setEntidad(new TTransform());
	debug = false;
	shMan = ShaderManager::Instance();
	window = SkyWindow::Instance();
}

SkyEngine::~SkyEngine(){
	delete root;
}

void SkyEngine::init(){
	shMan->cargarShader("shadow_map", "../Shaders/shadow_map.vs", "../Shaders/shadow_map.frag");
	shMan->cargarShader("debug_shadow", "../Shaders/debug_quad.vs", "../Shaders/debug_quad.frag");
	shMan->cargarShader("render", "../Shaders/texDirect.vs", "../Shaders/texDirect.frag");
	shMan->setActiveShader("render");
	Shader* s = shMan->getShaderbyName((char*)"render");
	//		glUniform1i(glGetUniformLocation(s->Program, "texture_diffuse1"), 0);
	glUniform1i(glGetUniformLocation(s->Program, "shadowMap"), 2);
}

SkyMalla* SkyEngine::crearMalla(SkyNodo* padre, tipoMalla t){
	return new SkyMalla(padre ? padre->TransNodos[0] : root, t);;
}

SkyCamara* SkyEngine::crearCamara(SkyNodo* padre){
	SkyCamara* c = new SkyCamara(padre ? padre->TransNodos[0] : root, num_c);
	camaras.insert(std::pair<int, SkyCamara*>(num_c, c));
	num_c++;
	return c;
}

SkyLuz* SkyEngine::crearLuz(SkyNodo* padre){
	SkyLuz* c = new SkyLuz(padre ? padre->TransNodos[0] : root, num_l);
	luces.insert(std::pair<int, SkyLuz*>(num_l, c));
	num_l++;
	return c;
}

SkyMallaAnimada * SkyEngine::crearMallaAnimada(SkyNodo *padre){
    return new SkyMallaAnimada(padre ? padre->TransNodos[0] : root);
}

void SkyEngine::Draw(){
	shMan->setActiveShader("render");
    renderCamaras();
	glCullFace(GL_FRONT);
    shMan->setActiveShader("shadow_map");
	renderScene(true);
	limpiar();
	glCullFace(GL_BACK);
	
	if(debug)
		renderZbuffer();
	else{
		shMan->setActiveShader("render");
		renderScene(false);
	}
}

void SkyEngine::setAntiAliasing(bool set){
    AntiAliasing = set;
}

void SkyEngine::renderScene(bool pass){
	if(!pass)
		renderCamaras();
	luces.begin()->second->Draw(pass);
	root->Draw(pass);
}

void SkyEngine::renderCamaras(){
	std::map<int, SkyCamara*>::iterator iter = camaras.find(active_cam);
	if(iter != camaras.end())
		iter->second->Draw();
	else
		printf("SIN CAMARA\n");
}

void SkyEngine::renderZbuffer(){
	shMan->setActiveShader("debug_shadow");
	luces.begin()->second->debugDraw(shMan->getShaderbyName("debug_shadow"));
	limpiar();
}

void SkyEngine::limpiar(){
	window->resetViewport();
	luces.begin()->second->clearScreen();
}

bool SkyEngine::setActiveCam(int i){
	if(i<0 || i>num_c)
		return false;
	active_cam = i;
	return true;
}

//TO DO: apagar luz segun el ID
