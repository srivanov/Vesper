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

class menuPrueba : public Motor::GUI {
public:
    menuPrueba(){}
    ~menuPrueba(){}
    void inicializar();
    void update();
    void onClickStartGame(const CEGUI::EventArgs &e);
    
private:
//    CEGUI::DefaultWindow *label_prueba;
    CEGUI::DefaultWindow *label_titulo;
    CEGUI::PushButton *button_nueva;
    CEGUI::PushButton *button_cargar;
    CEGUI::PushButton *button_opciones;
    CEGUI::PushButton *button_creditos;
    CEGUI::PushButton *button_salir;
};

#endif /* menuPrueba_hpp */
