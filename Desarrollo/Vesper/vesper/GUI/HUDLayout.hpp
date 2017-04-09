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
#include "../components/typeArma.hpp"

class HUDLayout : public GUI {
public:
    HUDLayout();
    ~HUDLayout();
    //    void update() override;
    void init();
    void getVida(int v);
    void getMonedas(int v);
    void ocultarArmas();
    void mostrarArma(typeArma tipo);
    
private:
    CEGUI::DefaultWindow *moneda0;
   	CEGUI::DefaultWindow *moneda1;
    CEGUI::DefaultWindow *moneda2;
    CEGUI::DefaultWindow *moneda3;
    CEGUI::ProgressBar *vida;
    CEGUI::DefaultWindow* actual;
    
    std::map<typeArma,CEGUI::DefaultWindow*> armas;
    
};

#endif /* HUDLayout_hpp */
