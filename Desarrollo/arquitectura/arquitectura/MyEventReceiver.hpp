
#include <stdio.h>
#include <irrlicht.h>

using namespace irr;

#ifndef MyEventReceiver_hpp
#define MyEventReceiver_hpp

class MyEventReceiver : public IEventReceiver
{
public:
	static MyEventReceiver* Instance();
	virtual bool OnEvent(const SEvent& event);
	virtual bool IsKeyDown(uint32_t keyCode) const;
	~MyEventReceiver();
protected:
	MyEventReceiver();
private:
	static MyEventReceiver* pinstance;
	// We use this array to store the current state of each key
	bool KeyIsDown[KEY_KEY_CODES_COUNT];
};

#endif /* MyEventReceiver_hpp */
