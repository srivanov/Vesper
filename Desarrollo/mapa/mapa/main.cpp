//
//  main.cpp
//  mapa
//
//  Created by Julia Martínez Valera on 5/11/16.
//  Copyright © 2016 Julia Martínez Valera. All rights reserved.
//

#include <stdio.h>
//#include <irrlicht.h>
#include <Box2D/Box2D.h>
#include "engineInterface.hpp"
//#include "cargarMapa.hpp"

//#include "tinyxml2.h"

/*using namespace irr;
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
*/

int main(){
    engineInterface* interfaceIrr = new engineInterface();
    interfaceIrr->_createDevice(640, 480, 18, false, false, false);
    
    interfaceIrr->loadMap();
    
    while(interfaceIrr->_Run()){
        interfaceIrr->_beginScene(true, true);
        interfaceIrr->_drawAll();
        interfaceIrr->_endScene();
    }
    interfaceIrr->_deviceDrop();
    
    /*MyEventReceiver receiver;
                                                        //primer booleano, true para pantalla completa, false para no.
    IrrlichtDevice* device = createDevice(EDT_OPENGL, dimension2d<u32>(640, 480), 16, true, false, false, &receiver);
    if (!device)
        return 1;
    IVideoDriver* driver = device->getVideoDriver();
    device->setWindowCaption(L"Mapa");
    ISceneManager* smgr = device->getSceneManager();
    printf("1\n");
    IMesh* muro = smgr->getMesh("../../../mapa/3d/muro.3ds");
    IMesh* muro2 = smgr->getMesh("../../../mapa/3d/muro.3ds");
    IMesh* suelo = smgr->getMesh("../../../mapa/3d/suelo.3ds");
     printf("2\n");
    if(!muro){
        printf("muro no cargado\n");
    }
    if(!suelo){
        printf("suelo no cargado\n");
    }
     printf("3\n");
    smgr->addCameraSceneNode(0,vector3df(0,-100,-150),vector3df(0,50,-40));  /////(0,-5,10)-(0,6,0)////posicion de la camra, y donde tiene q mirar
    cargarMapa * map = new cargarMapa();
   // map = new cargarMapa();
    map->leerMapa();
    map->mostrarMatriz();
    int*** mapita;
     printf("4\n");
    mapita = map->getMatriz();
    IMeshSceneNode* nodo;
    IMeshSceneNode* nodor;
    IMeshSceneNode* nodo_suelo;
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
            device->closeDevice();
        }
    }
    
    device->drop();
    return 0;
    */
}


