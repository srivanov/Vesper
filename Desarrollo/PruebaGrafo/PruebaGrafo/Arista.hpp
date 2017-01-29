//
//  Arista.hpp
//  PruebaGrafo
//
//  Created by Julia Martínez Valera on 27/1/17.
//  Copyright © 2017 Julia Martínez Valera. All rights reserved.
//

#ifndef Arista_hpp
#define Arista_hpp


struct vector2d{
    float x;
    float y;
};

class arista{
    float distancia;
public:
    arista(vector2d a,vector2d b);
    ~arista();
    float getValue() const {return distancia;}
};

#endif /* Arista_hpp */
