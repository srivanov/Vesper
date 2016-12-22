//
//  player.hpp
//  vesper
//
//  Created by Gaspar Rodriguez Valero on 13/12/16.
//  Copyright © 2016 Skyscrapers. All rights reserved.
//

#ifndef player_hpp
#define player_hpp

#include "datos.hpp"

class player{
public:
    player(vector3D PosInicial);
    ~player();
    int getLife();
    vector3D getPosition();
private:
    vector3D posicion;
    int life;
};

#endif /* player_hpp */
