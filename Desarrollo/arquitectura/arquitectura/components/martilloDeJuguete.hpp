
#ifndef martilloDeJuguete_hpp
#define martilloDeJuguete_hpp

#include <stdio.h>
#include "armaInterface.hpp"
#include <time.h>

class martilloDeJuguete : public armaInterface{
public:
	martilloDeJuguete(unsigned int pMunicion, float pAlcance, float pTiempo_recarga);
	~martilloDeJuguete();
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

#endif /* martilloDeJuguete_hpp */
