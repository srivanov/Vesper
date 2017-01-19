
#ifndef chicle_hpp
#define chicle_hpp

#include <stdio.h>
#include "armaInterface.hpp"
#include <time.h>

class chicle : public armaInterface{
public:
	chicle(unsigned int pMunicion, float pAlcance, float pTiempo_recarga);
	~chicle();
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

#endif /* chicle_hpp */
