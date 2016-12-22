
#ifndef escenarios_hpp
#define escenarios_hpp

#include <stdio.h>
#include "GameObject.hpp"
#include "cargarMapa.hpp"

class escenarios : public GameObject{
public:
    escenarios();
    ~escenarios();
	
	bool cargarNivel(int numero);
	int getAncho();
	int getAlto();
	int*** getMapa();
	void dibujarMapa();
	
private:
	int*** mapa_nivel;
	cargarMapa* cargador;
	int ancho, alto;
};
#endif /* escenarios_hpp */
