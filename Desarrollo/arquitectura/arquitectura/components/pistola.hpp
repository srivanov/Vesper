
#ifndef pistola_hpp
#define pistola_hpp

#include <stdio.h>
#include "armaInterface.hpp"
#include <time.h>

class pistola : public armaInterface{
public:
	pistola(unsigned int pMunicion, float pAlcance, float pTiempo_recarga);
	~pistola();
	void atacar();
	unsigned int getMunicion();
	void setMunicion(unsigned int n);
	void update();
	
private:
	unsigned int cadencia, municion, cargador;
	float tiempo_recarga, tiempo_vida, alcance;
	time_t tiempo;
};

#endif /* pistola_hpp */
