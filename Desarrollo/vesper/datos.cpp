//
//  datos.cpp
//  vesper
//
//  Created by Gaspar Rodriguez Valero on 7/12/16.
//  Copyright © 2016 Skyscrapers. All rights reserved.
//

#include "datos.hpp"
void datos::inicializar(){
    life=100;
    srand(time(NULL));
    sed = rand() % 40;
    hambre = rand() % 40;
    tipo = 1;
    //posActual = {1,1,0};
    velocidad = 1.f;
    llamando = false;
}
vector3D datos::getPosActual(){return posActual;}
vector3D datos::getPosAnterior(){return posAnterior;}
int datos::getLife(){return life;}
int datos::getHambre(){return hambre;}
int datos::getSed(){return sed;}
int datos::getEstado(){return estados;}
void datos::setEstados(int NewEstado){estados=NewEstado;}
void datos::Llamada(bool senyal,vector3D posicion){llamando=senyal;posLlamada=posicion;}
void datos::Avisado(bool senyal){avisado=senyal;}
bool datos::getAviso(){return avisado;}
bool datos::getLLamada(){return llamando;}
void datos::Curarse(int valor){
    life+=valor;
    if (life>100) life = 100;
}
void datos::Alimentarse(int valor){hambre-=valor;}
void datos::Beber(int valor){sed-=valor;}
