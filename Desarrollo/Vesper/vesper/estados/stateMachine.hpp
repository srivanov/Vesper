//
//  stateMachine.hpp
//  estados
//
//  Created by Stoycho Ivanov Atanasov on 16/3/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef stateMachine_hpp
#define stateMachine_hpp

/*
include lvl
 include mprin
 include mpause
 
*/

#include "estados.h"
#include "../Level.hpp"
#include "../GUI/menuManager.hpp"

class stateMachine {
public:
	stateMachine();
	bool update();
	void render();
    void Init();
	
	states* actualState;
private:
	void stop() { running = false; }
	Level nivelazo;
	menuManager menusManager;
	bool running;
};

#endif /* stateMachine_hpp */
