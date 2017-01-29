
#ifndef bombaHumo_hpp
#define bombaHumo_hpp

#include <stdio.h>
#include "armaInterface.hpp"
#include <time.h>

class bombaHumo : public armaInterface{
public:
	bombaHumo(unsigned int pMunicion, float pAlcance, float pTiempo_recarga);
	~bombaHumo();
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

#endif /* bombaHumo_hpp */
