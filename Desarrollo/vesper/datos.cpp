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
bool vector3D::operator ==(const vector3D &p) const{
    return this->x==p.x && this->y==p.y && this->z==p.z;
    
}
vector3D& vector3D::operator=(const vector3D &p){
    if(this!=&p){
        if(p.x != 0 ) this->x = p.x;
        if(p.y != 0 ) this->y = p.y;
        if(p.z != 0 ) this->z = p.z;
    }
    return *this;
}
vector3D datos::getPosicionFinal(){return posFinal;}
void datos::setPosicionFinal(vector3D posicion){posFinal=posicion;}
vector3D datos::getPosActual(){return posActual;}
vector3D datos::getPosAnterior(){return posAnterior;}
int datos::getLife(){return life;}
int datos::getHambre(){return hambre;}
int datos::getSed(){return sed;}
int datos::getEstado(){return estados;}
void datos::setEstados(int NewEstado){estados=NewEstado;}
void datos::Llamada(bool senyal,vector3D posicion){llamando=senyal;setPosicionFinal(posicion);}

void datos::Avisado(bool senyal){avisado=senyal;}
bool datos::getAviso(){return avisado;}
bool datos::getLLamada(){return llamando;}
void datos::Curarse(int valor){
    life+=valor;
    if (life>100) life = 100;
}
void datos::Alimentarse(int valor){hambre-=valor;}
void datos::Beber(int valor){sed-=valor;}
void datos::newPosition(vector3D nueva_posicion){posActual=nueva_posicion;}
