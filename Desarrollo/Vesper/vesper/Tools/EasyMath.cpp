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

float EasyMath::elevar_a(int exponente,float num){
    for (int i=1; i<exponente; i++) num = num*num;
    return num;
}

float EasyMath::CalcularDistancia(dvector3D a, dvector3D b){
    float x = absolute(a.x-b.x);
    float y = absolute(a.y-b.y);
    float z = absolute(a.z-b.z);
    return x+y+z;
}
float EasyMath::EucCalcularDistancia(dvector3D a, dvector3D b){
    dvector3D f = b - a;
    float x = elevar_a(2,f.x);
    float y = elevar_a(2,f.y);
    float z = elevar_a(2,f.z);
    return raiz_cuadrada(x+y+z);
}
float EasyMath::CalcularDistancia(dvector2D a, dvector2D b){
    float x = absolute(a.x-b.x);
    float y = absolute(a.y-b.y);
    return x+y;
}
float EasyMath::EucCalcularDistancia(dvector2D a, dvector2D b){
    float x = elevar_a(2, a.x-b.x);
    float y = elevar_a(2, a.y-b.y);
    return raiz_cuadrada(x+y);
}

float EasyMath::raiz_cuadrada(float num){
    float x = num;
    if(num > 0){
        int i;
        for(i = 0; i < 5; i ++) // ORIGINAL 20 ITERACIONES
            x = (((x * x) + num) / (2 * x));
        
        return x;
    }
    return 0;
}


