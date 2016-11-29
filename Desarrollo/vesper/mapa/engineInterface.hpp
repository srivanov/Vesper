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
#include "nodeMesh.hpp"
#include "eventReceiver.h"

using namespace irr;
using namespace core;
using namespace video;
using namespace io;
using namespace scene;

class engineInterface{
    public:
		static engineInterface* Instance();
		~engineInterface();
		bool _createDevice(uint32_t ancho, uint32_t alto, uint32_t color, bool fullscreen, bool stencilbuffer, bool vsync, bool receiver);
		bool _Run();
		void _deviceClose();
		bool loadMap();
		void _createCamera(float* posicion, float* target, float* rotation);
		void _setCamPosition(float* posicion);
		void _setCamTarget(float* target);
		void _setCamRotation(float* rotation);
		nodeMesh* _getNode(char* filename);
		nodeMesh*  _getNodeFromMesh(IMesh* mesh);
		bool _setMaterialTexture(nodeMesh* nodo, char* filename);
		void _setMaterialFlag(nodeMesh* node,uint32_t flag, bool value);
		void _beginScene(bool backBuffer, bool zBuffer);
		void _drawAll();
		void _endScene();
        ISceneCollisionManager* getSceneCollisionManager();
    
    void _setNearValue(float nv);
    void _setFarValue(float fv);
    f32 _getFOV();
    void zoomMasFOV();
    f32 zoomMenosFOV();
    
    
	
		void setreceiver(bool active);
		bool isKeyDown(char key);
protected:
	engineInterface();
private:
	IMesh* _getMesh(char* filename);
	static engineInterface* pinstance;
    IrrlichtDevice* device;
    IVideoDriver* driver;
    ISceneManager* smgr;
	ICameraSceneNode* camera;
	MyEventReceiver r;
};
#endif /* engineInterface_hpp */
