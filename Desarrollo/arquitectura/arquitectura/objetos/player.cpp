//
//  player.cpp
//  arquitectura
//
//  Created by Nerea Castellanos Rodríguez on 29/11/16.
//  Copyright © 2016 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "player.hpp"

player::player(){
	this->insertComponent((char*)"ataque", *new ataque());
    this->insertComponent((char*)"", *new ataque());
}

player::~player(){
    
}
