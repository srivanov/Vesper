//
//  render.cpp
//  arquitectura
//
//  Created by Nerea Castellanos Rodríguez on 29/11/16.
//  Copyright © 2016 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "render.hpp"

render::render(){
	nodo = NULL;
//	ventanita = ventana::Instance();
//	device = ventana::Instance()->getDevice();
//	driver = ventana::Instance()->getDriver();
//	smgr = ventana::Instance()->getSceneManager();
	
    
}

render::~render(){
	
}

void render::crearWindow(uint32_t ancho, uint32_t alto, uint32_t color, bool fullscreen, bool stencilbuffer, bool vsync, bool receiver){
	ventana::Instance()->crearWindow(ancho, alto, color, fullscreen, stencilbuffer, vsync, receiver);
}

bool render::run(){
	return ventana::Instance()->getDevice()->run();
}

void render::setNode(char *filename){
    if(nodo == NULL){
        nodo = new nodeMesh(ventana::Instance()->getSceneManager()->addMeshSceneNode(ventana::Instance()->getSceneManager()->getMesh(filename)));
		printf("cargado!\n");
    }
}

void render::dropNode(){
    nodo = NULL;
}

void render::dibujar(){
    ventana::Instance()->getDriver()->beginScene(true, true, SColor(255, 255, 255, 255));
    ventana::Instance()->getSceneManager()->drawAll();
    ventana::Instance()->getDriver()->endScene();
}
