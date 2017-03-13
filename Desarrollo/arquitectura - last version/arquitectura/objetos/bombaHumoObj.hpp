//
//  bombaHumoObj.hpp
//  arquitectura
//
//  Created by Nerea Castellanos Rodríguez on 22/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef bombaHumoObj_hpp
#define bombaHumoObj_hpp

#include <stdio.h>
#include "GameObject.hpp"
#include "../Dvector.hpp"

class bombaHumoObj : public GameObject{
public:
    bombaHumoObj();
    ~bombaHumoObj();
    void update();
    void contacto(GameObject* g);
    void contactoEnd(GameObject* g);
    bool const* getmuero();
private:
    bool muero;
};
#endif /* bombaHumoObj_hpp */
