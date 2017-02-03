//
//  Arista.cpp
//  PruebaGrafo
//
//  Created by Julia Martínez Valera on 27/1/17.
//  Copyright © 2017 Julia Martínez Valera. All rights reserved.
//

#include "Arista.hpp"
#include <math.h>

arista::arista(vector2d a,vector2d b){
    float x = fabsf(b.x-a.x);
    float y = fabsf(b.y-a.y);
    distancia = x+y;
}
arista::~arista(){}
