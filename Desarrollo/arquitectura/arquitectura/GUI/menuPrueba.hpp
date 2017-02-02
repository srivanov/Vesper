//
//  menuPrueba.hpp
//  arquitectura
//
//  Created by Catherine Castrillo González on 01/02/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef menuPrueba_hpp
#define menuPrueba_hpp

#include <stdio.h>
#include "GUI.h"

class menuPrueba : public Motor::GUI {
public:
    menuPrueba(){}
    ~menuPrueba(){}
    void inicializar();
    void update();
private:
    CEGUI::DefaultWindow *label_prueba;
};

#endif /* menuPrueba_hpp */
