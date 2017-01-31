//
//  main.cpp
//  arquitectura
//
//  Created by Stoycho Ivanov Atanasov on 29/11/16.
//  Copyright © 2016 Stoycho Ivanov Atanasov. All rights reserved.
//

#include <iostream>
#include "Game.hpp"

int main(int argc, const char * argv[]) {
	//TO DO: Hacer los Singleton sin puntero y con const (ejemplo en Game)
	Game* game = Game::Instance();
	
	game->start(600,600,32,false,false,true,true);
	
	while (game->isRunning()) {
		//TO DO: Update 15 veces por segundo
		game->update();
		//TO DO: interpolacion
		game->render();
	}
    return 0;
}
