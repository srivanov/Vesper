
#include "MyEventReceiver.hpp"

MyEventReceiver* MyEventReceiver::pinstance = 0;

MyEventReceiver* MyEventReceiver::Instance(){
	if(pinstance == 0)
		pinstance = new MyEventReceiver();
	return pinstance;
}

MyEventReceiver::MyEventReceiver()
{
	for (u32 i=0; i<KEY_KEY_CODES_COUNT; ++i)
		KeyIsDown[i] = false;
    
    pos_Mouse;
	clickL = false;
}

MyEventReceiver::~MyEventReceiver(){
	printf("DELETE receiver\n");
	delete pinstance;
}

// This is the one method that we have to implement
bool MyEventReceiver::OnEvent(const SEvent& event)
{
	// Remember whether each key is down or up
	if (event.EventType == irr::EET_KEY_INPUT_EVENT)
		KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
	
	if (event.EventType == irr::EET_MOUSE_INPUT_EVENT)
	{
		pos_Mouse.x = event.MouseInput.X;
		pos_Mouse.y = event.MouseInput.Y;
		
		if(event.MouseInput.Event == irr::EMIE_LMOUSE_PRESSED_DOWN)
			clickL = true;
		if(event.MouseInput.Event == irr::EMIE_LMOUSE_LEFT_UP)
			clickL = false;
	}
	
	return false;
}

// This is used to check whether a key is being held down
bool MyEventReceiver::IsKeyDown(uint32_t keyCode) const
{
	EKEY_CODE key;
	switch (keyCode) {
		case 'W':
			key = EKEY_CODE::KEY_KEY_W;
			break;
		case 'S':
			key = EKEY_CODE::KEY_KEY_S;
			break;
		case 'A':
			key = EKEY_CODE::KEY_KEY_A;
			break;
		case 'D':
			key = EKEY_CODE::KEY_KEY_D;
			break;
		case 'L':
			key = EKEY_CODE::KEY_KEY_L;
			break;
		case 'Q':
			key = EKEY_CODE::KEY_KEY_Q;
			break;
        case 'O':
            key = EKEY_CODE::KEY_KEY_O;
            break;
        case 'P':
            key = EKEY_CODE::KEY_KEY_P;
            break;
		case 't':
			key = EKEY_CODE::KEY_TAB;
			break;
		case 's':
			key = EKEY_CODE::KEY_SHIFT;
			break;
		default:
			return false;
			break;
	}
	return KeyIsDown[key];
}

dvector3D* MyEventReceiver::mouseTo3D(irr::scene::ISceneManager* smgr, dvector3D &node)
{
    dvector3D p(0,0,0);
	// Create a ray through the mouse cursor.
	const irr::core::vector2di posi(pos_Mouse.x, pos_Mouse.y);
	core::line3df ray = smgr->getSceneCollisionManager()->getRayFromScreenCoordinates(posi, smgr->getActiveCamera());
	
	// And intersect the ray with a plane around the node facing towards the camera.
	core::plane3df plane(core::vector3df(node.x, node.y, node.z), core::vector3df(0, 0, -1));
	core::vector3df mousePosition;
	mousePosition.X = pos_Mouse.x;
	mousePosition.Y = pos_Mouse.y;
	mousePosition.Z = 0;
	if(plane.getIntersectionWithLine(ray.start, ray.getVector(), mousePosition))
	{
		// We now have a mouse position in 3d space; move towards it.
		//		core::vector3df toMousePosition(mousePosition - node->getAbsolutePosition());
		//		printf("%.2f %.2f\n",toMousePosition.X,toMousePosition.Y);
		
		p.x = mousePosition.X;
		p.y = mousePosition.Y;
	}
	return &p;
}

bool MyEventReceiver::getLeftClick(){
	return clickL;
}

