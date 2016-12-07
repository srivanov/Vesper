//
//  datos.hpp
//  vesper
//
//  Created by Gaspar Rodriguez Valero on 7/12/16.
//  Copyright © 2016 Skyscrapers. All rights reserved.
//

#ifndef datos_hpp
#define datos_hpp

#include <stdlib.h>
#include <time.h>
class vector3D{
public:
    float x,y,z;
};

class datos {
private:
    int life,sed,hambre,tipo;
    vector3D posActual, posAnterior;
    float velocidad;
    
public:
    void inicializar();
    int getLife();
    int getSed();
    int getHambre();
    vector3D getPosActual();
    vector3D getPosAnterior();
};
#endif /* datos_hpp */
