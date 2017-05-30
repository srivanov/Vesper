//
//  Nodo_AVigilar.cpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 22/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Nodo_AVigilar.hpp"

short Nodo_AVigilar::run(const int &ID){
    if(!init){
        t.start();
        init = true;
    }
    if (t.tTranscurrido(6.f)) {
        init = false;
        t.reset();
        return FUNCIONO;
    }
    return RUNNING;
}
