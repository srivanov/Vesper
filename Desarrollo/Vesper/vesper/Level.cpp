//
//  Level.cpp
//  Arquitectura
//
//  Created by Gaspar Rodriguez Valero on 18/3/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#include "Level.hpp"

Level::Level() : p(nullptr) , c(nullptr){
    iniciado=false;
    actualState = states::Instance();
    input = InputManager::Instance();
}

Level::~Level(){
	printf("DELETE LEVEL\n");
	if(iniciado)
		destroy();
}

bool Level::inicializar(){
    loadLevel nivel;
	char numero[3];
    sprintf(numero, "%d", actualState->nivel);
    try {
        if(!nivel.load(numero)) throw LOADING_LEVEL;
        if(!exportar_objetos(nivel)) throw EXPORTING_DATA;
    } catch (LEVEL_ERRORS e) {
        std::string m_ERROR = " ### m_ERROR ### ";
        if(e==LOADING_LEVEL)        m_ERROR+=" | LOADING LEVEL | ";
        if(e==EXPORTING_DATA)       m_ERROR+=" | EXPORTING DATA | ";
        if(e==DELETE_DATA)          m_ERROR+=" | DELETE DATA | ";
        if(e==READING_LAYER_DATA)   m_ERROR+=" | LAYER DATA | ";
        if(e==READING_MURO_DATA)    m_ERROR+=" | MURO DATA | ";
        if(e==READING_GRAPH_DATA)   m_ERROR+=" | GRAPH DATA | ";
        if(e==GRAPH_NODO_CONNECTION)m_ERROR+=" | NODO CONNECTION | ";
        if(e==FACTORY_ERROR)        m_ERROR+=" | FACTORY CONSTRUCTION | ";
        cout << m_ERROR << " ### ERROR ### " << endl;
        return iniciado;
    }
    NpcLibrary::instancia();
    LevelBlackBoard::instance();
    gestor_eventos::instance();
    iniciado = true;
    return iniciado;
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

void Level::clear(){
    printf("");
    for (it=0; it<w.size(); it++)
        if(w[it]->Eliminable()){
            delete w[it];
            w.erase(w.begin()+it);
            it=0;
        }
    end = w.size();
}

void Level::update(const long &timePerFrame){
	if(!iniciado){
		inicializar();
	}
    clear();
    
    if(input->isPressed(SKY_KEY_ESCAPE)){
        actualState->nextState = MENU;
        actualState->menu = tmPAUSE;
    }
    
    c->update();
    p->update();
    
    for (it=0; it<end; it++)
        w[it]->update();
        
    mundoBox2D::Instance()->update(timePerFrame);
    gestor_eventos::instance()->update();
}

void Level::render(float &interpolation){
    c->render(interpolation);
    p->render(interpolation);
    
    for (it=0; it<end; it++)
        w[it]->render(interpolation);
}

void Level::destroy(){
    //TO DO: eliminar los datos del nivel actual (jugador, objetos...)
    printf("DESTROY LEVEL\n");
	delete p;
	delete c;
	
	while(w.size()>0){
		delete w[0];
		w.erase(w.begin());
	}
	mundoBox2D::Instance()->cleanWorld();
	iniciado = false;
}


