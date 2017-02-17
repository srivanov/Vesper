
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
#include "player.hpp"


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
    void cambiarArmaJugador();
    void atacarJugador();
    void rotarConRaton(dvector3D posRaton);
    player* getPlayer();
	
private:
	std::vector<int>* mapa_nivel;
	std::vector<dvector2D>* objetos_col;
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
    player *jugador;
    
    
};
#endif /* nivel_hpp */
