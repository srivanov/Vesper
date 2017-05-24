
#ifndef ventana_hpp
#define ventana_hpp

#include <stdio.h>
#include <SkyEngine/SkyWindow.hpp>
#include "../Dvector.hpp"

class ventana {
public:
	static ventana* Instance();
	virtual ~ventana();
	
	void crearWindow(uint32_t ancho, uint32_t alto, uint32_t color, bool fullscreen, bool stencilbuffer, bool vsync, bool rec);
//	IrrlichtDevice* getDevice();
//	IVideoDriver* getDriver();
//	ISceneManager* getSceneManager();
	bool isRunning() { return window->isRunning(); }
	void deviceDrop();
	dvector3D posicionRaton(dvector3D &player);
	void beginDraw() { window->beginDraw(); }
	void endDraw() { window->endDraw(); }
	
	const dvector2D* getSize() { return window->getSIZE(); }
	
protected:
	ventana();
private:
	SkyWindow* window;
//	IrrlichtDevice* device;
//	IVideoDriver* driver;
//	ISceneManager* smgr;
//	MyEventReceiver *receiver;
};

#endif /* ventana_hpp */
