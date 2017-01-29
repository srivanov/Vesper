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

class grafo{
    int*** matriz;
    std::vector<Nodo*> all_nodos;
    std::vector<std::string> caminos;
    void crearMatriz();
    void cleanWays();
    bool iteacion();
    int nodo_inicial = 0, nodo_final = 0;
    const std::vector<std::string> explode(const std::string& s, const char& c);
public:
    void reset();
    void calcularCamino(vector2d posIni,vector2d posFin);
    grafo(std::vector<Nodo*> nodos_vector);
    ~grafo();
};

#endif /* Grafo_hpp */
