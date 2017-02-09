//
//  Layout.hpp
//  arquitectura
//
//  Created by Catherine Castrillo González on 08/02/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef LayoutGUI_hpp
#define LayoutGUI_hpp

#include <stdio.h>
#include "GUI.h"
#include "MenuPrincipalLayout.hpp"
#include "CargarPartidaLayout.hpp"
#include "OpcionesLayout.hpp"
#include "CreditosLayout.hpp"
#include "HUDLayout.hpp"
#include <vector>

class LayoutGUI {
public:
    LayoutGUI();
    ~LayoutGUI();
    void update();
    void setActiveLayout(tLayout nuevo);
    void posicionarRaton(float x, float y);
    void inyectarClick();
    void inyectarClickUP();
    
private:
    tLayout activeLayout;
    std::vector<Motor::GUI*>::iterator iter;
    std::vector<Motor::GUI*> vector;
    Motor::GUI* seleccionado;
    bool activo;
};

#endif /* LayoutGUI_hpp */
