//
//  objects.hpp
//  vesper
//
//  Created by Gaspar Rodriguez Valero on 8/12/16.
//  Copyright © 2016 Skyscrapers. All rights reserved.
//

#ifndef objects_hpp
#define objects_hpp

#include "datos.hpp"

class objetos {
public:
    vector3D getPosition(){return posicion;}
private:
    vector3D posicion;
};
class botiquin : public objetos{
public:
private:
    int num_usos;
    
    bool gastado = false;
};
class fuente : public objetos{};
class comida : public objetos{};

#endif /* objects_hpp */
