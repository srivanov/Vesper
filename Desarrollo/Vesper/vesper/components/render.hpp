
#ifndef render_hpp
#define render_hpp

#include <stdio.h>
#include "component.hpp"
#include "ventana.hpp"
#include <vector>
#include <string>
#include <SkyEngine/SkyEngine.hpp>
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
    void changeNode(char* filename);
    void CreateGround(int alto, int ancho);
	void deleteNode();
    void dibujar();
    void beginDraw();
	void DrawNode(dvector3D &prev_pos, dvector3D &next_pos, dvector3D &prev_rot, dvector3D &next_rot, float &interpolation);
    void endDraw();
	void addCamera(dvector3D &p, dvector3D &l);
	void closeWindow();
	void dibujarMuro(int*tilemap,int anchoMapa, int altoMapa);
	void setCamPos(dvector3D &spos);
	dvector3D* getCamPos();
	void setCamTarget(dvector3D pos);
    void anyadirArma();
    bool m_animada;
    void addAnimation(std::string ruta, std::string nombre, float time);
    void changeAnimation(std::string anim);
    void AnimateNode(bool r){m_animada=r;}
private:
    std::string actual;
	SkyEngine* engine;
    std::vector<SkyMalla*> all_nodos;
	ventana* vent;
	SkyMalla *nodo_suelo;
    SkyNodo *nodo;
	SkyCamara* camara;
	SkyLuz* luz;
	dvector3D cam_pos;
	SkyMalla* creaNodo(char* malla, char* textura, tipoMalla t, SkyNodo* padre);
};

#endif /* render_hpp */
