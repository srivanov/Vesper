//
//  chicleObj.hpp
//  arquitectura
//
//  Created by Nerea Castellanos Rodríguez on 22/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef chicleObj_hpp
#define chicleObj_hpp

#include <stdio.h>
#include "GameObject.hpp"
#include "../Dvector.hpp"

class chicleObj : public GameObject{
public:
    chicleObj();
    ~chicleObj();
    void update();
    void contacto(GameObject* g);
    void contactoEnd(GameObject* g);
    bool const* getmuero();
private:
    bool muero;
};
#endif /* chicleObj_hpp */
