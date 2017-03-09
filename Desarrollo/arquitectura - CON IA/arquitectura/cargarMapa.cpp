
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
    
    //cargar los gids de diversas capas
    
    //Carga la primera capa de textura
    layer = map->FirstChildElement("layer");
    XMLElement *data = layer->FirstChildElement("data")->FirstChildElement("tile");
    int w = _width*_height, query;
    
    for(int k=0; k < w ; k++){
        data->QueryIntAttribute("gid", &query);
        _tilemap.push_back(query);
        
        //avanzo hasta al siguiente tag
        data = data->NextSiblingElement("tile");
    }
    
    //leemos los objetos que hay por el mapa
    if(_numLayers > 1){
        layer = layer->NextSiblingElement("layer");
        
        data = layer->FirstChildElement("data")->FirstChildElement("tile");
        
        int a = _width*_height, obj, x=0, y=0;
        
        for(int k=0; k < a ; k++){
            data->QueryIntAttribute("gid", &obj);
            if(obj != 0)
                _obj_map.push_back(dvector3D(x,y,obj));
            
            if(x == _width-1){
                x=0;
                y++;
            }else
                x++;
            //avanzo hasta al siguiente tag
            data = data->NextSiblingElement("tile");
        }
    }
    
    //LEER CAPA DE OBJETOS
    XMLElement* objectGroup = map->FirstChildElement("objectgroup");
    XMLElement* object = objectGroup->FirstChildElement("object");
    vector<int> nums_nodos;
    vector<string> conexiones_nodos;
    
    for (tinyxml2::XMLElement* child = map->FirstChildElement("objectgroup"); child != NULL; child = child->NextSiblingElement("objectgroup")){
        
        dvector2D separador(INT_MAX, INT_MAX);
        int i =0;
        string name_capa = child->Attribute("name");
        //cout<<"NAME CAPA: " <<name_capa<<endl;
        
        if(object == NULL && (child != NULL)){
            object = child->FirstChildElement();
        }
        
        while (object != NULL){
            if(name_capa == "muros"){
                //cout<<"HAS ENTRADOOOOOO 111"<<endl;
                dvector2D a(atoi(object->ToElement()->Attribute("x"))/_tileWidth, atoi(object->ToElement()->Attribute("y"))/_tileHeight);
                _pos_objetos.push_back(a);
                
                XMLElement* polylinea = object->FirstChildElement("polyline");
                while (polylinea != NULL) {
                    //            polylinea->QueryFloatAttribute("points", valor);
                    //            std::cout << polylinea->ToElement()->Attribute("points") << std::endl;
                    
                    char *puntosLinea = strdup(polylinea->ToElement()->Attribute("points"));
                    
                    char* punto = strtok(puntosLinea, " ");
                    
                    while (punto){
                        dvector2D point;
                        sscanf(punto, "%f,%f", &point.x, &point.y);
                        
                        _objetos.push_back(point);
                        
                        punto = strtok(0, " ");
                    }
                    free(puntosLinea);
                    
                    polylinea = polylinea->NextSiblingElement();
                    _objetos.push_back(separador);
                    
                    
                }
                
            }
            if(name_capa == "nodos"){
                // cout<<"HAS ENTRADOOOOOO"<<endl;
                
                //cout<<"ID OBJECT: "<< object->IntAttribute("id")<<endl;
                dvector2D pos_nodo(atoi(object->ToElement()->Attribute("x"))/_tileWidth, atoi(object->ToElement()->Attribute("y"))/_tileHeight);
                XMLElement* properties = object->FirstChildElement();
                XMLElement* property = properties->FirstChildElement();
                
                int num_nodo = object->IntAttribute("name");
                string conecta_nodos = property->Attribute("value");
                
                nums_nodos.push_back(num_nodo);
                conexiones_nodos.push_back(conecta_nodos);
                if(i == 0){
                    //                    cout <<"Nodo: " <<nums_nodos[i]<<endl;
                    //                    cout<<"Conecta: "<<conexiones_nodos[i]<<endl;
                    i++;
                }
                
                
            }
            object = object->NextSiblingElement();
        }
    }//for
    
    
    //	_objetos.back() = dvector2D(INT_MIN, INT_MIN);
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

std::vector<dvector2D>* cargarMapa::getParedes(){
	return &_objetos;
}

std::vector<dvector2D>* cargarMapa::get_posParedes(){
	return &_pos_objetos;
}

int cargarMapa::getTileWidth(){
    return _tileWidth;
}

int cargarMapa::getTileHeight(){
    return _tileHeight;
}

std::vector<dvector3D>* cargarMapa::get_PosObjetos(){
	return &_obj_map;
}


