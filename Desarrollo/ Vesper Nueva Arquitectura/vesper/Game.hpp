//
//  Game.hpp
//  arquitectura
//
//  Created by Stoycho Ivanov Atanasov on 1/12/16.
//  Copyright © 2016 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <vector>
#include <stdio.h>
#include "components/render.hpp"
#include "components/input.hpp"
#include "objetos/Objects.hpp"
#include "Level.hpp"
#include "Fps.hpp"
#include "mundoBox2D.hpp"
#include "Arquitectura IA/trigger_system.hpp"
#include "Arquitectura IA/LevelBlackBoard.hpp"
#include "Arquitectura IA/NpcLibrary.hpp"
#include "Dvector.hpp"
#include "GUI/LayoutGUI.hpp"
#include "tiempo.h"

class Game {
public:
	static Game* Instance();
	
	void start(uint32_t ancho, uint32_t alto, uint32_t color, bool fullscreen, bool stencilbuffer, bool vsync, bool receiver);
	void stop();
	
	virtual ~Game();
	void update();
	void render();
	bool isRunning();
    //Player* getPlayer();
    void zoom(bool z);
	void atacarJugador();
	void cambiarArmaJugador();
	void rotarConRaton(dvector3D posRaton);
	void setPausa(bool p);
	
protected:
	Game();
	
private:
	//static Game* pinstance;
	class render *renderizador;
	class input* entrada;
	bool running, pausa;
    Bala* bala_aux;
    std::vector<Bala*>::iterator iter;
	Level* nivelazo;
	
	void processEvents();
	
	LayoutGUI* layoutPrueba;
};

#endif /* Game_hpp */
