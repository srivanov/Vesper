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

class OpcionesLayout : public Motor::GUI {
public:
    OpcionesLayout();
    ~OpcionesLayout();
//    void update() override;
    tLayout getLayout() override;
    void onClickControles(const CEGUI::EventArgs &e);
    void onClickSonido(const CEGUI::EventArgs &e);
    void onClickPantalla(const CEGUI::EventArgs &e);
    void onClickVolver(const CEGUI::EventArgs &e);
    
private:
    CEGUI::DefaultWindow *label_ajustes;
    CEGUI::PushButton *button_controles;
    CEGUI::PushButton *button_sonido;
    CEGUI::PushButton *button_pantalla;
    CEGUI::PushButton *button_volver;
};

#endif /* OpcionesLayout_hpp */
