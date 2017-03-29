
#ifndef bombaHumo_hpp
#define bombaHumo_hpp

#include <stdio.h>
#include <time.h>

class bombaHumo {
public:
	bombaHumo(unsigned int pMunicion, float pAlcance, float pTiempo_recarga);
	~bombaHumo();
	void atacar();
	unsigned int getMunicion();
	void setMunicion(unsigned int n);
	void update();
	void destructor();
    typeArma const* getType();
	
private:
	unsigned int cadencia, municion, cargador;
	float tiempo_recarga, tiempo_vida, alcance;
	time_t tiempo;
};

#endif /* bombaHumo_hpp */
