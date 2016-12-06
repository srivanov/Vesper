//
//  render.cpp
//  arquitectura
//
//  Created by Nerea Castellanos Rodríguez on 29/11/16.
//  Copyright © 2016 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "render.hpp"

render::render(){
	window = ventana::Instance();
    device = window->getDevice();
    driver = window->getDriver();
    smgr = window->getSceneManager();
    nodo = NULL;
    
}

render::~render(){
	
}

void render::crearWindow(uint32_t ancho, uint32_t alto, uint32_t color, bool fullscreen, bool stencilbuffer, bool vsync, bool receiver){
	window->crearWindow(ancho, alto, color, fullscreen, stencilbuffer, vsync, receiver);
}

bool render::run(){
	return window->getDevice()->run();
}

void render::setNode(char *filename){
    if(nodo == NULL){
        nodo = new nodeMesh(window->getSceneManager()->addMeshSceneNode(window->getSceneManager()->getMesh(filename)));
        printf("he llegado");
    }
    
}

void render::dropNode(){
    nodo = NULL;
}

void render::dibujar(){
    window->getDriver()->beginScene(true, true, SColor(255, 255, 255, 255));
    window->getSceneManager()->drawAll();
    window->getDriver()->endScene();
}
