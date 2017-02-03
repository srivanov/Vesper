//
//  Grafo.cpp
//  PruebaGrafo
//
//  Created by Julia Martínez Valera on 27/1/17.
//  Copyright © 2017 Julia Martínez Valera. All rights reserved.
//

#include "Grafo.hpp"


void BolsaNodos::add_nodo(Nodo *nodo , float _F){
    nodos.push_back(nodo);
    F.push_back(_F);
}

void BolsaNodos::camino(){
    for (int i=0; i<nodos.size(); i++) {
        std::cout << nodos[i]->getID() << " " << std::endl;
    }
}

const std::vector<std::string> grafo::explode (const std::string &s, const char &c){
    std::string buff{""};
    std::vector<std::string> v;
    for(auto n:s)
    {
        if(n != c) buff+=n; else
            if(n == c && buff != "") { v.push_back(buff); buff = ""; }
    }
    if(buff != "") v.push_back(buff);
    
    return v;
}




grafo::grafo(std::vector<Nodo*> nodos_vector){
    all_nodos = nodos_vector;
}
grafo::~grafo(){
    for (int i=0; i<all_nodos.size(); i++) {
        delete all_nodos[i];
    }
    all_nodos.clear();
}


void grafo::calcularCamino(vector2d posIni,vector2d posFin){
    float distanciaCalculo,disNodoInicial = -1,disNodoFinal = -1;
    float x, y;
    for (int i=0; i<all_nodos.size(); i++) {
        x = fabsf(all_nodos[i]->getPosition().x-posIni.x);
        y = fabsf(all_nodos[i]->getPosition().y-posIni.y);
        distanciaCalculo = x+y;
        if (disNodoInicial==-1 || disNodoInicial>distanciaCalculo) {
            disNodoInicial= distanciaCalculo;
            nodo_inicial = all_nodos[i]->getID();
        }
        x = fabsf(all_nodos[i]->getPosition().x-posFin.x);
        y = fabsf(all_nodos[i]->getPosition().y-posFin.y);
        distanciaCalculo = x+y;
        if (disNodoFinal==-1 || disNodoFinal>distanciaCalculo) {
            disNodoFinal= distanciaCalculo;
            nodo_final = all_nodos[i]->getID();
        }
        continue;
    }
    abierta.add_nodo(all_nodos[nodo_inicial], 1.f);
    while (iteacion());
    abierta.camino();
    //cleanWays();
    /*for (int i=0; i<caminos.size(); i++) {
        std::cout << caminos[i] << std::endl;
    }
    caminos.clear();*/
}

void grafo::cleanWays(){
    for (int i=0; i<caminos.size(); i++) {
        std::vector<std::string> v{explode(caminos[i],'-')};
        int nodo =  stoi(v[v.size()-1]);
        if(nodo!=nodo_final) {
            caminos.erase(caminos.begin()+i);
            i=0;
        }
    }
}

void grafo::reset(){
    for (int i=0; i<all_nodos.size(); i++) {
        all_nodos[i]->setPass(false);
    }
}
bool grafo::iteacion(){
    bool response;
    std::vector<float> F;
    int NodoBolsa = -1;
    std::vector<Nodo*> vecAux = all_nodos[nodo_inicial]->conexiones();
    for (int i=0; i<vecAux.size(); i++) {
        float f, x , y ;
        x = fabsf(all_nodos[nodo_final]->getPosition().x-vecAux[i]->getPosition().x);
        y = fabsf(all_nodos[nodo_final]->getPosition().y-vecAux[i]->getPosition().y);
        f = all_nodos[nodo_inicial]->getArista(i)->getValue() + x + y;
        F.push_back(f);
    }
    float aux = -1;
    for (int i=0; i<F.size(); i++) {
        if(aux==-1 || (F[i]<aux && !vecAux[i]->getPass())){
            aux = F[i];
            NodoBolsa = i;
        }
    }
    if (vecAux[NodoBolsa]->getID()==nodo_final) response = false;
    else response = true;
    vecAux[NodoBolsa]->setPass(true);
    abierta.add_nodo(vecAux[NodoBolsa], F[NodoBolsa]);
    nodo_inicial = vecAux[NodoBolsa]->getID();
    
    vecAux.clear();
    F.clear();
    //int changes = 0;
    /*
     if (caminos.empty()) {
        // Crea el primer camino
        all_nodos[nodo_inicial]->pasado();
        std::string camino = std::to_string(nodo_inicial);
        caminos.push_back(camino);
        changes++;
        
    }else{
        // COMO EL TAMAÑO ES MODIFICADO EN EL BUCLE MANTENEMOS EL TAMAÑO ANTERIOR
        size_t ActualSize = caminos.size();
        // A partir del primer camino calcula los siguientes
        for (int i=0; i<ActualSize; i++) {
            std::string camino = caminos[i];
            // sacar ultimo nodo y convertirlo a int
            std::vector<std::string> v{explode(camino,'-')};
            int nodo =  stoi(v[v.size()-1]);
            if (nodo==nodo_final) continue;
            // obtener nodos conexos sin utilizar
            std::vector<int> nodos_nuevos;
            for (int j=0; j<all_nodos[nodo]->conexiones().size();j++) {
                if(!all_nodos[nodo]->conexiones()[j]->getPass()){
                    nodos_nuevos.push_back(all_nodos[nodo]->conexiones()[j]->getID());
                    if(all_nodos[nodo]->conexiones()[j]->getID()!=nodo_final)
                        all_nodos[nodo]->conexiones()[j]->pasado();
                }
            }
            // añado los nuevos nodos y los nuevos caminos
            for (int j=0; j<nodos_nuevos.size(); j++) {
                changes++;
                std::string Act_camino = camino+"-"+std::to_string(nodos_nuevos[j]);
                if (j==0) caminos[i] = Act_camino;
                else caminos.push_back(Act_camino);
            }
        }
    }
     */
    return response;
}
