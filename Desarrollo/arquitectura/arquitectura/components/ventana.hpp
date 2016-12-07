//
//  window.hpp
//  arquitectura
//
//  Created by Stoycho Ivanov Atanasov on 2/12/16.
//  Copyright © 2016 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef ventana_hpp
#define ventana_hpp

#include <stdio.h>
#include <irrlicht.h>
#include "MyEventReceiver.hpp"

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
