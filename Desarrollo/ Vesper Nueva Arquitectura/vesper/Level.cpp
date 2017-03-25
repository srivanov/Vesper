//
//  Level.cpp
//  Arquitectura
//
//  Created by Gaspar Rodriguez Valero on 18/3/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#include "Level.hpp"

Level::~Level(){
	printf("DELETE LEVEL\n");
    delete p;
    delete c;
    
    while(w.size()>0){
        delete w[0];
        w.erase(w.begin());
    }
}

bool Level::inicializar(char *numero){
    loadLevel nivel;
    
    try {
        if(!nivel.load(numero)) throw LOADING_LEVEL;
        if(!exportar_objetos(nivel)) throw EXPORTING_DATA;
    } catch (LEVEL_ERRORS e) {
        std::string ERROR = " ### ERROR ### ";
        if(e==LOADING_LEVEL) ERROR+=" | LOADING LEVEL | ";
        if(e==EXPORTING_DATA) ERROR+=" | EXPORTING DATA | ";
        if(e==DELETE_DATA) ERROR+=" | DELETE DATA | ";
        if(e==READING_LAYER_DATA) ERROR+=" | LAYER DATA | ";
        if(e==READING_MURO_DATA) ERROR+=" | MURO DATA | ";
        if(e==READING_GRAPH_DATA) ERROR+=" | GRAPH DATA | ";
        if(e==GRAPH_NODO_CONNECTION) ERROR+=" | NODO CONNECTION | ";
        if(e==FACTORY_ERROR) ERROR+=" | FACTORY CONSTRUCTION | ";
        cout << ERROR << " ### ERROR ### " << endl;
        return false;
    }
    NpcLibrary::instancia();
    LevelBlackBoard::instance();
    trigger_system::instance();
    return true;
}

bool Level::exportar_objetos(loadLevel& nivel){
    
    w = nivel.getMundo();
    p = nivel.getPlayer();
    c = nivel.getCamara();
    if(w.empty() || !p || !c)
        return false;
    end = w.size();
    return true;
}

void Level::update(){
    trigger_system::instance()->update();
    
    
    c->update();
    p->update();
    
    for (it=0; it<end; it++)
        w[it]->update();
    
    
    
}

void Level::render(){
    c->render();
    p->render();
    
    for (it=0; it<end; it++)
        w[it]->render();
}
