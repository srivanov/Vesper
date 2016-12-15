//
//  datos.cpp
//  vesper
//
//  Created by Gaspar Rodriguez Valero on 7/12/16.
//  Copyright © 2016 Skyscrapers. All rights reserved.
//

#include "datos.hpp"

#define BOLASdeFUEGO 1
#define LANZApinchos 2
#define ESCUPEacido 3
#define CUERPOaCUERPO 4


datos::datos(int ntipos,vector3D * PosicionInicial){
    life=30;
    srand(static_cast<int>(time(NULL)));
    sed = 80; //rand() % 40;
    hambre = 90;  //rand() % 40;
    llamando = false;
    avisado = false;
    tipo = ntipos;
    if (tipo<=ESCUPEacido) {
        velocidad = 1.f;
        if(tipo==BOLASdeFUEGO) velcorriendo = 1.5f;
        else if(tipo==LANZApinchos) velcorriendo = 1.2f;
        else velcorriendo = 1.7f;
    }else{
        velocidad = 0.8f;
        velcorriendo = 2.f;
    }
    aviso = posActual = PosicionInicial;
}
datos::~datos(){}
void datos::setEstados(int NewEstado){estados=NewEstado;}
void datos::Llamada(bool senyal,vector3D * posicion){llamando=senyal;setPosicionFinal(posicion);}
void datos::setPosicionFinal(vector3D *posicion){aviso = posicion;}
void datos::Avisado(bool senyal){avisado=senyal;}
void datos::Curarse(int valor){
    life+=valor;
    if (life>100) life = 100;
}
void datos::Alimentarse(int valor){hambre-=valor;}
void datos::Beber(int valor){sed-=valor;}
void datos::newPosition(vector3D * nueva_posicion){posActual=nueva_posicion;}
