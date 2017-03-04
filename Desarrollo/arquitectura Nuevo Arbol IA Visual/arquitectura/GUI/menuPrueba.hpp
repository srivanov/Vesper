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
#include "../components/ventana.hpp"
#include "../MyEventReceiver.hpp"

class menuPrueba : public Motor::GUI {
public:
    menuPrueba(){
        init("3d/GUI", ventana::Instance()->getDevice());
        
        loadScheme("OgreTray.scheme");
        loadLayout("vista.layout");
        setMouseCursor("OgreTrayImages/MouseArrow");
    }
    ~menuPrueba(){}
    void inicializar();
    
private:
    CEGUI::ProgressBar *salud;
};

#endif /* menuPrueba_hpp */
