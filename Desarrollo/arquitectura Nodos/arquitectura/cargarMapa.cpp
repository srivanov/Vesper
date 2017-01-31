
#include "cargarMapa.hpp"

#include <iostream>
#include <stdlib.h> //para crear variables dinamicas con new y delete
//#include "tinyxml2.h"
using namespace tinyxml2;
using namespace std;
//TO DO: revisar el cargador entero
cargarMapa::cargarMapa(){
    _width = 0;
    _height = 0;
    _tileWidth = 0;
    _tileHeight = 0;
    _numLayers = 0;
}

cargarMapa::~cargarMapa() {
    _tilemap.clear();
	delete _level;
}

bool cargarMapa::leerMapa(char* fichero) {
    
    XMLDocument doc;
   
    //doc.LoadFile("mapas/mapa1tiled.tmx");
    doc.LoadFile(fichero);
	if(doc.NoChildren())
		return false;
	
    //tamanyo mapa y de los tiles
    XMLElement* map = doc.FirstChildElement("map");
    map->QueryIntAttribute("width", &_width);
    map->QueryIntAttribute("height", &_height);
    map->QueryIntAttribute("tilewidth", &_tileWidth);
    map->QueryIntAttribute("tileheight", &_tileHeight);
    map->QueryIntAttribute("tileheight", &_tileHeight);
    
    cout << "width: "<<_width <<" height: "<<_height << endl; //w: tiles de ancho, h:tiles de alto del mapa tmx
    cout << "tilewd: "<<_tileWidth <<" tilehg: "<<_tileHeight << endl; //dimensiones del png de sprites
    
    //Capas del mapa
    XMLElement *layer = map->FirstChildElement("layer"); //primera capa, la de patrones
    while(layer){
        _numLayers++;
        layer = layer->NextSiblingElement("layer"); //Creamos a capa
    }
    
    //en el vector level de tamaño del alto por ancho del mapa(capa), guardo todos los valores de los tiles de la capa
    _level = new int [_width*_height];
    int cont = 0;
    //cargar los gids de diversas capas
	
    //Carga la primera capa de textura
    XMLElement *data = map->FirstChildElement("layer")->FirstChildElement("data")->FirstChildElement("tile");
    int w = _width*_height*_numLayers, query;
    
    for(int k=0; k < w ; k++){
       //en el vector level de tamaño del alto por ancho del mapa(capa), guardo todos los valores de los tiles de la capa
        _level[cont] = data->IntAttribute("gid")-1; //hasta q llega a 260 desde 1(ancho*alto)
        cont++;
        
        data->QueryIntAttribute("gid", &query);
        _tilemap.push_back(query);
        
        //avanzo hasta al siguiente tag
        data = data->NextSiblingElement("tile");
    }
    
    //LEER CAPA DE OBJETOS
    XMLElement* objectGroup = map->FirstChildElement("objectgroup");
    XMLElement* object = objectGroup->FirstChildElement("object");
//    for (tinyxml2::XMLElement* child = element->FirstChildElement("objectgroup"); child != NULL; child = child->NextSiblingElement("objectgroup"))
    float* valor;
//    std::vector<<#class _Tp#>>
    while (object != NULL) {
        XMLElement* polylinea = object->FirstChildElement("polyline");
        while (polylinea != NULL) {
//            polylinea->QueryFloatAttribute("points", valor);
            std::cout << polylinea->ToElement()->Attribute("points") << std::endl;
            polylinea = polylinea->NextSiblingElement();
        }
        object = object->NextSiblingElement();
    }
	return true;
}

int cargarMapa::getWidth(){
    return _width;
}

int cargarMapa::getHeight(){
    return _height;
}

void cargarMapa::mostrarMatriz(){
    int w1 = _width, h1 = _height;
    
    for(int i = 0; i<_numLayers; i++){
        for(int j =_height*i; j<h1; j++){
            for(int k = w1-_width; k<w1; k++){
                // muestra matriz de ints en la consola del mapa1
				cout<< _tilemap.at(k) << " ";
            }
            w1 += _width;
            cout << endl;
        }
        h1 = _height + _height*(i+1);
        w1 = _width + _width*_height*(i+1);
    }
    
}

std::vector<int>* cargarMapa::getMatriz(){
    return &_tilemap;
}

int cargarMapa::getTileWidth(){
    return _tileWidth;
}

int cargarMapa::getTileHeight(){
    return _tileHeight;
}
