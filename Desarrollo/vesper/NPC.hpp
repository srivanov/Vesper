//
//  NPC.hpp
//  vesper
//
//  Created by Gaspar Rodriguez Valero on 7/12/16.
//  Copyright © 2016 Skyscrapers. All rights reserved.
//

#ifndef NPC_hpp
#define NPC_hpp

#include "estados.hpp"


class NPC{
public:
    NPC(int ntipo, vector3D * posinicial);
    ~NPC();
    datos getNPCinfo();
    void update(BlackBoard * worldINFO);
    vector3D * getPosition();
    void setPosition(vector3D * posicion);
private:
    datos * datosPropios;
    estados * DeciSys;
    
};

#endif /* NPC_hpp */
