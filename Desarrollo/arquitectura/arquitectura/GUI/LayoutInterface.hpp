//
//  LayoutInterface.hpp
//  arquitectura
//
//  Created by Catherine Castrillo González on 08/02/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef LayoutInterface_hpp
#define LayoutInterface_hpp

#include <stdio.h>
#include "GUI.h"
#include "../MyEventReceiver.hpp"

//enum Layout {
//    tMenuPrincipalLayout = 0,
//    tCargarPartidaLayout,
//    tOpcionesLayout,
//    tCreditosLayout
//};

class LayoutInterface {
public:
    virtual void update() = 0;
    virtual int getLayout2() = 0;
    
protected:
    tLayout layout;
};

#endif /* LayoutInterface_hpp */
