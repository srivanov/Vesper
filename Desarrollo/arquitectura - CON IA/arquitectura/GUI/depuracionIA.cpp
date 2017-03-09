//
//  depuracionIA.cpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 9/3/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "depuracionIA.hpp"
#include "../components/ventana.hpp"
#include "Game.hpp"

depuracionIA::depuracionIA(){
    init("3d/GUI", ventana::Instance()->getDevice());
    
    layout = tdepuracionIA;
    
    loadScheme("OgreTray.scheme");
    
    loadLayout("interfaz.layout");
    setMouseCursor("OgreTrayImages/MouseArrow");
    
    
}

depuracionIA::~depuracionIA(){
    
}

tLayout depuracionIA::getLayout(){
    return layout;
}
