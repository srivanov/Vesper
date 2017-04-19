//
//  Level.hpp
//  Arquitectura
//
//  Created by Gaspar Rodriguez Valero on 18/3/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#ifndef Level_hpp
#define Level_hpp

#include <string>
#include "loadLevel.hpp"
#include "estados.h"
#include "state.hpp"
#include "HUDLayout.hpp"
#include <SkyEngine/InputManager.h>


class Level  : public state{
    bool exportar_objetos(loadLevel& nivel);
    Player * p;
    Camera * c;
    vector<GameObject*> w;
    size_t it,end;
    bool iniciado;
    void clear();
    InputManager* input;
public:
    Level();
    ~Level();
    bool lvlActivo() const {return iniciado;}
    bool inicializar(char *numero);
    void render();
    void update();
    void destroy();
	HUDLayout hud;
};


#endif /* Level_hpp */
