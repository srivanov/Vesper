
#ifndef escopeta_hpp
#define escopeta_hpp

#include <stdio.h>
#include "armaInterface.hpp"
#include <time.h>

class escopeta : public armaInterface{
public:
	escopeta(unsigned int pMunicion, float pAlcance, float pTiempo_recarga);
	~escopeta();
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

#endif /* escopeta_hpp */
