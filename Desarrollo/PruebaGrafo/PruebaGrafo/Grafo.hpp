//
//  Grafo.hpp
//  PruebaGrafo
//
//  Created by Julia Martínez Valera on 27/1/17.
//  Copyright © 2017 Julia Martínez Valera. All rights reserved.
//

#ifndef Grafo_hpp
#define Grafo_hpp

#include "Nodo.hpp"
#include <iostream>
#include <math.h>
#include <string>
#include <cstring>

struct BolsaNodos{
    BolsaNodos(){}
    ~BolsaNodos(){nodos.clear();F.clear();}
    void add_nodo(Nodo* nodo, float _F);
    void recalcular();
    void camino();
private:
    std::vector<Nodo*> nodos;
    std::vector<float> F;
};

class grafo{
    std::vector<Nodo*> all_nodos;
    BolsaNodos abierta;
    bool iteacion();
    
    
    std::vector<std::string> caminos;
    void cleanWays();
    int nodo_inicial = 0, nodo_final = 0;
    const std::vector<std::string> explode(const std::string& s, const char& c);
public:
    void reset();
    void calcularCamino(vector2d posIni,vector2d posFin);
    grafo(std::vector<Nodo*> nodos_vector);
    ~grafo();
};

#endif /* Grafo_hpp */
