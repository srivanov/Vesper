//
//  NodoDarAlarma.hpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef NodoDarAlarma_hpp
#define NodoDarAlarma_hpp

#include "Nodo.hpp"


class NodoDarAlarma : public Nodo {
public:
    ~NodoDarAlarma();
    NodoDarAlarma();
    short run(int &id);
    void reset(){}
private:
};

#endif /* NodoDarAlarma_hpp */
