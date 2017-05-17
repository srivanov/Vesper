
#include "ventana.hpp"

ventana* ventana::Instance(){
    static ventana pinstance;
    return &pinstance;
}

ventana::ventana(){
//	receiver = MyEventReceiver::Instance();
	window = SkyWindow::Instance();
//	sManager = ShaderManager::Instance();
}

ventana::~ventana(){
	printf("DELETE VENTANA\n");
}

void ventana::crearWindow(uint32_t ancho, uint32_t alto, uint32_t color, bool fullscreen, bool stencilbuffer, bool vsync, bool rec){
//	if(receiver)
//		device = createDevice(EDT_OPENGL, irr::core::dimension2d<u32>(ancho, alto), color, fullscreen, stencilbuffer, vsync, receiver);
//	else
//		device = createDevice(EDT_OPENGL, irr::core::dimension2d<u32>(ancho, alto), color, fullscreen, stencilbuffer, vsync, 0);
	window->crearWindow(dvector2D(ancho,alto),vsync);
	
//	sManager->cargarShader("67", "Shaders/texLight.vs", "Shaders/texLight.frag");
//	ShaderManager::Instance()->setActiveShader("67");
	
//	driver = device->getVideoDriver();
//	smgr = device->getSceneManager();
//	device->setWindowCaption(L"Vesper");
}

//IrrlichtDevice* ventana::getDevice(){
//	return device;
//}
//
//IVideoDriver* ventana::getDriver(){
//	return device->getVideoDriver();
//}
//
//ISceneManager* ventana::getSceneManager(){
//	return device->getSceneManager();
//}

void ventana::deviceDrop(){
//	device->closeDevice();
	window->terminate();
}

dvector3D ventana::posicionRaton(dvector3D &player){
//	return receiver->mouseTo3D(smgr, player);
	return dvector3D(0,0,0);
}

