//
//  cargarMapa.hpp
//  mapa
//
//  Created by Julia Martínez Valera on 5/11/16.
//  Copyright © 2016 Julia Martínez Valera. All rights reserved.
//

#ifndef cargarMapa_hpp
#define cargarMapa_hpp

#include <stdio.h>
#include "tinyxml2.h"
#include <iostream>
using namespace tinyxml2;


class cargarMapa{
public:
    cargarMapa();
    ~cargarMapa();
    bool leerMapa(char* fichero);
    int getWidth();
    int getHeight();
    int getTileWidth();
    int getTileHeight();
    int * getLevel();
    //int getMatriz()[][][] const;
    //virtual ~cargarMapa();
    int ***_tilemap;
    void mostrarMatriz();
    int*** getMatriz();
    
private:
    
	int _width;
    int _height;
    int _tileWidth;
    int _tileHeight;
    int _numLayers;
    int *_level;
    int ***matrizMapa;
    
   // int matrizMapa[][][];
    
    //sf::Vector2f pos_ini;
    XMLElement * objs;
    XMLElement* tilesMov;
    //sf::VertexArray m_vertices;
    //sf::Texture m_tileset;
};

#endif /* cargarMapa_hpp */
