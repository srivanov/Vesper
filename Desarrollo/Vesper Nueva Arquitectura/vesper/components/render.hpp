
#ifndef render_hpp
#define render_hpp

#include <stdio.h>
#include "component.hpp"
#include "ventana.hpp"
#include <vector>
//#include "../nodeMesh.hpp"
#include <SkyEngine/SkyEngine.hpp>
//#include <SkyEngine/SkyMalla.hpp>
//#include <SkyEngine/SkyCamara.hpp>
#include "../Fps.hpp"
#include "../Dvector.hpp"

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
    void CreateGround(int alto, int ancho);
	void deleteNode();
	void setTexto();
    void dibujar();
    void beginDraw();
    void endDraw();
	void addCamera(dvector3D &p, dvector3D &l);
	void closeWindow();
	void dibujarMuro(int*tilemap,int anchoMapa, int altoMapa);
	void setCamPos(dvector3D &pos);
	dvector3D* getCamPos();
	void setCamTarget(dvector3D &pos);
    void anyadirArma();
	
private:
	SkyEngine* engine;
//    std::vector<nodeMesh*> all_nodos;
	std::vector<SkyMalla*> all_nodos;
	ventana* vent;
//	nodeMesh* nodo;
	SkyMalla *nodo, *nodo_suelo;
//	ICameraSceneNode* camara;
	SkyCamara* camara;
//    ISceneNode* nodo_suelo;
//	irr::gui::IGUIStaticText* texto;
};

#endif /* render_hpp */
