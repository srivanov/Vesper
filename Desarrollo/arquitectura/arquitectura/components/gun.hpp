
#ifndef gun_hpp
#define gun_hpp

#include <stdio.h>
#include <string>
#include <time.h>
#include "Dvector.hpp"
#include <vector>
#include "bala.hpp"

enum typeArma{
    tArmaNO_TYPE = -1,
    tPISTOLA,
    tESCOPETA,
    tLANZACARAMELOS,
    tPIEDRAc,
    tGLOBOAGUA,
    tCHICLE,
    tBOMBAHUMO,
    tMARTILLO,
    tPALAc
};

class gun {
public:
	gun(unsigned int pMunicion, float pAlcance, float pTiempo_recarga, unsigned int caden, unsigned int carga, typeArma t);
    ~gun();
	void atacar(dvector3D &pos, dvector3D &dir);
	unsigned int getMunicion();
	void setMunicion(unsigned int n);
	void update();
    typeArma const* getType();
    void insertBala(dvector3D &pos, dvector3D &dir, float vel);
    void render();
	
private:
    typeArma tipo;
	unsigned int cadencia, municion, cargador;
	float tiempo_recarga, tiempo_vida, alcance;
	time_t tiempo;
    std::vector<bala*> balas;
    bala* bala_aux;
    std::vector<bala*>::iterator iter;
    
    const char* jotas[10] = {"tArmaNO_TYPE","tPISTOLA","tESCOPETA","tLANZACARAMELOS","tPIEDRAc","tGLOBOAGUA","tCHICLE","tBOMBAHUMO","tMARTILLO","tPALAc"};
};

#endif /* gun_hpp */
