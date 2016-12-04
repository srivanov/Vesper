//
//  window.cpp
//  arquitectura
//
//  Created by Stoycho Ivanov Atanasov on 2/12/16.
//  Copyright © 2016 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "ventana.hpp"

ventana* ventana::pinstance = 0;

ventana* ventana::Instance(){
	if(pinstance == 0)
		pinstance = new ventana();
	return pinstance;
}

ventana::ventana(){
	r = MyEventReceiver::Instance();
}

ventana::~ventana(){
	delete r;
}

void ventana::crearWindow(uint32_t ancho, uint32_t alto, uint32_t color, bool fullscreen, bool stencilbuffer, bool vsync, bool receiver){
	if(receiver)
		device = createDevice(EDT_OPENGL, irr::core::dimension2d<u32>(ancho, alto), color, fullscreen, stencilbuffer, vsync, r);
	else
		device = createDevice(EDT_OPENGL, irr::core::dimension2d<u32>(ancho, alto), color, fullscreen, stencilbuffer, vsync, 0);
	
	driver = device->getVideoDriver();
	smgr = device->getSceneManager();
	device->setWindowCaption(L"HOLA");
}

IrrlichtDevice* ventana::getDevice(){
	return device;
}

IVideoDriver* ventana::getDriver(){
	return driver;
}

ISceneManager* ventana::getSceneManager(){
	return smgr;
}

void ventana::deviceDrop(){
	device->closeDevice();
}


