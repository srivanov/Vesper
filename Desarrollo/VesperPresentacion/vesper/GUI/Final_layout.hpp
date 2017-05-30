//
//  Final_layout.hpp
//  vesper
//
//  Created by Nerea Castellanos Rodríguez on 23/5/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Final_layout_hpp
#define Final_layout_hpp

#include <stdio.h>
#include "GUI.h"

class Final_layout : public GUI {
public:
    Final_layout();
    ~Final_layout();
    void init(CEGUI::RenderTarget* target);
    
    void onClickContinuar(const CEGUI::EventArgs &e);
    void onClickReintentar(const CEGUI::EventArgs &e);
    void onClickSalir(const CEGUI::EventArgs &e);
    
private:
    CEGUI::PushButton *button_continuar;
    CEGUI::PushButton *button_salir;
    CEGUI::PushButton *button_salir2;
    CEGUI::PushButton *button_reintentar;
    
};

#endif /* Final_layout_hpp */
