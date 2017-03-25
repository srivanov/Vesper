//
//  Level.hpp
//  Arquitectura
//
//  Created by Gaspar Rodriguez Valero on 18/3/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#ifndef Level_hpp
#define Level_hpp


#include "loadLevel.hpp"
#include <string>


class Level {
    bool exportar_objetos(loadLevel& nivel);
    Player * p;
    Camera * c;
    vector<GameObject*> w;
    size_t it,end;
public:
    Level(){}
    ~Level();
    bool inicializar(char *numero);
    void render();
    void update();
};


#endif /* Level_hpp */
