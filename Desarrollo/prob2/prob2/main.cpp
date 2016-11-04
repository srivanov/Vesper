#include <irrlicht.h>
#include <Box2D/Box2D.h>
#include "physicsController.hpp"
#include <stdio.h>

using namespace irr;
using namespace io;
using namespace core;
using namespace video;
using namespace scene;

#if defined(_MSC_VER)
#pragma comment(lib, "Irrlicht.lib")
#endif

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


int main()
{
	
	MyEventReceiver receiver;
	IrrlichtDevice* device = createDevice(EDT_OPENGL, dimension2d<u32>(640, 480), 16, false, false, false, &receiver);
	if (!device)
		return 1;
	device->setWindowCaption(L"HELLO WORLD");
	
	IVideoDriver* driver = device->getVideoDriver();
	ISceneManager* smgr = device->getSceneManager();
	IAnimatedMesh* cubo = smgr->getMesh("../../../modelos3D/sydney.md2");
	
	if(!cubo)
		printf("\nno se ha cargado el modelo 3D\n");
	
	IAnimatedMeshSceneNode* node = smgr->addAnimatedMeshSceneNode(cubo);
	if(node){
		node->setMaterialFlag(EMF_LIGHTING, false);
		node->setMaterialTexture(0, driver->getTexture("../../../modelos3D/sydney.bmp"));
		node->setPosition(vector3df(0,0,0));
	}
	
	ICameraSceneNode* camera = smgr->addCameraSceneNode(0,vector3df(0,-10,-150),vector3df(0,0,0));
	
    physicsController *fisicas = new physicsController();
    fisicas->Footest();
    float* p;
	while (device->run())
	{
        
        p = fisicas->Step();
        node->setPosition(vector3df(p[0],p[1],0));
		driver->beginScene(true, true, SColor(255, 255, 255, 255));
		
		smgr->drawAll();
		
		driver->endScene();
		
//		camera->setTarget(node->getAbsolutePosition());
		
		if(receiver.IsKeyDown(irr::KEY_ESCAPE)){
			break;
		}
		if(receiver.IsKeyDown(irr::KEY_KEY_W)){
            fisicas->setMoveState(0);
			//node->setPosition(node->getPosition() + vector3df(0,1,0));
		}
		if(receiver.IsKeyDown(irr::KEY_KEY_S)){
			
			//node->setPosition(node->getPosition() + vector3df(0,-1,0));
		}
		if(receiver.IsKeyDown(irr::KEY_KEY_A)){
			fisicas->setMoveState(1);
			//node->setPosition(node->getPosition() + vector3df(-1,0,0));
		}
		if(receiver.IsKeyDown(irr::KEY_KEY_D)){
			fisicas->setMoveState(2);
			//node->setPosition(node->getPosition() + vector3df(1,0,0));
		}
	}
	
	device->drop();
	return 0;
}
