//
//  TMallaAnimada.hpp
//  motor
//
//  Created by Gaspar Rodriguez Valero on 16/5/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef TMallaAnimada_hpp
#define TMallaAnimada_hpp

#include <string>
#include <map>
#include <vector>
#include "tiempo.h"

#include "TEntidad.hpp"
#include "TRecursoMalla.hpp"
#include "ShaderManager.hpp"
#include "TGestorRecursos.hpp"

struct Animacion {
    Animacion();
    ~Animacion();
    void setFrames(std::vector<TRecursoMalla*> mallas);
    TRecursoMalla * frameActivo(){return frames[actual];}
    void nextFrame();
    void resetAnimacion(){actual=0;}
    float AnimationTime;
    size_t NumFrames;
private:
    unsigned int actual;
    TRecursoMalla **frames;
};

class TMallaAnimada : public TEntidad {
	
	TRecursoTextura* textura;
    Pila* pila;
    TGestorRecursos* gestor;
    
    std::map<std::string,Animacion*> animaciones;
    std::map<std::string,Animacion*>::iterator it;
    tiempo t;
    bool FileExist(std::string ruta);
    
    Animacion * animacion_activa;
    
    
public:
    TMallaAnimada();
    ~TMallaAnimada();
    
    void setTextura(char* fichero);
    bool setAnimacion(std::string ruta,std::string nombre,float time, unsigned int NumberFrames = 0);
    bool ChangeAnimacion(std::string nombre);
    
    void beginDraw();
    void endDraw();
    
    
    
};

#endif /* TMallaAnimada_hpp */
