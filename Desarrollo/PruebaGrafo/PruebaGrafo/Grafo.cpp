//
//  Grafo.cpp
//  PruebaGrafo
//
//  Created by Julia Martínez Valera on 27/1/17.
//  Copyright © 2017 Julia Martínez Valera. All rights reserved.
//

#include "Grafo.hpp"
#include <math.h>
#include <string>
#include <cstring>


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
    crearMatriz();
}
grafo::~grafo(){
    if (matriz) {
        for (int i=0; i<all_nodos.size(); i++) {
            delete[] matriz[i];
        }
        delete[] matriz;
    }
    for (int i=0; i<all_nodos.size(); i++) {
        delete all_nodos[i];
    }
    all_nodos.clear();
}

void grafo::crearMatriz(){
    matriz = new int **[all_nodos.size()];
    for (int i=0; i<all_nodos.size(); i++) {
        matriz[i] = new int*[all_nodos[i]->conexiones().size()];
        for (int j=0; j<all_nodos[i]->conexiones().size(); j++) {
            matriz[i][j]= new int(all_nodos[i]->conexiones()[j]->getID());
        }
    }
}

void grafo::calcularCamino(vector2d posIni,vector2d posFin){
    float distanciaCalculo,disNodoInicial = 666,disNodoFinal = 999;
    for (int i=0; i<all_nodos.size(); i++) {
        float x = fabsf(all_nodos[i]->getPosition().x-posIni.x);
        float y = fabsf(all_nodos[i]->getPosition().y-posIni.y);
        distanciaCalculo = x+y;
        if (disNodoInicial>distanciaCalculo) {
            disNodoInicial= distanciaCalculo;
            nodo_inicial = i;
        }
        x = fabsf(all_nodos[i]->getPosition().x-posFin.x);
        y = fabsf(all_nodos[i]->getPosition().y-posFin.y);
        distanciaCalculo = x+y;
        if (disNodoFinal>distanciaCalculo) {
            disNodoFinal= distanciaCalculo;
            nodo_final = i;
        }
        continue;
    }
    //if (nodo_inicial==0) return;
    while (iteacion());
    cleanWays();
    for (int i=0; i<caminos.size(); i++) {
        std::cout << caminos[i] << std::endl;
    }
    caminos.clear();
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
        all_nodos[i]->reset();
    }
}
bool grafo::iteacion(){
    int changes = 0;
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
    return changes;
}
