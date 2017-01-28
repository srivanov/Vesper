
#ifndef cargarMapa_hpp
#define cargarMapa_hpp

#include <stdio.h>
#include "tinyxml2.h"
#include <iostream>
#include <vector>
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
    std::vector<int> _tilemap;
    void mostrarMatriz();
    std::vector<int>* getMatriz();
    
private:
    
	int _width;
    int _height;
    int _tileWidth;
    int _tileHeight;
    int _numLayers;
    int *_level;
    
   // int matrizMapa[][][];
    
    //sf::Vector2f pos_ini;
    XMLElement * objs;
    XMLElement* tilesMov;
    //sf::VertexArray m_vertices;
    //sf::Texture m_tileset;
};

#endif /* cargarMapa_hpp */
