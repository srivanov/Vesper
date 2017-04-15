//
//  CargarPartidaLayout.hpp
//  arquitectura
//
//  Created by Catherine Castrillo González on 08/02/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef CargarPartidaLayout_hpp
#define CargarPartidaLayout_hpp

#include <stdio.h>
#include "GUI.h"

class CargarPartidaLayout : public GUI {
public:
    CargarPartidaLayout();
    ~CargarPartidaLayout();
//    void update() override;
    void init(CEGUI::RenderTarget* target);
    void onClickPartida1(const CEGUI::EventArgs &e);
    void onClickPartida2(const CEGUI::EventArgs &e);
    void onClickPartida3(const CEGUI::EventArgs &e);
    void onClickVolver(const CEGUI::EventArgs &e);
    
private:
    CEGUI::DefaultWindow *label_cargar;
    CEGUI::PushButton *button_partida1;
    CEGUI::PushButton *button_partida2;
    CEGUI::PushButton *button_partida3;
    CEGUI::PushButton *button_volver;
};

#endif /* CargarPartidaLayout_hpp */
