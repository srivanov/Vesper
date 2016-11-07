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
#endif /* cargarMapa_hpp */

class cargarMapa{
public:
    cargarMapa();
    void leerMapa();
    int getWidth();
    int getHeight();
    int getTileWidth();
    int getTileHeight();
    int * getLevel();
    
    //virtual ~cargarMapa();
private:
    
    int _width;
    int _height;
    int _tileWidth;
    int _tileHeight;
    int _numLayers;
    int *_level;
    int ***matrizMapa;
    
    //sf::Vector2f pos_ini;
    XMLElement * objs;
    XMLElement* tilesMov;
    //sf::VertexArray m_vertices;
    //sf::Texture m_tileset;
};
