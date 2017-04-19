
#ifndef gun_hpp
#define gun_hpp

#include <stdio.h>
#include <string>
#include "../tiempo.h"
#include "../objetos/GameObject.hpp"
#include "Dvector.hpp"
#include <vector>
#include "bala.hpp"

enum typeArma{
    tArmaNO_TYPE = VOID,
    tPISTOLA,
    tESCOPETA = ESCOPETA,
    tLANZACARAMELOS = SWEET_SHOOTER,
    tPIEDRA = PIEDRA,
    tGLOBOAGUA = GLOBO_AGUA,
    tCHICLE = BUMMER_BOOM,
    tBOMBAHUMO = BOMBA_HUMO,
    tMARTILLO,
    tPALA = PALA
};

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
	void setMunicion(unsigned int n);
	void update();
    typeArma const* getType();
    void insertBala(dvector3D &pos, dvector3D &dir, float vel);
    void render();
    
private:
	float tiempo_vida;
    cualidades cualidad;
	tiempo temp;
    std::vector<Bala*> balas;
    Bala* bala_aux;
    std::vector<Bala*>::iterator iter;
    
};

#endif /* gun_hpp */
