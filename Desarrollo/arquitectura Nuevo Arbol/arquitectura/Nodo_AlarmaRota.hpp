//
//  Nodo_AlarmaRota.hpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Nodo_AlarmaRota_hpp
#define Nodo_AlarmaRota_hpp

#include "Nodo.hpp"

class Nodo_AlarmaRota : public Nodo {
public:
    Nodo_AlarmaRota();
    ~Nodo_AlarmaRota();
    short run(int &id);
    void reset(){}
private:
};
#endif /* Nodo_AlarmaRota_hpp */
