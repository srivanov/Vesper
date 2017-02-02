//
//  EasyMath.hpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 2/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef EasyMath_hpp
#define EasyMath_hpp

#include <stdio.h>
#include "Dvector.hpp"

class EasyMath {
public:
    static float absolute(float p);
    static float CalcularDistancia(dvector3D a, dvector3D b);
};


#endif /* EasyMath_hpp */
