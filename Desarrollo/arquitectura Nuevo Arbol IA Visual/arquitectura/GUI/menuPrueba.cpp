//
//  menuPrueba.cpp
//  arquitectura
//
//  Created by Catherine Castrillo González on 01/02/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "menuPrueba.hpp"
#include "../components/ventana.hpp"
#include "Game.hpp"

void menuPrueba::inicializar(){
    init("3d/GUI", ventana::Instance()->getDevice());
    
    loadScheme("OgreTray.scheme");
    loadLayout("vista.layout");
    setMouseCursor("OgreTrayImages/MouseArrow");
    
    
}
