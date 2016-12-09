//
//  bala.hpp
//  arquitectura
//
//  Created by Nerea Castellanos Rodríguez on 9/12/16.
//  Copyright © 2016 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef bala_hpp
#define bala_hpp

#include <stdio.h>
#include "GameObject.hpp"

class bala : public GameObject{
public:
    bala(float* pos);
    ~bala();
    
};
#endif /* bala_hpp */
