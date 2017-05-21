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
	Animacion(){
		actual = NumFrames = 0 ;
		TimePerFrame = 0.f;
	}
	~Animacion(){}
	void setFrames(std::vector<TRecursoMalla*> mallas){
		if(NumFrames==0) NumFrames = mallas.size();
		
		frames = new TRecursoMalla*[NumFrames];
		size_t cont = 0;
		while (mallas.size()!=0) {
			frames[cont] = mallas[0];
			mallas.erase(mallas.begin());
			cont++;
		}
	}
    size_t NumFrames;
    unsigned int actual;
    float TimePerFrame;
    TRecursoMalla **frames;
};

class SkyMallaAnimada : public SkyNodo {
	friend class SkyEngine;
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
