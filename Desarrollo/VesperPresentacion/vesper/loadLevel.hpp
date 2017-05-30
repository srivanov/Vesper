//
//  loadLevel.hpp
//  Arquitectura
//
//  Created by Gaspar Rodriguez Valero on 18/3/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#ifndef loadLevel_hpp
#define loadLevel_hpp

#include "Dvector.hpp"
#include "PathFinding/PathPlanning.hpp"
#include "objetos/Objects.hpp"
#include "objetos/ObjectFactory.hpp"
#include "components/ventana.hpp"
#include "tinyxml2.h"
#include <iostream>
#include <stdio.h>

using namespace tinyxml2;
using namespace std;


enum LEVEL_ERRORS {
    UNKNOWN = 0,
    LOADING_LEVEL,
    READING_LAYER_DATA,
    READING_MURO_DATA,
    READING_GRAPH_DATA,
    EXPORTING_DATA,
    DELETE_DATA,
    GRAPH_NODO_CONNECTION,
    FACTORY_ERROR
};

class loadLevel {
    int m_width, m_height, m_tileWidth, m_tileHeight;
    int m_numLayers, *m_tilemap;
    vector<dvector3D> m_obj ;
    vector<dvector2D> objetos , pos_objetos ;
    dvector2D ConvertDataPosition2D(XMLElement*);
    void readPolyline(XMLElement*);
    const vector<std::string> explode(const std::string& s, const char& c);
    vector<GameObject*> Mundo;
    Player* player;
    Camera* camara;
    Rehen* rehen;
    Salida * salida;
    void CreateWorld();
    int LLAVES, puerta;
public:
    bool load(char* fichero);
    vector<GameObject*> getMundo() {return Mundo;}
    Camera * getCamara() {return camara;}
    Player * getPlayer() {return player;}
    
    loadLevel();
    ~loadLevel();
};

#endif /* loadLevel_hpp */
