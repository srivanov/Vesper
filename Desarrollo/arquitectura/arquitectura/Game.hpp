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
#include "render.hpp"
#include "input.hpp"
#include "player.hpp"
#include "camara.hpp"
#include "Fps.hpp"
#include "mundoBox2D.hpp"
#include <vector>
#include "bala.hpp"

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
    bala* insertBala();
protected:
	Game();
private:
	static Game* pinstance;
	class render *renderizador;
	class input* entrada;
	bool running;
    player* p;
    camara* c;
    vector<bala*> balas;
    bala* bala_aux;
    std::vector<bala*>::iterator iter;
};

#endif /* Game_hpp */
