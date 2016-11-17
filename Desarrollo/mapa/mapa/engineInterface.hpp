//
//  engineInterface.hpp
//  mapa
//
//  Created by Julia Martínez Valera on 17/11/16.
//  Copyright © 2016 Julia Martínez Valera. All rights reserved.
//

#ifndef engineInterface_hpp
#define engineInterface_hpp

#include <stdio.h>
#include <irrlicht.h>
#include "cargarMapa.hpp"

using namespace irr;
using namespace core;
using namespace video;
using namespace io;
using namespace scene;

class engineInterface{
    public:
    engineInterface();
    ~engineInterface();
    bool _createDevice(uint32_t ancho, uint32_t alto, uint32_t color, bool fullscreen, bool stencilbuffer, bool vsync);
    bool _Run();
    void _deviceDrop();
    bool loadMap();
    bool _getMesh(char* filename);
    void _beginScene(bool backBuffer, bool zBuffer);
    void _drawAll();
    void _endScene();
    
private:
    IrrlichtDevice* device;
    IVideoDriver* driver;
    ISceneManager* smgr;
    
};
#endif /* engineInterface_hpp */
