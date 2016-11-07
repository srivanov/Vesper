//
//  main.cpp
//  mapa
//
//  Created by Julia Martínez Valera on 5/11/16.
//  Copyright © 2016 Julia Martínez Valera. All rights reserved.
//

#include <stdio.h>
#include <irrlicht.h>
#include <Box2D/Box2D.h>

#include "cargarMapa.hpp"
//#include "tinyxml2.h"

using namespace irr;
using namespace core;
using namespace video;
using namespace io;
using namespace scene;

//PARA USAR LA VARIABLE RECEIVER EN EL MAIN
class MyEventReceiver : public IEventReceiver
{
public:
    // This is the one method that we have to implement
    virtual bool OnEvent(const SEvent& event)
    {
        // Remember whether each key is down or up
        if (event.EventType == irr::EET_KEY_INPUT_EVENT)
            KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
        
        return false;
    }
    
    // This is used to check whether a key is being held down
    virtual bool IsKeyDown(EKEY_CODE keyCode) const
    {
        return KeyIsDown[keyCode];
    }
    
    MyEventReceiver()
    {
        for (u32 i=0; i<KEY_KEY_CODES_COUNT; ++i)
            KeyIsDown[i] = false;
    }
    
private:
    // We use this array to store the current state of each key
    bool KeyIsDown[KEY_KEY_CODES_COUNT];
};


int main(){
    MyEventReceiver receiver;
    IrrlichtDevice* device = createDevice(EDT_OPENGL, dimension2d<u32>(640, 480), 16, false, false, false, &receiver);
    if (!device)
        return 1;
    IVideoDriver* driver = device->getVideoDriver();
    device->setWindowCaption(L"Mapa");
    ISceneManager* smgr = device->getSceneManager();
    IMesh* muro = smgr->getMesh("../../../mapa/3d/muro.3ds");
    
    if(!muro){
        printf("muro no cargado\n");
    }
    
    cargarMapa * map = new cargarMapa();
   // map = new cargarMapa();
    map->leerMapa();
    
//    IMeshSceneNode* nodo;
//    for(int i=0; i<map->getWidth();i++){
//        for(int j=0; j<map->getHeight(); j++){
//            
//        }
//    }
//    
//    IMeshSceneNode* nodo = smgr->addMeshSceneNode(muro);
//    if(nodo){
//        nodo->setMaterialTexture(0, driver->getTexture("../../../mapa/3d/rocas.jpg"));
//        nodo->setPosition(vector3df(0,0,0));
//    }
    
    while (device->run())
    {
        driver->beginScene(true, true, SColor(255, 255, 255, 255));
        smgr->drawAll();
        driver->endScene();
        
        if(receiver.IsKeyDown(irr::KEY_ESCAPE)){
            break;
        }
    }
    
    device->drop();
    return 0;
    
}


