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
    void onClickResol1(const CEGUI::EventArgs &e);
    void onClickResol2(const CEGUI::EventArgs &e);
    void onClickResol3(const CEGUI::EventArgs &e);
    void onClickGuardar(const CEGUI::EventArgs &e);
    void setControles();
    
private:
    CEGUI::DefaultWindow *label_ajustes;
    CEGUI::PushButton *button_controles;
    CEGUI::PushButton *button_sonido;
    CEGUI::PushButton *button_pantalla;
    CEGUI::PushButton *button_volver;
    CEGUI::PushButton *button_resol1;
    CEGUI::PushButton *button_resol2;
    CEGUI::PushButton *button_resol3;
    CEGUI::PushButton *button_guardar;
    CEGUI::ToggleButton *check_sonido;
    CEGUI::Slider *slider_volumen;
    
    CEGUI::DefaultWindow *contenedor_pantalla;
    CEGUI::DefaultWindow *contenedor_sonido;
    CEGUI::DefaultWindow *contenedor_controles;

    int volumen;
	const char* controlesFile = "controles.json";
};

#endif /* OpcionesLayout_hpp */
