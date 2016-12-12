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
    bool operator ==(const vector3D &p) const;
    vector3D& operator =(const vector3D &p);
};

class datos {
private:
    int life,sed,hambre,tipo;
    vector3D posActual, posAnterior;
    vector3D posFinal;
    float velocidad;
    int estados;
    bool llamando;
    bool avisado;
public:
    vector3D getPosicionFinal();
    void setPosicionFinal(vector3D posicion);
    void Avisado(bool senyal);
    void Llamada(bool senyal,vector3D posicion);
    void Beber(int valor);
    void Alimentarse(int valor);
    void Curarse(int valor);
    bool getAviso();
    bool getLLamada();
    void setEstados(int NewEstado);
    int getEstado();
    void inicializar();
    int getLife();
    int getSed();
    int getHambre();
    void newPosition(vector3D nueva_posicion);
    vector3D getPosActual();
    vector3D getPosAnterior();
};
#endif /* datos_hpp */
