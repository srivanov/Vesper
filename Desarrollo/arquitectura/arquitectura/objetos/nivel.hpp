
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
#include "superSockerObj.hpp"
#include "lanzaCaramelosObj.hpp"
#include "globoAguaObj.hpp"
#include "chicleObj.hpp"
#include "bombaHumoObj.hpp"
#include "rehen.hpp"

struct obj_mapping{
	int key;
	std::string tex;
	GameObject* (*pfunc)();
};

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
    void render(float &interpolation);
    void contacto(GameObject* g);
    void contactoEnd(GameObject* g);
    bool const* getmuero();
    void cambiarArmaJugador();
    void atacarJugador();
    void rotarConRaton(dvector3D posRaton);
    player* getPlayer();
//    rehen* getRehen();
	
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
	obj_mapping* objs;
//    rehen *re;
    
};
#endif /* nivel_hpp */
