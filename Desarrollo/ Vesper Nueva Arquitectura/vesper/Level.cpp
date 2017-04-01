//
//  Level.cpp
//  Arquitectura
//
//  Created by Gaspar Rodriguez Valero on 18/3/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#include "Level.hpp"

Level::Level(){
    iniciado=false;
    actualState = states::Instance();
    input = InputManager::Instance();
}

Level::~Level(){
	printf("DELETE LEVEL\n");
	if(iniciado)
		destroy();
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
        return iniciado;
    }
    NpcLibrary::instancia();
    LevelBlackBoard::instance();
    gestor_eventos::instance();
	hud.init();
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
//TO DO: mirar por si se puede optimizar
void Level::clear(){
    for (it=0; it<w.size(); it++)
        if(w[it]->Eliminable()){
            delete w[it];
            w.erase(w.begin()+it);
            it=0;
        }
    end = w.size();
}

void Level::update(){
	if(!iniciado)
		inicializar("3");
    clear();
    
    if(input->isPressed(SKY_KEY_ESCAPE)){
        actualState->nextState = MENU;
        actualState->menu = tmPAUSE;
    }
    //TO DO: poner el resto para elegir personajes
    
    c->update();
    p->update();
    
    for (it=0; it<end; it++)
        w[it]->update();
        
    mundoBox2D::Instance()->update();
    gestor_eventos::instance()->update();
}

void Level::render(){
    c->render();
    p->render();
    
    for (it=0; it<end; it++)
        w[it]->render();
	hud.render();
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
	iniciado = false;
}


