
#ifndef pala_hpp
#define pala_hpp

#include <time.h>
#include <stdio.h>
#include "component.hpp"
#include "armaInterface.hpp"

class pala : public armaInterface {
public:
    pala(unsigned int pMunicion, float pAlcance, float pTiempo_recarga);
    ~pala();
	void update();

    void atacar() override;
    unsigned int getMunicion() override;
    void setMunicion(unsigned int n) override;
    void destructor() override;
private:
    unsigned int cadencia, municion, cargador;
    float tiempo_recarga, tiempo_vida, alcance;
    time_t tiempo;
};
#endif /* pala_hpp */
