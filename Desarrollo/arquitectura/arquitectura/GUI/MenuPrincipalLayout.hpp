//
//  MenuPrincipalLayout.hpp
//  arquitectura
//
//  Created by Catherine Castrillo González on 08/02/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef MenuPrincipalLayout_hpp
#define MenuPrincipalLayout_hpp

#include <stdio.h>
#include "GUI.h"
#include "../MyEventReceiver.hpp"

class MenuPrincipalLayout : public Motor::GUI {
public:
    MenuPrincipalLayout();
    ~MenuPrincipalLayout();
//    void update() override;
    tLayout getLayout() override;
    void inicializar();
    
    void onClickStartGame(const CEGUI::EventArgs &e);
    void onClickLoadScreen(const CEGUI::EventArgs &e);
    void onClickOptions(const CEGUI::EventArgs &e);
    void onClickCredits(const CEGUI::EventArgs &e);
    void onClickStopGame(const CEGUI::EventArgs &e);
    
    // TO DO: provisisonal
    void onClickPausa(const CEGUI::EventArgs &e);

private:
    CEGUI::DefaultWindow *label_titulo;
    CEGUI::PushButton *button_nueva;
    CEGUI::PushButton *button_cargar;
    CEGUI::PushButton *button_opciones;
    CEGUI::PushButton *button_creditos;
    CEGUI::PushButton *button_salir;
    CEGUI::PushButton *button_pausa;

};

#endif /* MenuPrincipalLayout_hpp */
