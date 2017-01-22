
#ifndef nivel_hpp
#define nivel_hpp

#include <stdio.h>
#include "GameObject.hpp"
#include "palaObj.hpp"
#include "../cargarMapa.hpp"


class nivel : public GameObject{
public:
    nivel();
    ~nivel();
	
	bool cargarNivel(char* numero);
	int getAncho();
	int getAlto();
    std::vector<int>* getMapa();
	void dibujarMapa();
	void update();
	
private:
	std::vector<int>* mapa_nivel;
	cargarMapa* cargador;
	int ancho, alto;
	palaObj pala;
};
#endif /* nivel_hpp */
