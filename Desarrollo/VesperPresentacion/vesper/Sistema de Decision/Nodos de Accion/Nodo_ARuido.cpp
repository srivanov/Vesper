//
//  Nodo_ARuido.cpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 23/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Nodo_ARuido.hpp"

short Nodo_ARudio::run(const int &ID){
    
    if(!init){
        init = true;
        t.start();
    }
    else if(t.tTranscurrido(2.0f) && init){
        init = false;
        t.reset();
        return FUNCIONO;
    }
    return RUNNING;
}
