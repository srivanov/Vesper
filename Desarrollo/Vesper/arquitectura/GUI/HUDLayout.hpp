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

class HUDLayout : public Motor::GUI {
public:
    HUDLayout();
    ~HUDLayout();
    //    void update() override;
    tLayout getLayout() override;
    void onClickVolver(const CEGUI::EventArgs &e);
    
private:
   CEGUI::PushButton *button_volver;
};

#endif /* HUDLayout_hpp */
