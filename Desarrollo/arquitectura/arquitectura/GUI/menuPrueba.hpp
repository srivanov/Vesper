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
#include "../MyEventReceiver.hpp"

class menuPrueba : public Motor::GUI {
public:
    menuPrueba(){}
    ~menuPrueba(){}
    void inicializar();
    void update();
    void onClickStartGame(const CEGUI::EventArgs &e);
    void onClickLoadScreen(const CEGUI::EventArgs &e);
    void onClickOptions(const CEGUI::EventArgs &e);
    void onClickCredits(const CEGUI::EventArgs &e);
    void onClickStopGame(const CEGUI::EventArgs &e);
    void setLayout(int e);
    
private:
//    CEGUI::DefaultWindow *label_prueba;
    CEGUI::DefaultWindow *label_titulo;
    CEGUI::PushButton *button_nueva;
    CEGUI::PushButton *button_cargar;
    CEGUI::PushButton *button_opciones;
    CEGUI::PushButton *button_creditos;
    CEGUI::PushButton *button_salir;
    
    CEGUI::DefaultWindow *label_cargar;
    CEGUI::PushButton *button_partida_01;
    CEGUI::PushButton *button_partida_02;
    CEGUI::PushButton *button_partida_03;
    
    CEGUI::PushButton *button_volver;
    int layout;
};

#endif /* menuPrueba_hpp */
