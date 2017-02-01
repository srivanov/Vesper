//
//  Nodo_HayBotiquin.hpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Nodo_HayBotiquin_hpp
#define Nodo_HayBotiquin_hpp

#include "Nodo.hpp"

class Nodo_HayBotiquin : public Nodo {
public:
    ~Nodo_HayBotiquin();
    Nodo_HayBotiquin();
    short run(int &id);
    void reset(){}
private:
    
};

#endif /* Nodo_HayBotiquin_hpp */
