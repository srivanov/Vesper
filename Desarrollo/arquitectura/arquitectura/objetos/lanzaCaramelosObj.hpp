//
//  lanzaCaramelosObj.hpp
//  arquitectura
//
//  Created by Nerea Castellanos Rodríguez on 22/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef lanzaCaramelosObj_hpp
#define lanzaCaramelosObj_hpp

#include <stdio.h>
#include "GameObject.hpp"
#include "../Dvector.hpp"

class lanzaCaramelosObj : public GameObject{
public:
    lanzaCaramelosObj();
    ~lanzaCaramelosObj();
    void update();
    void contacto(GameObject* g);
    void contactoEnd(GameObject* g);
    bool const getmuero();
private:
    bool muero;
};
#endif /* lanzaCaramelosObj_hpp */
