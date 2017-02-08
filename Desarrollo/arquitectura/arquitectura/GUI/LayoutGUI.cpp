//
//  Layout.cpp
//  arquitectura
//
//  Created by Catherine Castrillo González on 08/02/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "LayoutGUI.hpp"

LayoutGUI::LayoutGUI(){
    
}

LayoutGUI::~LayoutGUI(){
    
}

void LayoutGUI::update(){
    seleccionada->getLayout();
}

void LayoutGUI::setActiveLayout(tLayout nuevo){
    activeLayout = nuevo;
    //TO DO: hacer aqui el cambio de un layout a otro segun el tipo en activeLayout aka borrar el layout actual y cargar el nuevo. Si los ocultamos, se haria en este metodo tambien.
    
    // Recorrer el vector ocultando todos los menos excepto el que tenga el tipo activeLayout.
    
    // Ocultar el vector en plan, solo el vector, no hace falta recorrer
    
    // O sea, ocultamos el actual y recorremos el vector para mostrar unicamente el nuevo/activo
}
