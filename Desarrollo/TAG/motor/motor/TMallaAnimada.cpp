//
//  TMallaAnimada.cpp
//  motor
//
//  Created by Gaspar Rodriguez Valero on 16/5/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "TMallaAnimada.hpp"

Animacion::Animacion() : frames(nullptr) {
    actual = NumFrames = 0 ;
    AnimationTime = 0.f;
}
Animacion::~Animacion(){}

void Animacion::setFrames(std::vector<TRecursoMalla *> mallas){
    if(NumFrames==0) NumFrames = mallas.size();
    
    frames = new TRecursoMalla*[NumFrames];
    size_t cont = 0;
    while (mallas.size()!=0) {
        frames[cont] = mallas[0];
        mallas.erase(mallas.begin());
        cont++;
    }
    
}

void Animacion::nextFrame(){
    actual = ((actual++) == NumFrames ? 0 : actual);
}

TMallaAnimada::TMallaAnimada() : animacion_activa(nullptr) , textura(nullptr) {
    pila = Pila::Instance();
    gestor = TGestorRecursos::Instance();
    sh = ShaderManager::Instance()->getActivo();
    t.start();
}

void TMallaAnimada::setTextura(char *fichero){
    textura = static_cast<TRecursoTextura*>(gestor->getRecurso(fichero, tRTextura));
}

TMallaAnimada::~TMallaAnimada(){}

bool TMallaAnimada::setAnimacion(std::string ruta, std::string nombre, float time, unsigned int NumberFrames){
    
    Animacion * anim = new Animacion;
    
    anim->AnimationTime = time;
    
    std::string archivo = ruta + nombre;
    
    std::vector<TRecursoMalla*> mallas;
    
    char* buffer;
    int n = 0;
    sprintf(buffer, "%d",n);
    std::string rutaF = archivo+ '(' + buffer + ')';
    
    while(FileExist(rutaF)){
        
        
        TRecursoMalla * malla = static_cast<TRecursoMalla*>(gestor->getRecurso(rutaF, tRMalla));
        
        mallas.push_back(malla);
        
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

bool TMallaAnimada::FileExist(std::string ruta){
    FILE *fp;
    if ((fp = fopen(ruta.c_str(), "r"))){
        fclose(fp);
        return true;
    }
    return false;
}

void TMallaAnimada::beginDraw(){
    sh = ShaderManager::Instance()->getActivo();
    
    pila->calculaMVP();
    pila->calculoFrustum();
    
    
    TRecursoMalla * malla = animacion_activa->frameActivo();
    
    bool control = pila->AABB_Frustum_Test(malla->getminBB(), malla->getmaxBB());
    
    glUniformMatrix4fv(glGetUniformLocation(sh->Program, "model"), 1, GL_FALSE, glm::value_ptr(pila->actual));
    glUniformMatrix4fv(glGetUniformLocation(sh->Program, "MVP"), 1, GL_FALSE, glm::value_ptr(pila->MVP));
    
    //if(control){
        if(textura)
            malla->Draw(sh, textura->getTexture());
        else
            malla->Draw(sh, nullptr);
    //}
    
    
}

bool TMallaAnimada::ChangeAnimacion(std::string nombre){
    it = animaciones.find(nombre);
    if(it==animaciones.end())
        return false;
    
    t.reset();
    animacion_activa->resetAnimacion();
    animacion_activa = it->second;
    return true;
}

void TMallaAnimada::endDraw(){
    // CALCULA EL TIEMPO POR FRAME
    float tPf = animacion_activa->AnimationTime / animacion_activa->NumFrames;
    // CONTADOR PARA PROXIMOS FRAMES
    unsigned int nextF = 1;
    // TIEMPO TRANSCURRIDO
    long tt = t.getTiempo();
    // MIENSTRAS EL TIEMPO TRANSCURRIDO SEA SUPERIOR A
    // EL TIEMPO ENTRE FRAMES POR NUMERO DE FRAMES
    while(tt > nextF*tPf*MILI){
        animacion_activa->nextFrame();
        nextF++;
    }
    t.reset();
}
