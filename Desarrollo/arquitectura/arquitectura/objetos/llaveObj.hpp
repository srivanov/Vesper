//
//  llaveObj.hpp
//  arquitectura
//
//  Created by Nerea Castellanos Rodríguez on 23/1/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef llaveObj_hpp
#define llaveObj_hpp

#include <stdio.h>
#include "GameObject.hpp"
#include "../Dvector.hpp"

class llaveObj : public GameObject{
public:
    llaveObj();
    ~llaveObj();
    void update();
private:
    
};

#endif /* llaveObj_hpp */
