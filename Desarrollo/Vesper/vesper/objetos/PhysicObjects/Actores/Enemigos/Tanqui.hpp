//
//  Tanqui.hpp
//  Arquitectura
//
//  Created by Gaspar Rodriguez Valero on 21/3/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#ifndef Tanqui_hpp
#define Tanqui_hpp

#include "../Enemy.hpp"

class Tanqui : public Enemy {
public:
    Tanqui(){}
    ~Tanqui(){}
    void render();
};

#endif /* Tanqui_hpp */
