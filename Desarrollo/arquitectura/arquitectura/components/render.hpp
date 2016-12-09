
#ifndef render_hpp
#define render_hpp

#include <stdio.h>
#include "component.hpp"
#include "ventana.hpp"
//#include <irrlicht.h>
#include "nodeMesh.hpp"
#include "Fps.hpp"
#include <OpenGL/gl.h>

//using namespace irr;

class render : public component {
public:
    render();
    ~render();
	void crearWindow(uint32_t ancho, uint32_t alto, uint32_t color, bool fullscreen, bool stencilbuffer, bool vsync, bool receiver);
	bool run();
    void setNode(char* filename);
    void dropNode();
	void setTexto();
    void dibujar();
	void actualizarRender();
	void addCamera(float* p, float* l);
	void closeWindow();
	
private:
	nodeMesh* nodo;
	ICameraSceneNode* camara;
	irr::gui::IGUIStaticText* texto;
};

#endif /* render_hpp */
