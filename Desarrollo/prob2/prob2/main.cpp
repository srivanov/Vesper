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
		
		if (event.EventType == irr::EET_MOUSE_INPUT_EVENT)
		{
			p[0] = event.MouseInput.X;
			p[1] = event.MouseInput.Y;
		}
		
		return false;
	}
	
	const SEvent::SJoystickEvent & GetJoystickState(void) const
	{
		return JoystickState;
	}
	
	virtual int* getPosicionMouse() const
	{
		return p;
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
	int* p;
};

int* mouseTo3D(ISceneManager* smgr, ICameraSceneNode* camera, IAnimatedMeshSceneNode* node, int* posicionMouse)
{
	KeyboardEventReceiver receiver;
	int p_aux[2] = {0,0};
	int* p=p_aux;
	// Create a ray through the mouse cursor.
	const vector2di posi(posicionMouse[0], posicionMouse[1]);
	core::line3df ray = smgr->getSceneCollisionManager()->getRayFromScreenCoordinates(posi, camera);
	
	// And intersect the ray with a plane around the node facing towards the camera.
	core::plane3df plane(node->getAbsolutePosition(), core::vector3df(0, 0, -1));
	core::vector3df mousePosition;
	mousePosition.X = posicionMouse[0];
	mousePosition.Y = posicionMouse[1];
	mousePosition.Z = 0;
	if(plane.getIntersectionWithLine(ray.start, ray.getVector(), mousePosition))
	{
		// We now have a mouse position in 3d space; move towards it.
//		core::vector3df toMousePosition(mousePosition - node->getAbsolutePosition());
//		printf("%.2f %.2f\n",toMousePosition.X,toMousePosition.Y);
		
		p[0] = mousePosition.X;
		p[1] = mousePosition.Y;
	}
	return p;
}

int main()
{
	KeyboardEventReceiver receiver;
	IrrlichtDevice* device = createDevice(EDT_OPENGL, dimension2d<u32>(640, 480), 16, false, false, false, &receiver);
	if (!device)
		return 1;
	device->setWindowCaption(L"HELLO WORLD");

	IVideoDriver* driver = device->getVideoDriver();
	ISceneManager* smgr = device->getSceneManager();
	IAnimatedMesh* cubo = smgr->getMesh("../../../modelos3D/sphere.3ds");
	
	if(!cubo)
		printf("\nno se ha cargado el modelo 3D\n");
	
	IAnimatedMeshSceneNode* node = smgr->addAnimatedMeshSceneNode(cubo);
	if(node){
		node->setMaterialFlag(EMF_LIGHTING, false);
		node->setMaterialTexture(0, driver->getTexture("../../../modelos3D/texture.png"));
		node->setPosition(vector3df(0,0,0));
		node->setRotation(vector3df(0,0,0));
	}
	
	ICameraSceneNode* camera = smgr->addCameraSceneNode(0,vector3df(0,-10,-10),vector3df(0,0,0));
	
    physicsController *fisicas = new physicsController();
    fisicas->Footest();
	float vel_aux[3] = {0,0,0};
	float pos_aux[3] = {0,0,0};
    float mFin[2] = {0,0};
	float *vel = vel_aux, *pos = pos_aux, *posmouseFinal = mFin;
	int p_aux[2] = {0,0};
	int *posmouse = p_aux, *posmouse2;

	while (device->run())
	{
		posmouse = receiver.getPosicionMouse();
		posmouse2 = mouseTo3D(smgr, camera, node, posmouse);
        fisicas->Step(vel,pos, posmouseFinal, posmouse2);
//		printf("%d %d\n",posmouse2[0],posmouse2[1]);
		
        node->setPosition(vector3df(pos[0],pos[1],pos[2]));
		
        node->setRotation(vector3df(0,0,posmouseFinal[0]));
		
		driver->beginScene(true, true, SColor(255, 255, 255, 255));
		
		smgr->drawAll();
		
		driver->endScene();
		vel[0] = 0; vel[1] = 0;
		
        if(inputSFML::Instance()->isKeyPressed(36)){
			device->closeDevice();
		}
		if(inputSFML::Instance()->isKeyPressed(22)){
			vel[1] =  1;
//			node->setPosition(node->getPosition() + vector3df(0,1,0));
		}
		if(inputSFML::Instance()->isKeyPressed(18)){
			vel[1] = -1;
//			node->setPosition(node->getPosition() + vector3df(0,-1,0));
		}
		if(inputSFML::Instance()->isKeyPressed(0)){
			vel[0] = -1;
//			node->setPosition(node->getPosition() + vector3df(-1,0,0));
		}
		if(inputSFML::Instance()->isKeyPressed(3)){
			vel[0] =  1;
//			node->setPosition(node->getPosition() + vector3df(1,0,0));
		}
		if(inputSFML::Instance()->isKeyPressed(57)){
			vel[0] = 0; vel[1] = 0;
//			node->setRotation(vector3df(0,0,node->getRotation().Z+1));
//			node->setPosition(node->getPosition() + vector3df(1,0,0));
		}
	}
	
	device->drop();
	return 0;
}
