//
//  SkyMallaAnimada.hpp
//  motor
//
//  Created by Gaspar Rodriguez Valero on 14/5/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef SkyMallaAnimada_hpp
#define SkyMallaAnimada_hpp

#include "TGestorRecursos.hpp"
#include "TMalla.hpp"
#include "SkyNodo.hpp"
#include "tiempo.h"
#include <map>
#include <vector>
#include <stdio.h>

struct Animacion {
    Animacion();
    ~Animacion();
    void setFrames(std::vector<TRecursoMalla*> mallas);
    size_t NumFrames;
    unsigned int actual;
    float TimePerFrame;
    TRecursoMalla **frames;
};

class SkyMallaAnimada : public SkyNodo {
    std::map<std::string,Animacion*> animaciones;
    std::map<std::string,Animacion*>::iterator it;
    tiempo t;
    bool FileExist(std::string ruta);
public:
    SkyMallaAnimada(TNodo * padre);
    ~SkyMallaAnimada();
    bool AnyadirAnimacion(std::string ruta,std::string nombre,float time);
    bool CambiarAnimacion(std::string cambio);
    Animacion * animacion_activa;
};

#endif /* SkyMallaAnimada_hpp */
