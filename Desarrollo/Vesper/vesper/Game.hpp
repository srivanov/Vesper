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
//#include "Level.hpp"
#include "Fps.hpp"
#include "Dvector.hpp"
//#include "GUI/LayoutGUI.hpp"
#include "tiempo.h"

#include "estados/stateMachine.hpp"

class Game {
public:
	static Game* Instance();
	
	void start(uint32_t ancho, uint32_t alto, uint32_t color, bool fullscreen, bool stencilbuffer, bool vsync, bool receiver);
	void stop();
	
	virtual ~Game();
	void update(const long &timePerFrame);
	void render(float &interpolation);
	bool isRunning();
    void setPausa(bool p){
        pausa = p;
    }
protected:
	Game();
	
private:
	class render *renderizador;
	class input* entrada;
	bool running, pausa;
//	Level* nivelazo;
	
	void processEvents();
	
    stateMachine maquina;
};

#endif /* Game_hpp */
