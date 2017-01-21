
#include "ventana.hpp"

ventana* ventana::pinstance = 0;

ventana* ventana::Instance(){
	if(pinstance == 0)
		pinstance = new ventana();
	return pinstance;
}

ventana::ventana(){
	receiver = MyEventReceiver::Instance();
}

ventana::~ventana(){
	printf("DELETE ventana\n");
//	delete receiver;
//	delete smgr;
//	delete driver;
//	delete device;
	delete pinstance;
}

void ventana::crearWindow(uint32_t ancho, uint32_t alto, uint32_t color, bool fullscreen, bool stencilbuffer, bool vsync, bool rec){
	if(receiver)
		device = createDevice(EDT_OPENGL, irr::core::dimension2d<u32>(ancho, alto), color, fullscreen, stencilbuffer, vsync, receiver);
	else
		device = createDevice(EDT_OPENGL, irr::core::dimension2d<u32>(ancho, alto), color, fullscreen, stencilbuffer, vsync, 0);
	
	driver = device->getVideoDriver();
	smgr = device->getSceneManager();
	device->setWindowCaption(L"Vesper");
}

IrrlichtDevice* ventana::getDevice(){
	return device;
}

IVideoDriver* ventana::getDriver(){
	return device->getVideoDriver();
}

ISceneManager* ventana::getSceneManager(){
	return device->getSceneManager();
}

void ventana::deviceDrop(){
	device->closeDevice();
}

dvector3D ventana::posicionRaton(dvector3D &player){
	return receiver->mouseTo3D(smgr, player);
}

