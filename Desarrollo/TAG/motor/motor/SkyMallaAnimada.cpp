//
//  SkyMallaAnimada.cpp
//  motor
//
//  Created by Gaspar Rodriguez Valero on 14/5/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "SkyMallaAnimada.hpp"

SkyMallaAnimada::SkyMallaAnimada(TNodo * padre) {
    
    nodo = new TNodo();
    
    m_mallas = new TMallaAnimada();
    
    buildTransform();
    
    nodo->setEntidad(m_mallas);
    
    TransNodos[0]->addHijo(nodo);
    
    padre->addHijo(TransNodos[2]);
    
    t.start();
    
}

SkyMallaAnimada::~SkyMallaAnimada(){}

bool SkyMallaAnimada::AnyadirAnimacion(std::string ruta, std::string nombre, float time,unsigned int NumberFrames){
    bool answer;
    if(m_mallas)
         answer = m_mallas->setAnimacion(ruta, nombre, time,NumberFrames);
    else
        return false;
    return answer;
}

bool SkyMallaAnimada::CambiarAnimacion(std::string cambio){
    bool answer;
    if(m_mallas)
        answer = m_mallas->ChangeAnimacion(cambio);
    else
        return false;
    return answer;
}

