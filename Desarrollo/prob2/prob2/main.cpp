#include <irrlicht.h>
#include <Box2D/Box2D.h>
#include "physicsController.hpp"
#include <stdio.h>
#include "inputSFML.hpp"

using namespace irr;
using namespace io;
using namespace core;
using namespace video;
using namespace scene;

#if defined(_MSC_VER)
#pragma comment(lib, "Irrlicht.lib")
#endif

class KeyboardEventReceiver : public IEventReceiver
{
public:
	// This is the one method that we have to implement
	virtual bool OnEvent(const SEvent& event)
	{
		// Remember whether each key is down or up
		if (event.EventType == irr::EET_KEY_INPUT_EVENT)
			KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
		
		if(event.EventType == irr::EET_JOYSTICK_INPUT_EVENT && event.JoystickEvent.Joystick == 0){
			JoystickState = event.JoystickEvent;
		}
		
		return false;
	}
	
	const SEvent::SJoystickEvent & GetJoystickState(void) const{
		return JoystickState;
	}
	
	// This is used to check whether a key is being held down
	virtual bool IsKeyDown(EKEY_CODE keyCode) const
	{
		return KeyIsDown[keyCode];
	}
	
	KeyboardEventReceiver()
	{
		for (u32 i=0; i<KEY_KEY_CODES_COUNT; ++i)
			KeyIsDown[i] = false;
	}
	
private:
	// We use this array to store the current state of each key
	bool KeyIsDown[KEY_KEY_CODES_COUNT];
	SEvent::SJoystickEvent JoystickState;
};


int main()
{
	KeyboardEventReceiver receiver;
	IrrlichtDevice* device = createDevice(EDT_OPENGL, dimension2d<u32>(640, 480), 16, false, false, false, 0);
	if (!device)
		return 1;
	device->setWindowCaption(L"HELLO WORLD");
	
	array<SJoystickInfo> joystickInfo; //create array to load info
	if(device->activateJoysticks(joystickInfo)){ //add active joysticks to my number
	
	}

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
	float vel_aux[3] = {0,0,0};
	float pos_aux[3] = {0,0,0};
    float mFin[2] = {0,0};
	float *vel = vel_aux, *pos = pos_aux, *posmouseFinal = mFin;
    int *posmouse;

	while (device->run())
	{
        
		//printf("\n%.2f\n",node->getAbsolutePosition().X);
        fisicas->Step(vel,pos, posmouseFinal, inputSFML::Instance()->posicionRaton());
        node->setPosition(vector3df(pos[0],pos[1],pos[2]));
//        printf("%.2f\n",posmouseFinal[0]);
//        node->setRotation(vector3df(0,0,posmouseFinal[0]));
        
		driver->beginScene(true, true, SColor(255, 255, 255, 255));
		
		smgr->drawAll();
		
		driver->endScene();
		vel[0] = 0; vel[1] = 0;
//		camera->setTarget(node->getAbsolutePosition());
        printf("%.2f\n",node->getRotation().Z);
		if(joystickInfo.size() > 0)
			printf("tengo mando\n");
		
        if(inputSFML::Instance()->isKeyPressed(36)){
			device->closeDevice();
		}
		if(inputSFML::Instance()->isKeyPressed(22)){
			vel[1] =  3;
//            fisicas->setMoveState(3);
//			node->setPosition(node->getPosition() + vector3df(0,1,0));
		}
		if(inputSFML::Instance()->isKeyPressed(18)){
			vel[1] = -3;
//			fisicas->setMoveState(4);
//			node->setPosition(node->getPosition() + vector3df(0,-1,0));
		}
		if(inputSFML::Instance()->isKeyPressed(0)){
			vel[0] = -3;
//			fisicas->setMoveState(1);
//			node->setPosition(node->getPosition() + vector3df(-1,0,0));
		}
		if(inputSFML::Instance()->isKeyPressed(3)){
			vel[0] =  3;
//			fisicas->setMoveState(2);
//			node->setPosition(node->getPosition() + vector3df(1,0,0));
		}
		if(inputSFML::Instance()->isKeyPressed(57)){
            node->setRotation(vector3df(0,0,posmouseFinal[0]));
			vel[0] = 0; vel[1] = 0;
//			fisicas->setMoveState(0);
//			node->setPosition(node->getPosition() + vector3df(1,0,0));
		}
	}
	
	device->drop();
	return 0;
}
