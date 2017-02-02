//
//  menuPrueba.cpp
//  arquitectura
//
//  Created by Catherine Castrillo González on 01/02/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "menuPrueba.hpp"
#include "../components/ventana.hpp"

void menuPrueba::inicializar(){
    init("3d/GUI", ventana::Instance()->getDevice());
    
    loadScheme("AlfiskoSkin.scheme");
    loadLayout("prueba.layout");
    
    label_prueba = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(69));
    
    label_prueba->setText("HOLA CATHERINE");
}

void menuPrueba::update(){
    
}
