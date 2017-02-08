//
//  OpcionesLayout.cpp
//  arquitectura
//
//  Created by Nerea Castellanos Rodríguez on 8/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "OpcionesLayout.hpp"

OpcionesLayout::OpcionesLayout(){
     loadLayout("Opciones.layout");
}

OpcionesLayout::~OpcionesLayout(){
    
}

void OpcionesLayout::inicializar(){
    
    label_ajustes = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(7));
    
}
