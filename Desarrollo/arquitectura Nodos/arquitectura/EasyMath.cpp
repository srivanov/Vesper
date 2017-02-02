//
//  EasyMath.cpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 2/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "EasyMath.hpp"



float EasyMath::absolute(float p){
    float aux = 0;
    if(p<0) aux=-p;
    else aux = p;
    return aux;
}

float EasyMath::CalcularDistancia(dvector3D a, dvector3D b){
    float x = absolute(a.x-b.x);
    float y = absolute(a.y-b.y);
    return x+y;
}


