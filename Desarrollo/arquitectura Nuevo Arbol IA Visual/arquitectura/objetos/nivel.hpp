
#ifndef nivel_hpp
#define nivel_hpp

#include <stdio.h>
#include "GameObject.hpp"
#include "palaObj.hpp"
#include "piedraObj.hpp"
#include "monedas.hpp"
#include "llaveObj.hpp"
#include "../cargarMapa.hpp"
#include "enemigos.hpp"
#include "alarma.hpp"
#include "botiquin.hpp"
#include "comida.hpp"
#include "fuente.hpp"
#include "camara.hpp"
#include "puerta.hpp"


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
    void render();
    void contacto(GameObject* g);
    void contactoEnd(GameObject* g);
    bool const* getmuero();
	
private:
	std::vector<int>* mapa_nivel;
	cargarMapa* cargador;
    int ancho, alto, contador_npc;
    std::vector<GameObject*> powerups;
    std::vector<enemigos*> npcs;
    std::vector<alarma*> alarmas;
    std::vector<fuente*> fuentes;
    std::vector<comida*> comidas;
    std::vector<botiquin*> botiquines;
	std::vector<puerta*> puertas;
    bool muero;
};
#endif /* nivel_hpp */
