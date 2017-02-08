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
#include "LayoutInterface.hpp"
#include "MenuPrincipalLayout.hpp"
#include "CargarPartidaLayout.hpp"
#include "OpcionesLayout.hpp"
#include <vector>

class LayoutGUI {
public:
    LayoutGUI();
    ~LayoutGUI();
    void update();
    void setActiveLayout(tLayout nuevo);
    
private:
    tLayout activeLayout;
    std::vector<LayoutInterface*> vector;
};

#endif /* LayoutGUI_hpp */
