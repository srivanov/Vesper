//
//  cargarMapa.cpp
//  mapa
//
//  Created by Julia Martínez Valera on 5/11/16.
//  Copyright © 2016 Julia Martínez Valera. All rights reserved.
//

#include "cargarMapa.hpp"

#include <iostream>
#include <stdlib.h> //para crear variables dinamicas con new y delete
//#include "tinyxml2.h"
using namespace tinyxml2;
using namespace std;

cargarMapa::cargarMapa(){
    _width = 0;
    _height = 0;
    _tileWidth = 0;
    _tileHeight = 0;
    _numLayers = 0;
}

void cargarMapa::leerMapa() {
    ////////////////////////////////////////////////////////////////////////////////////
    // CAPA DE TEXTURAS
    
    XMLDocument doc;
   
    //doc.LoadFile("mapas/mapa1tiled.tmx");
    doc.LoadFile("../../../mapa/tiled/mapa2.tmx");
   
    
    //tamanyo mapa y de los tiles
    XMLElement* map = doc.FirstChildElement("map");
    map->QueryIntAttribute("width", &_width);
    map->QueryIntAttribute("height", &_height);
    map->QueryIntAttribute("tilewidth", &_tileWidth);
    map->QueryIntAttribute("tileheight", &_tileHeight);
    map->QueryIntAttribute("tileheight", &_tileHeight);
    
    cout << "width: "<<_width <<" height: "<<_height << endl; //w: tiles de ancho, h:tiles de alto del mapa tmx
    cout << "tilewd: "<<_tileWidth <<" tilehg: "<<_tileHeight << endl; //dimensiones del png de sprites
    
    //Imagen del tileset
    XMLElement *img = map->FirstChildElement("tileset")->FirstChildElement("image");
    const char *filename = img->Attribute("source");
    
    //guardar la altura y ancho de la tilesheet
    int _tswidth;
    int _tsheight;
    _tsheight = atoi(img->Attribute("height"));
    _tswidth = atoi(img->Attribute("width"));
    cout << "source-> "<<filename << endl;
    cout << "AnchoAllSprites: " <<_tswidth << " AltoAllSprites: "<<_tsheight<<endl;
    
    //Capas del mapa
    XMLElement *layer = map->FirstChildElement("layer"); //primera capa, la de patrones
    while(layer){
        _numLayers++;
        layer = layer->NextSiblingElement("layer"); //Creamos a capa
    }
    
    
    //RESERVO MEMORIA PARA LAS CAPAS Y SU TAMAÑO
    //reservo memoria como si fuera un vector y luego la recorro
     _tilemap = new int ** [_numLayers];
     
     for(int l = 0; l < _numLayers; l++) { //filas
        _tilemap[l] = new int * [_height];
     }
     
     for(int l = 0; l < _numLayers; l++) {
        for(int y = 0; y < _height; y++) { //columnas
            _tilemap[l][y] = new int [_width];
        }
     }
    
    //en el vector level de tamaño del alto por ancho del mapa(capa), guardo todos los valores de los tiles de la capa
    _level = new int [_width*_height];
    int cont = 0;
    //cargar los gids de diversas capas
    XMLElement  *data[_width*_height];
    //Carga la primera capa de textura
    data[0] = map->FirstChildElement("layer")->FirstChildElement("data")->FirstChildElement("tile");
    for(int l=0; l<_numLayers; l++){
        for(int y=0; y<_height; y++){
            for(int x=0; x<_width; x++){
               //en el vector level de tamaño del alto por ancho del mapa(capa), guardo todos los valores de los tiles de la capa
                _level[cont] = data[l]->IntAttribute("gid")-1; //hasta q llega a 260 desde 1(ancho*alto)
                cont++;
                data[l]->QueryIntAttribute("gid", &_tilemap[l][y][x]);

                //avanzo hasta el siguiente tag
                data[l] = data[l]->NextSiblingElement("tile");

              
            }
        }
    }

    ////////////////////////////////////////////////////////////////////////////////////
    // AQUI EMPIEZA LA CAPA DE OBJETOS
    ////////////////////////////////////////////////////////////////////////////////////
    cout <<"Empiezo a compilar objetos" <<endl;
    objs = map->FirstChildElement("objectgroup");

}

int cargarMapa::getWidth(){
    return _width;
}

int cargarMapa::getHeight(){
    return _height;
}


void cargarMapa::mostrarMatriz(){
    for(int l=0; l<_numLayers; l++){
        for(int y=0; y<_height; y++){
            for(int x=0; x<_width; x++){
                // muestra matriz de ints en la consola del mapa1
                cout<< _tilemap[l][y][x] << " ";
                if(x == _width-1){
                    cout<< endl;
                }
            }
        }        
    }
    
}

cargarMapa::~cargarMapa(){
    delete _tilemap;
    delete _level;
    delete matrizMapa;
    //delete objs;
    //delete tilesMov;
}


int*** cargarMapa::getMatriz(){
    return _tilemap;
}

int cargarMapa::getTileWidth(){
    return _tileWidth;
}

int cargarMapa::getTileHeight(){
    return _tileHeight;
}
