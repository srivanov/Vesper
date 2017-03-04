
#ifndef GameObject_hpp
#define GameObject_hpp

#include <stdio.h>
#include <map>
//#include "component.hpp"

//#include "../components/armasArrojadizas.hpp"
//#include "../components/armasDisparo.hpp"
#include "../components/ataque.hpp"
#include "../components/habilidadEspecial.hpp"
#include "../components/hambre.hpp"
#include "../components/IACamara.hpp"
#include "../components/IAEnemigos.hpp"
#include "../components/input.hpp"
//#include "../components/martilloDeJuguete.hpp"
#include "../components/transform3D.hpp"
#include "../components/Physics.hpp"
//#include "../components/piedra.hpp"
#include "../components/render.hpp"
#include "../components/salud.hpp"
#include "../components/sed.hpp"
#include "../Dvector.hpp"

using namespace std;

//TO DO: mantener actualizado
enum typeObj{
	tHabNO_TYPE = -1,
	tALARMA,
	tPALA,
	tCAMARA,
	tENEMIGOS,
	tNIVEL,
	tMONEDAS,
	tPLAYER,
	tPUERTA,
	tBALA,
	tBOTIQUIN,
	tCOMIDA,
	tFUENTE,
	tLLAVE,
	tPIEDRA,
    tESCOPETA,
    tLANZACARAMELOS,
    tGLOBOAGUA,
    tCHICLE,
    tBOMBAHUMO,
    tREHEN
};

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
	
	dvector3D* getPosicion();
    void setPosicion(dvector3D p3D);
	void setRotacion(float rot);
	void rotarConRaton(dvector3D &posRaton);
	dvector3D* getRotacion();
	dvector3D* getDirDisparo();
	void setDirDisparo(dvector3D &dir);
	
	void mover(dvector3D &vel);
    virtual void render(float &interpolation);
    virtual void update();
	
    void addNodo(char* filename);
	void setTexture(char* filename);
	
	void setType(typeObj t);
	typeObj const* getType();
	
	virtual void contacto(GameObject* g){};
    virtual void contactoEnd(GameObject* g){};
    virtual bool const* getmuero() = 0;
    void setID(int &ID) { this->ID = ID; }
	int getID() { return ID; }
protected:
    bool renderizable, first = true;
    dvector3D posicion, prev_pos, rotacion, anguloDisparo;
	int ID;
private:
	//TO DO: crear el vector con componentes y no punteros
    std::map<char*, component*> components;
	typeObj tipo;
};

#endif /* GameObject_hpp */
