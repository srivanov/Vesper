//
//  LanzaPinchos.hpp
//  Arquitectura
//
//  Created by Gaspar Rodriguez Valero on 21/3/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#ifndef LanzaPinchos_hpp
#define LanzaPinchos_hpp

#include "../Enemy.hpp"

class LanzaPinchos : public Enemy {
    
public:
    void render();
    ~LanzaPinchos();
    LanzaPinchos();
};

#endif /* LanzaPinchos_hpp */
