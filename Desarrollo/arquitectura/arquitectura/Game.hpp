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
#include "Fps.hpp"
#include "mundoBox2D.hpp"
#include "objetos/bala.hpp"
#include "objetos/nivel.hpp"
#include "BlackBoards.hpp"
#include "trigger_system.hpp"
#include <vector>
#include "Dvector.hpp"
#include "GUI/LayoutGUI.hpp"

class Game {
public:
	static Game* Instance();
	
	void start(uint32_t ancho, uint32_t alto, uint32_t color, bool fullscreen, bool stencilbuffer, bool vsync, bool receiver);
	void stop();
	
	virtual ~Game();
	void update(const long &timePerFrame);
	void render(float &interpolation);
	bool isRunning();
    player* getPlayer();
    void zoom(bool z);
	void atacarJugador();
	void cambiarArmaJugador();
	void rotarConRaton(dvector3D posRaton);
    camara* getCamara();
	void setPausa(bool p);
	
protected:
	Game();
	
private:
	//static Game* pinstance;
	class render *renderizador;
	class input* entrada;
	bool running, pausa;
    camara* cam;
    bala* bala_aux;
    std::vector<bala*>::iterator iter;
	nivel* nivelazo;
	
	void processEvents();
	
	LayoutGUI* layoutPrueba;
};

#endif /* Game_hpp */
