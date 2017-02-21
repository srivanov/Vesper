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


struct EasyMath{
    static float absolute(float p);
    static float CalcularDistancia(dvector3D a, dvector3D b);
    static float CalcularDistancia(dvector2D a, dvector2D b);
    static float EucCalcularDistancia(dvector3D a, dvector3D b);
    static float EucCalcularDistancia(dvector2D a, dvector2D b);
    static float elevar_a(int,float);
    static float raiz_cuadrada(float);
};
#endif /* EasyMath_hpp */

