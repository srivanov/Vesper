//
//  world.hpp
//  vesper
//
//  Created by Gaspar Rodriguez Valero on 8/12/16.
//  Copyright © 2016 Skyscrapers. All rights reserved.
//

#ifndef world_hpp
#define world_hpp

#include "NPC.hpp"
#include "objects.hpp"
#include "tinyxml2.h"


class world {
public:
    world();
    ~world();
    void anyadirBotiquin();
    void anyadirFuente();
    void anyadirComida();
private:
    std::vector<NPC*> enemigos;
    std::vector<objetos*> objetos_mundo;
    void cargarMapa();
    
};

#endif /* world_hpp */
