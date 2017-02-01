//
//  Nodo_SuenaAlarma.hpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Nodo_SuenaAlarma_hpp
#define Nodo_SuenaAlarma_hpp

#include "Nodo.hpp"


class Nodo_SuenaAlarma : public Nodo {
public:
    ~Nodo_SuenaAlarma();
    Nodo_SuenaAlarma();
    short run(int &id);
    void reset(){}
private:
};

#endif /* Nodo_SuenaAlarma_hpp */
