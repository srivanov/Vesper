
#ifndef chicle_hpp
#define chicle_hpp

#include <stdio.h>
#include "armaInterface.hpp"
#include <time.h>

class chicle : public armaInterface{
public:
	chicle(unsigned int pMunicion, float pAlcance, float pTiempo_recarga);
	~chicle();
	void atacar() override;
	unsigned int getMunicion() override;
	void setMunicion(unsigned int n) override;
	void update();
	void destructor() override;
	
private:
	unsigned int cadencia, municion, cargador;
	float tiempo_recarga, tiempo_vida, alcance;
	time_t tiempo;
};

#endif /* chicle_hpp */
