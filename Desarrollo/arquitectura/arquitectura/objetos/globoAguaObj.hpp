//
//  globoAguaObj.hpp
//  arquitectura
//
//  Created by Nerea Castellanos Rodríguez on 22/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef globoAguaObj_hpp
#define globoAguaObj_hpp

#include <stdio.h>
#include "GameObject.hpp"
#include "../Dvector.hpp"

class globoAguaObj : public GameObject{
public:
    globoAguaObj();
    ~globoAguaObj();
    void update();
    void contacto(GameObject* g);
    void contactoEnd(GameObject* g);
    bool const getmuero();
private:
    bool muero;
};
#endif /* globoAguaObj_hpp */
