
#ifndef GameObject_hpp
#define GameObject_hpp

#include <stdio.h>
#include <map>
//#include "component.hpp"

//#include "../components/armasArrojadizas.hpp"
//#include "../components/armasDisparo.hpp"
#include "../components/ataque.hpp"
#include "../components/blindada.hpp"
#include "../components/bloqueada.hpp"
#include "../components/chirriante.hpp"
#include "../components/conAlarma.hpp"
#include "../components/conLlave.hpp"
#include "../components/conPuzzle.hpp"
#include "../components/destructiva.hpp"
#include "../components/habilidadEspecial.hpp"
#include "../components/hambre.hpp"
#include "../components/IACamara.hpp"
#include "../components/IAEnemigos.hpp"
#include "../components/input.hpp"
#include "../components/martilloDeJuguete.hpp"
#include "../components/transform3D.hpp"
#include "../components/pala.hpp"
#include "../components/Physics.hpp"
#include "../components/piedra.hpp"
#include "../components/render.hpp"
#include "../components/salud.hpp"
#include "../components/sed.hpp"

using namespace std;

class component;

class GameObject{
public:
    GameObject();
    ~GameObject();
	
	//COMPONENTES
    void insertComponent(char* nombre, component *comp);
    void eraseComponent(char* nombre);
    component* findComponent(char* nombre);
	std::map<char*,component*>::iterator getIteradorBegin();
	std::map<char*,component*>::iterator getIteradorEnd();
	void clearComponents();
	
    bool getRenderizable();
    void setRenderizable(bool r);
	
	float* getPosicion();
    void setPosicion(float* p3D);
	void setRotacion(float* rot);
	float* getRotacion();
	float* getDirDisparo();
	
	void mover(float* vel);
    void render();
    virtual void update();
	
    void addNodo(char* filename);
	void setTexture(char* filename);
    
protected:
    bool renderizable;
    float* posicion;
	float* rotacion;
	float* anguloDisparo;
private:
    std::map<char*, component*> components;
};

#endif /* GameObject_hpp */
