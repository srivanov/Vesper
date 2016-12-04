//
//  input.hpp
//  arquitectura
//
//  Created by Stoycho Ivanov Atanasov on 29/11/16.
//  Copyright © 2016 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef input_hpp
#define input_hpp

#include <stdio.h>
#include "component.hpp"
#include "MyEventReceiver.hpp"
#include "Game.hpp"

class input : public component {
public:
	input();
	~input();
	void update();
	
private:
	MyEventReceiver *r;
	class Game* juego;
};

#endif /* input_hpp */
