//
//  render.hpp
//  arquitectura
//
//  Created by Nerea Castellanos Rodríguez on 29/11/16.
//  Copyright © 2016 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef render_hpp
#define render_hpp

#include <stdio.h>
#include "component.hpp"
#include "ventana.hpp"
//#include <irrlicht.h>
#include "nodeMesh.hpp"

//using namespace irr;

class render : public component {
public:
    render();
    ~render();
	void crearWindow(uint32_t ancho, uint32_t alto, uint32_t color, bool fullscreen, bool stencilbuffer, bool vsync, bool receiver);
	bool run();
    void setNode(char* filename);
    void dropNode();
    void dibujar();
	
private:
	nodeMesh* nodo;
	
//	ventana* ventanita;
//    IrrlichtDevice* device;
//    IVideoDriver* driver;
//    ISceneManager* smgr;
	
    
};

#endif /* render_hpp */
