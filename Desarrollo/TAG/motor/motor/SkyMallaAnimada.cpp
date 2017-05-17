//
//  SkyMallaAnimada.cpp
//  motor
//
//  Created by Gaspar Rodriguez Valero on 14/5/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "SkyMallaAnimada.hpp"
/*
 void Animation::setFrames(Mesh** meshes){
 frames = meshes;
 }
 
 void Animation::setFrames(std::vector<Mesh> meshes){
 if(NumFrames == 0) NumFrames = meshes.size()
 frames = new Mesh*[NumFrames];
 
 for (size_t i = 0; i < meshes.size(); ++i)
 {
 frames[i] = meshes[i];
 }
 }
 
 */

//Animacion::Animacion() : frames(nullptr) {
//
//}
//
//Animacion::~Animacion(){}
//
//void Animacion::setFrames(std::vector<TRecursoMalla *> mallas){
//	
//    
//}

SkyMallaAnimada::SkyMallaAnimada(TNodo * padre) : animacion_activa(nullptr) {
    
    nodo = new TNodo();
    
    //m_malla = new TMalla();
    
    buildTransform();
    
    //nodo->setEntidad(m_malla);
    
    TransNodos[0]->addHijo(nodo);
    
    padre->addHijo(TransNodos[2]);
    
    t.start();
    
}

SkyMallaAnimada::~SkyMallaAnimada(){}

bool SkyMallaAnimada::AnyadirAnimacion(std::string ruta, std::string nombre, float time){
    
    Animacion * anim = new Animacion;
    
    anim->TimePerFrame = time;
    
    std::string archivo = ruta + nombre;
    
    std::vector<TRecursoMalla*> mallas;
    
    char* buffer;
    int n = 0;
    sprintf(buffer, "%d",n);
    std::string rutaF = archivo+ '(' + buffer + ')';
    
    while(FileExist(rutaF)){
        
        /*
         
         TO DO: CARGAR RECURSO FICHERO Y AÑADIR EN EL VECTOR
         
         */
        
        sprintf(buffer, "%d",n);
        rutaF = archivo+ '(' + buffer + ')';
        n++;
        
    }
    if(n==0)
        return false;
    
    n = 0;
    
    anim->NumFrames = mallas.size();
    anim->setFrames(mallas);
    
    it = animaciones.find(nombre);
    while(it!=animaciones.end()){
        sprintf(buffer, "%d",n);
        nombre = nombre + buffer;
        it = animaciones.find(nombre);
        n++;
    }
    
    if(!animacion_activa)
        animacion_activa = anim;
    
    animaciones.insert(std::pair<std::string, Animacion*>(nombre,anim));
    return true;
}

bool SkyMallaAnimada::CambiarAnimacion(std::string cambio){
    
    it = animaciones.find(cambio);
    if(it==animaciones.end())
        return false;
    
    animacion_activa->actual = 0;
    animacion_activa = it->second;
    t.reset();

    return true;
}

bool SkyMallaAnimada::FileExist(std::string ruta){
    FILE *fp;
    if ((fp = fopen(ruta.c_str(), "r"))){
        fclose(fp);
        return true;
    }
    return false;
}
