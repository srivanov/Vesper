//
//  Muro.cpp
//  Arquitectura
//
//  Created by Gaspar Rodriguez Valero on 18/3/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#include "Muro.hpp"

void Muro::construirMuros(int *tilemap,std::vector<dvector2D> &v, std::vector<dvector2D> &p, int ancho, int alto,int anchoMapa,int altoMapa){
    
    physics * fisicas = static_cast<physics*>(componentes.find(PHYSICS)->second) ;
    
    if(fisicas)
        fisicas->crearObjetosEstaticos(v,p,ancho,alto);
     
    class render * ren = static_cast<class render*>(componentes.find(RENDER)->second) ;
    if(ren)
        ren->dibujarMuro(tilemap,anchoMapa,altoMapa);
}

