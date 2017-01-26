//
//  piedraObj.hpp
//  arquitectura
//
//  Created by Nerea Castellanos Rodríguez on 23/1/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef piedraObj_hpp
#define piedraObj_hpp

#include <stdio.h>
#include "GameObject.hpp"
#include "../Dvector.hpp"

class piedraObj : public GameObject{
public:
    piedraObj();
    ~piedraObj();
    void update();
    void contacto(GameObject* g);
    void contactoEnd(GameObject* g);
    bool const* getmuero();
private:
    bool muero;
};

#endif /* piedraObj_hpp */
