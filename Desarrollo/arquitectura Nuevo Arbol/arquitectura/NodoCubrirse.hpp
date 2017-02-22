//
//  NodoCubrirse.hpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef NodoCubrirse_hpp
#define NodoCubrirse_hpp

#include "Nodo.hpp"

class NodoCubrirse : public Nodo {
public:
    ~NodoCubrirse();
    NodoCubrirse();
    short run(int &id);
    void reset(){}
private:
};

#endif /* NodoCubrirse_hpp */
