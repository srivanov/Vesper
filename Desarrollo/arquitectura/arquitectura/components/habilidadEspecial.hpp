
#ifndef habilidadEspecial_hpp
#define habilidadEspecial_hpp

#include <stdio.h>
#include "component.hpp"

class habilidadEspecial : public component {
public:
    habilidadEspecial();
    ~habilidadEspecial();
	void update() override;
    void aumentarMoneda();
    void resetear();
private:
    const unsigned int numMonedas;
    unsigned int actual, numUsos;
};
#endif /* habilidadEspecial_hpp */
