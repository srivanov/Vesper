//
//  depuracionIA.hpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 9/3/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef depuracionIA_hpp
#define depuracionIA_hpp

#include <stdio.h>
#include "GUI.h"
#include "../MyEventReceiver.hpp"

class depuracionIA : public Motor::GUI{
public:
    depuracionIA();
    ~depuracionIA();
    tLayout getLayout() override;
    
private:
    CEGUI::ProgressBar* barra_salud;
    
};
#endif /* depuracionIA_hpp */

