
#ifndef piedra_hpp
#define piedra_hpp

#include <stdio.h>
#include "armaInterface.hpp"
#include <time.h>

class piedra : public armaInterface{
public:
	piedra(unsigned int pMunicion, float pAlcance, float pTiempo_recarga);
	~piedra();
	void atacar();
	unsigned int getMunicion();
	void setMunicion(unsigned int n);
	void destructor();
	void update();
	
private:
	unsigned int cadencia, municion, cargador;
	float tiempo_recarga, tiempo_vida, alcance;
	time_t tiempo;
};

#endif /* piedra_hpp */
