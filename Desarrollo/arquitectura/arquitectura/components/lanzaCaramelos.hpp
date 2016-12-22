

#ifndef lanzaCaramelos_hpp
#define lanzaCaramelos_hpp

#include <stdio.h>
#include "armaInterface.hpp"
#include <time.h>

class lanzaCaramelos : public armaInterface{
public:
	lanzaCaramelos(unsigned int pMunicion, float pAlcance, float pTiempo_recarga);
	~lanzaCaramelos();
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

#endif /* lanzaCaramelos_hpp */
