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

class Game {
public:
	static Game* Instance();
	
	void start(uint32_t ancho, uint32_t alto, uint32_t color, bool fullscreen, bool stencilbuffer, bool vsync, bool receiver);
	
	virtual ~Game();
	void update();
	void render();
	bool isRunning();
protected:
	Game();
private:
	static Game* pinstance;
	class render *renderizador;
	input* input;
//	engineInterface* interfaceIrr;
};

#endif /* Game_hpp */
