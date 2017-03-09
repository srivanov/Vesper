//
//  superSockerObj.hpp
//  arquitectura
//
//  Created by Nerea Castellanos Rodríguez on 22/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef superSocker_hpp
#define superSocker_hpp

#include <stdio.h>
#include "GameObject.hpp"
#include "../Dvector.hpp"

class superSockerObj : public GameObject{
public:
    superSockerObj();
    ~superSockerObj();
    void update();
    void contacto(GameObject* g);
    void contactoEnd(GameObject* g);
    bool const* getmuero();
private:
    bool muero;
};
#endif /* superSockerObj_hpp */
