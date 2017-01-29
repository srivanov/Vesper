
#ifndef habilidadEspecial_hpp
#define habilidadEspecial_hpp

#include <stdio.h>
#include <time.h>
#include "component.hpp"

enum tipoHab{
	NO_TYPE = 0,
	tHabINVISIBLE,
	tHabINHIBIDOR,
	tHabSINRUIDO
};

class habilidadEspecial : public component {
public:
    habilidadEspecial();
    ~habilidadEspecial();
	void update() override;
    void aumentarMoneda();
    void resetear();
	void activar();
	void setTipo(tipoHab t);
	bool const* estaActivada();
	bool puedoUsar();
private:
    const unsigned int numMonedas;
    unsigned int actual, numUsos, duracion;
	bool activada;
	time_t tiempo;
	tipoHab tipo;
};
#endif /* habilidadEspecial_hpp */
