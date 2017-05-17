//
//  Decoracion.hpp
//  vesper
//
//  Created by Gaspar Rodriguez Valero on 17/5/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Decoracion_hpp
#define Decoracion_hpp

#include "../PhysicObject.hpp"

class Decoracion : public PhysicObject {
    
public:
    void inicializar(int& ID,ObjectType type);
    void update(){}
    Decoracion(){}
    ~Decoracion(){}
};

#endif /* Decoracion_hpp */
