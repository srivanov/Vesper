
#include <irrlicht.h>

using namespace irr;

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
	virtual bool IsKeyDown(uint32_t keyCode) const
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
            case 'P':
                key = EKEY_CODE::KEY_KEY_P;
                break;
            case 'O':
                key = EKEY_CODE::KEY_KEY_O;
                break;
			default:
				return false;
				break;
		}
		return KeyIsDown[key];
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
