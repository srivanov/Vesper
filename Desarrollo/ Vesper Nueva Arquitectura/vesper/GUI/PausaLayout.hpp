//
//  PausaLayout.hpp
//  arquitectura
//
//  Created by Catherine Castrillo González on 18/02/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef PausaLayout_hpp
#define PausaLayout_hpp

#include <stdio.h>
#include "GUI.h"
#include "../MyEventReceiver.hpp"

class PausaLayout : public GUI {
public:
    PausaLayout();
    ~PausaLayout();
    void init(CEGUI::RenderTarget* target);
    
    void onClickContinuar(const CEGUI::EventArgs &e);
    void onClickGuardar(const CEGUI::EventArgs &e);
    void onClickMenuPrincipal(const CEGUI::EventArgs &e);
    void onClickSalir(const CEGUI::EventArgs &e);
    
private:
    CEGUI::DefaultWindow *label_pausa;
    CEGUI::PushButton *button_continuar;
    CEGUI::PushButton *button_guardar;
    CEGUI::PushButton *button_menuprincipal;
    CEGUI::PushButton *button_salir;
    
};

#endif /* PausaLayout_hpp */
