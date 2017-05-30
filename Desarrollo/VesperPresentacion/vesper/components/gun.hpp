
#ifndef gun_hpp
#define gun_hpp

#include <stdio.h>
#include <string>
#include "../tiempo.h"
#include "../objetos/GameObject.hpp"
#include "../Dvector.hpp"
#include <vector>
#include "../objetos/PhysicObjects/Bala.hpp"
#include "typeArma.hpp"

struct cualidades {
    typeArma tipo;
    unsigned int municion ;
    float alcance ;
    float recarga ;
    unsigned int cadencia ;
    unsigned int cargador ;
};

class gun {
public:
	gun(const typeArma t);
    ~gun();
	void atacar(dvector3D &pos, dvector3D &dir);
	unsigned int getMunicion();
    unsigned int getCarga();
	void setMunicion(unsigned int n);
	void update();
    typeArma getType(){return cualidad.tipo;}
    void insertBala(dvector3D &pos, dvector3D &dir, float vel);
    void render(float &interpolation);
    
private:
	float tiempo_vida;
    cualidades cualidad;
	tiempo temp;
    unsigned int carga_max;
    std::vector<Bala*> balas;
    Bala* bala_aux;
    std::vector<Bala*>::iterator iter;
    
};

#endif /* gun_hpp */
