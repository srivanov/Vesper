
#include <stdio.h>
#include <irrlicht.h>
#include <stdint.h>
#include "Dvector.hpp"

using namespace irr;

#ifndef MyEventReceiver_hpp
#define MyEventReceiver_hpp

class MyEventReceiver : public IEventReceiver
{
public:
	static MyEventReceiver* Instance();
	virtual bool OnEvent(const SEvent& event);
	virtual bool IsKeyDown(EKEY_CODE keyCode) const;
	~MyEventReceiver();
	dvector3D mouseTo3D(irr::scene::ISceneManager* smgr, dvector3D &node);
	bool getLeftClick();
	const dvector2D* getMousePosition();
protected:
	MyEventReceiver();
private:
	// We use this array to store the current state of each key
	bool KeyIsDown[KEY_KEY_CODES_COUNT];
	dvector2D pos_Mouse;
	bool clickL;
};

#endif /* MyEventReceiver_hpp */
