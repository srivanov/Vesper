
#ifndef GameObject_hpp
#define GameObject_hpp

#include <stdio.h>
#include <map>
//#include "component.hpp"

#include "armasArrojadizas.hpp"
#include "armasDisparo.hpp"
#include "ataque.hpp"
#include "blindada.hpp"
#include "bloqueada.hpp"
#include "chirriante.hpp"
#include "conAlarma.hpp"
#include "conLlave.hpp"
#include "conPuzzle.hpp"
#include "destructiva.hpp"
#include "habilidadEspecial.hpp"
#include "hambre.hpp"
#include "IACamara.hpp"
#include "IAEnemigos.hpp"
#include "input.hpp"
#include "martilloDeJuguete.hpp"
#include "transform3D.hpp"
#include "pala.hpp"
#include "Physics.hpp"
#include "piedra.hpp"
#include "render.hpp"
#include "salud.hpp"
#include "sed.hpp"

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
