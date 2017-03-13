//
//  rehen.hpp
//  arquitectura
//
//  Created by Nerea Castellanos Rodríguez on 22/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef rehen_hpp
#define rehen_hpp

#include <stdio.h>
#include "GameObject.hpp"
#include "../Dvector.hpp"

class rehen : public GameObject{
public:
    rehen();
    ~rehen();
    void contacto(GameObject* g);
    void contactoEnd(GameObject* g);
    bool const* getmuero();
    
private:
    bool muero;
};
#endif /* rehen_hpp */
