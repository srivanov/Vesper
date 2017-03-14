
#ifndef piedra_hpp
#define piedra_hpp

#include <stdio.h>
#include "armaInterface.hpp"
#include <time.h>

class piedra : public armaInterface{
public:
	piedra(unsigned int pMunicion, float pAlcance, float pTiempo_recarga);
	~piedra();
	void atacar() override;
	unsigned int getMunicion() override;
	void setMunicion(unsigned int n) override;
	void update();
	void destructor() override;
	typeArma const* getType() override;
    
private:
	unsigned int cadencia, municion, cargador;
	float tiempo_recarga, tiempo_vida, alcance;
	time_t tiempo;
};

#endif /* piedra_hpp */
