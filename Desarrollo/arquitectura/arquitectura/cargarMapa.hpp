
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
    void mostrarMatriz();
    std::vector<int>* getMatriz();
	std::vector<dvector2D>* getParedes();
	std::vector<dvector2D>* get_posParedes();
	std::vector<dvector3D>* get_PosObjetos();
	
private:
    
	int _width;
    int _height;
    int _tileWidth;
    int _tileHeight;
    int _numLayers;
	
	std::vector<int> _tilemap;
	std::vector<dvector3D> _obj_map;
	std::vector<dvector2D> _objetos, _pos_objetos;
   // int matrizMapa[][][];
    
    //sf::Vector2f pos_ini;
    XMLElement * objs;
    XMLElement* tilesMov;
    //sf::VertexArray m_vertices;
    //sf::Texture m_tileset;
};

#endif /* cargarMapa_hpp */
