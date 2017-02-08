//
//  OpcionesLayout.hpp
//  arquitectura
//
//  Created by Nerea Castellanos Rodríguez on 8/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef OpcionesLayout_hpp
#define OpcionesLayout_hpp

#include <stdio.h>
#include "GUI.h"
#include "../MyEventReceiver.hpp"
#include "menuPrueba.hpp"

class OpcionesLayout : public Motor::GUI{
public:
    OpcionesLayout();
    ~OpcionesLayout();
    void inicializar();
private:
    CEGUI::DefaultWindow *label_ajustes;
    CEGUI::PushButton *button_controles;
    CEGUI::PushButton *button_sonido;
    CEGUI::PushButton *button_pantalla;
};

#endif /* OpcionesLayout_hpp */
