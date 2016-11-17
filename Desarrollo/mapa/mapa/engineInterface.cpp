//
//  engineInterface.cpp
//  mapa
//
//  Created by Julia Martínez Valera on 17/11/16.
//  Copyright © 2016 Julia Martínez Valera. All rights reserved.
//

#include "engineInterface.hpp"

engineInterface::engineInterface(){
    
}

engineInterface::~engineInterface(){
    
}

bool engineInterface::_createDevice(uint32_t ancho, uint32_t alto, uint32_t color, bool fullscreen, bool stencilbuffer, bool vsync){
   
    device = createDevice(EDT_OPENGL, dimension2d<u32>(ancho, alto), color, fullscreen, stencilbuffer, vsync, 0);
    if(!device){
        return false;
    }
    driver = device->getVideoDriver();
    smgr = device->getSceneManager();
    
    return true;
}

bool engineInterface::_Run(){
    return device->run();
}
void engineInterface::_deviceDrop(){
    device->drop();
}

bool engineInterface::_getMesh(char* filename){
    IMesh* object = smgr->getMesh(filename);
    
    if(!object)
        return false;
    
    return true;
}

bool engineInterface::loadMap(){
    //loadMesh("../../../mapa/3d/muro.3ds");
    IMesh* muro = smgr->getMesh("../../../mapa/3d/muro.3ds");
    IMesh* muro2 = smgr->getMesh("../../../mapa/3d/muro.3ds");
    IMesh* suelo = smgr->getMesh("../../../mapa/3d/suelo.3ds");
   
    if(!muro){
        printf("muro no cargado\n");
        return false;
    }
    if(!suelo){
        printf("suelo no cargado\n");
        return false;
    }
   
    smgr->addCameraSceneNode(0,vector3df(0,-100,-150),vector3df(0,50,-40));  /////(0,-5,10)-(0,6,0)////posicion de la camra, y donde tiene q mirar
    cargarMapa * map = new cargarMapa();
    
    map->leerMapa();
    map->mostrarMatriz();
    int*** mapita;
    
    mapita = map->getMatriz();
    IMeshSceneNode* nodo;
    IMeshSceneNode* nodor;
    IMeshSceneNode* nodo_suelo;
    
    if(map->getHeight() < 0 || map->getWidth() < 0)
        return false;
    
    for(int i=0; i<map->getHeight();i++){
        for(int j=0; j<map->getWidth(); j++){
            if(mapita[0][i][j] == 21){
                nodo = smgr->addMeshSceneNode(muro);
                nodo->setMaterialFlag(EMF_LIGHTING, false);
                nodo->setMaterialTexture(0, driver->getTexture("../../../mapa/3d/rocas.jpg"));
                nodo->setPosition(vector3df(i,j,0));
                nodo = NULL;
            }
            if(mapita[0][i][j] == 9){
                nodor = smgr->addMeshSceneNode(muro2);
                nodor->setMaterialFlag(EMF_LIGHTING, false);
                nodor->setMaterialTexture(0, driver->getTexture("../../../mapa/3d/rocas.jpg"));
                nodor->setPosition(vector3df(i,j,0));
                nodor = NULL;
            }
            
            if(mapita[0][i][j] == 86){
                nodo_suelo = smgr->addMeshSceneNode(suelo);
                nodo_suelo->setMaterialFlag(EMF_LIGHTING, false);
                nodo_suelo->setMaterialTexture(0, driver->getTexture("../../../mapa/3d/verde.jpg"));
                nodo_suelo->setPosition(vector3df(i,j,0));
                nodo_suelo = NULL;
            }
        }
    }
    return true;
}

void engineInterface::_beginScene(bool backBuffer, bool zBuffer){
    driver->beginScene(backBuffer, zBuffer, SColor(255, 255, 255, 255));
}
void engineInterface::_drawAll(){
    smgr->drawAll();
}
void engineInterface::_endScene(){
    driver->endScene();
}
