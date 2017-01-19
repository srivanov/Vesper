//
//  Game.hpp
//  arquitectura
//
//  Created by Stoycho Ivanov Atanasov on 1/12/16.
//  Copyright © 2016 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include "components/render.hpp"
#include "components/input.hpp"
#include "objetos/player.hpp"
#include "objetos/enemigos.hpp"
#include "objetos/alarma.hpp"
#include "objetos/botiquin.hpp"
#include "objetos/comida.hpp"
#include "objetos/fuente.hpp"
#include "objetos/camara.hpp"
#include "Fps.hpp"
#include "mundoBox2D.hpp"
#include "objetos/bala.hpp"
#include "objetos/escenarios.hpp"
#include "BlackBoards.hpp"
#include "trigger_system.hpp"
#include <vector>

class Game {
public:
	static Game* Instance();
	
	void start(uint32_t ancho, uint32_t alto, uint32_t color, bool fullscreen, bool stencilbuffer, bool vsync, bool receiver);
	void stop();
	
	virtual ~Game();
	void update();
	void render();
	bool isRunning();
    player* getPlayer();
    bala* insertBala(float vel);
    void zoom(bool z);
	void atacarJugador();
	void cambiarArmaJugador();
	void rotarConRaton(float* posRaton);
	
protected:
	Game();
	
private:
	//static Game* pinstance;
	class render *renderizador;
	class input* entrada;
	bool running;
    player* jugador;
    camara* cam;
    vector<bala*> balas;
    bala* bala_aux;
    std::vector<bala*>::iterator iter;
	escenarios* nivel;
	std::vector<enemigos*> npcs;
    std::vector<alarma*> alarmas;
    std::vector<fuente*> fuentes;
    std::vector<comida*> comidas;
    std::vector<botiquin*> botiquines;
	int contador_npc;
};

#endif /* Game_hpp */
