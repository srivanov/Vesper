//
//  ground.hpp
//  vesper
//
//  Created by Gaspar Rodriguez Valero on 23/3/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Ground_hpp
#define Ground_hpp

#include "GameObject.hpp"

class Ground : public GameObject {
public:
    void inicializar(float alto, float ancho);
    ~Ground(){}
    Ground(){}
};

#endif /* ground_hpp */
