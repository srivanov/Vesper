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
	
	Game* game = Game::Instance();
	
	while (game->isRunning()) {
		
	}
	
    return 0;
}
