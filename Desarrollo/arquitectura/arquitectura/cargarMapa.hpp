
#ifndef cargarMapa_hpp
#define cargarMapa_hpp

#include <stdio.h>
#include "tinyxml2.h"
#include "Dvector.hpp"
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
    void mostrarMatriz();
    std::vector<int>* getMatriz();
	std::vector<dvector2D>* getObjetos();
	std::vector<dvector2D>* get_posObjetos();
    
private:
    
	int _width;
    int _height;
    int _tileWidth;
    int _tileHeight;
    int _numLayers;
    int *_level;
	
	std::vector<int> _tilemap;
	std::vector<dvector2D> _objetos, _pos_objetos;
   // int matrizMapa[][][];
    
    //sf::Vector2f pos_ini;
    XMLElement * objs;
    XMLElement* tilesMov;
    //sf::VertexArray m_vertices;
    //sf::Texture m_tileset;
};

#endif /* cargarMapa_hpp */
