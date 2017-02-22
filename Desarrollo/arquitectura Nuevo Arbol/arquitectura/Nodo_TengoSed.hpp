//
//  Nodo_TengoSed.hpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Nodo_TengoSed_hpp
#define Nodo_TengoSed_hpp

#include "Nodo.hpp"

class Nodo_TengoSed : public Nodo {
public:
    ~Nodo_TengoSed();
    Nodo_TengoSed();
    short run(int &id);
    void reset(){}
private:
};
#endif /* Nodo_TengoSed_hpp */
