//
//  HUDLayout.hpp
//  arquitectura
//
//  Created by Nerea Castellanos Rodríguez on 9/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef HUDLayout_hpp
#define HUDLayout_hpp

#include <stdio.h>
#include "GUI.h"
#include "../MyEventReceiver.hpp"

class HUDLayout : public GUI {
public:
    HUDLayout();
    ~HUDLayout();
    //    void update() override;
    void init();
    void getVida(int v);
    void getMonedas(int v);
    
private:
    CEGUI::DefaultWindow *moneda0;
   	CEGUI::DefaultWindow *moneda1;
    CEGUI::DefaultWindow *moneda2;
    CEGUI::DefaultWindow *moneda3;
    CEGUI::DefaultWindow *vida1;
    CEGUI::DefaultWindow *vida2;
    CEGUI::DefaultWindow *vida3;
    CEGUI::DefaultWindow *vida4;
    CEGUI::DefaultWindow *vida5;
    CEGUI::DefaultWindow *pistola1;
    CEGUI::DefaultWindow *pistola2;
    CEGUI::DefaultWindow *pistola3;
};

#endif /* HUDLayout_hpp */
