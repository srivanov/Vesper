//
//  CreditosLayout.hpp
//  arquitectura
//
//  Created by Nerea Castellanos Rodríguez on 9/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef CreditosLayout_hpp
#define CreditosLayout_hpp

#include <stdio.h>
#include "GUI.h"
#include "../MyEventReceiver.hpp"

class CreditosLayout : public GUI {
public:
    CreditosLayout();
    ~CreditosLayout();
    //    void update() override;
    void init(CEGUI::RenderTarget* target);
    void onClickVolver(const CEGUI::EventArgs &e);
    
private:
    CEGUI::DefaultWindow *label_creditos;
    CEGUI::PushButton *button_volver;
};

#endif /* CreditosLayout_hpp */
