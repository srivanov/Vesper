
#ifndef render_hpp
#define render_hpp

#include <stdio.h>
#include "component.hpp"
#include "ventana.hpp"
#include "../nodeMesh.hpp"
#include "../Fps.hpp"
#include "../Dvector.hpp"

class nivel;
class render : public component {
public:
    render();
    ~render();
	void update() override;
	
	void crearWindow(uint32_t ancho, uint32_t alto, uint32_t color, bool fullscreen, bool stencilbuffer, bool vsync, bool receiver);
	bool run();
    void setNode(char* filename);
	void setNodeTexture(char* filename);
	bool setNodePosition(dvector3D &pos);
	bool setNodeRotation(dvector3D &rot);
    void dropNode();
	void deleteNode();
	void setTexto();
    void dibujar();
	void addCamera(dvector3D &p, dvector3D &l);
	void closeWindow();
	void dibujarMapa();
	void setCamPos(dvector3D &pos);
	dvector3D* getCamPos();
	void setCamTarget(dvector3D &pos);
	
private:
	nodeMesh* nodo;
	ICameraSceneNode* camara;
	irr::gui::IGUIStaticText* texto;
};

#endif /* render_hpp */
