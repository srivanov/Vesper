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

class Game {
public:
	static Game* Instance();
	
	virtual ~Game();
	void update();
	void render();
	bool isRunning();
protected:
	Game();
private:
	static Game* pinstance;
};

#endif /* Game_hpp */
