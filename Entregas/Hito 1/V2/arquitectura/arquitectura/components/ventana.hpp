
#ifndef ventana_hpp
#define ventana_hpp

#include <stdio.h>
#include <irrlicht.h>
#include "../MyEventReceiver.hpp"

using namespace irr;
using namespace video;
using namespace scene;

class ventana {
public:
	static ventana* Instance();
	virtual ~ventana();
	
	void crearWindow(uint32_t ancho, uint32_t alto, uint32_t color, bool fullscreen, bool stencilbuffer, bool vsync, bool rec);
	IrrlichtDevice* getDevice();
	IVideoDriver* getDriver();
	ISceneManager* getSceneManager();
	void deviceDrop();
	float* posicionRaton(float* player);
	
protected:
	ventana();
private:
	static ventana* pinstance;
	IrrlichtDevice* device;
	IVideoDriver* driver;
	ISceneManager* smgr;
	MyEventReceiver *receiver;
};

#endif /* ventana_hpp */
