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
#include "vectorD.hpp"
#include <vector>
#include <time.h>


class datos {
public:
    datos(int ntipos,vector3D * PosicionInicial,int rutina);//tipo, posActual;
    ~datos();
    void Avisado(bool senyal);
    void Llamada(bool senyal,vector3D * posicion);
    void Beber(int valor);
    void Alimentarse(int valor);
    void Curarse(int valor);
    bool getAviso() const {return avisado;}
    bool getLLamada() const {return llamando;}
    void setEstados(int NewEstado);
    int getEstado() const {return estados;}
    int getLife() const {return life;}
    int getSed() const {return sed;}
    int getHambre() const {return hambre;}
    void newPosition(vector3D * nueva_posicion);
    vector3D * getPosActual() const {return posActual;}
    vector3D * getPosAnterior() const {return posAnterior;}
    vector3D * getPosAviso() const {return aviso;}
    void setPosicionFinal(vector3D * posicion);
    std::vector<vector3D*> getPosRutina() const {return PosRutina;}
    int getRutina() const {return rutinas;}
    int getPaso() const{return paso;}
    void setPaso() {
        if(paso+1==PosRutina.size())paso=0;
        else paso++;
        }
private:
    int life,sed,hambre,tipo;
    vector3D *posActual, *posAnterior;
    std::vector<vector3D*> PosRutina;
    int rutinas,paso;
    vector3D * aviso;
    float velocidad;
    float velcorriendo;
    int estados;
    bool llamando;
    bool avisado;
};
#endif /* datos_hpp */
