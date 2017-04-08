//
//  Behaviour_tree2.cpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 23/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Behaviour_tree2.hpp"

Behaviour_tree2 * Behaviour_tree2::constructor = 0;

Behaviour_tree2 * Behaviour_tree2::instancia(){
    if(constructor==0) constructor = new Behaviour_tree2;
    return constructor;
}

Nodo_base * Behaviour_tree2::ConstruirRamaAccion(){
    Nodo_QEnemigo_QAlarma * NodoSuperior = new Nodo_QEnemigo_QAlarma;
    
    Nodo_SecuenciaPlus * NodoSelector = new Nodo_SecuenciaPlus;
    
    Nodo_base * Accion1 = ConstruirSubRamaHuir();
    Nodo_base * Accion2 = ConstruirSubRamaPedirAyuda();
    Nodo_base * Accion3 = ConstruirSubRamaCombate();
    
    NodoSuperior->addHijo(NodoSelector);
    
    //TO DO : CREAR FUNCIONES DESTINADAS A CADA SUBRAMA
    NodoSelector->addHijo(Accion1);
    NodoSelector->addHijo(Accion2);
    NodoSelector->addHijo(Accion3);
    
    return NodoSuperior;
}

Nodo_base * Behaviour_tree2::ConstruirSubRamaCombate(){
    Nodo_QCombatir * NodoSuperior = new Nodo_QCombatir;
    
    Nodo_AAtacar * Accion1 = new Nodo_AAtacar;
    //Nodo_Mover * Accion1 = new Nodo_Mover;

    
    NodoSuperior->addHijo(Accion1);
    
    return NodoSuperior;
}

Nodo_base * Behaviour_tree2::ConstruirSubRamaPedirAyuda(){
    Nodo_QPedir_Ayuda * NodoSuperior = new Nodo_QPedir_Ayuda;
    
    Nodo_APedir_Ayuda * Accion1 = new Nodo_APedir_Ayuda;
    Nodo_APedir_Ayuda2 * Accion2 = new Nodo_APedir_Ayuda2;
    
    NodoSuperior->addHijo(Accion1);
    NodoSuperior->addHijo(Accion2);
    
    return NodoSuperior;
    
}

Nodo_base * Behaviour_tree2::ConstruirSubRamaHuir(){
    Nodo_Qhuir * NodoSuperior = new Nodo_Qhuir;
    
    Nodo_AHuir * Accion1 = new Nodo_AHuir;
    
    NodoSuperior->addHijo(Accion1);
    
    return NodoSuperior;
}

Nodo_base * Behaviour_tree2::ConstruirRamaAyudar(){
    Nodo_QAyudar * NodoSuperior = new Nodo_QAyudar;
    
    Nodo_Mover * Accion1 = new Nodo_Mover;
    Nodo_AAyudar * Accion2 = new Nodo_AAyudar;
    Nodo_RAvisado * Accion3 = new Nodo_RAvisado;
    
    NodoSuperior->addHijo(Accion1);
    NodoSuperior->addHijo(Accion2);
    NodoSuperior->addHijo(Accion3);
    
    return NodoSuperior;
}

Nodo_base * Behaviour_tree2::ConstruirRama(const RamasArbol){
    
    
    return nullptr;
}

Nodo_base * Behaviour_tree2::ArbolPorDefecto(){
    Nodo_SecuenciaPlus * NodoSuperior = new Nodo_SecuenciaPlus;
    
    Nodo_base * RamaAccion = ConstruirRamaAccion();
    Nodo_base * RamaAyudar = ConstruirRamaAyudar();
    Nodo_base * RamaAlarma_Cercana = ConstruirRamaAlarmaCercana();
    Nodo_base * RamaRuido = ConstruirRamaRuido();
    Nodo_base * RamaMantenimiento = ConstruirRamaMantenimiento();
    Nodo_base * RamaPorDefecto = ConstruirRamaPorDefecto();
    
    NodoSuperior->addHijo(RamaAccion);
    NodoSuperior->addHijo(RamaAyudar);
    NodoSuperior->addHijo(RamaAlarma_Cercana);
    NodoSuperior->addHijo(RamaRuido);
    NodoSuperior->addHijo(RamaMantenimiento);
    NodoSuperior->addHijo(RamaPorDefecto);
    
    return NodoSuperior;
}

Nodo_base * Behaviour_tree2::ConstruirRamaAlarmaCercana(){
    Nodo_QAlarma_Cercano * NodoSuperior = new Nodo_QAlarma_Cercano;
    
    Nodo_Mover * Accion1 = new Nodo_Mover;
    Nodo_AAlarma_Cercano * Accion2 = new Nodo_AAlarma_Cercano;
    Nodo_RAlarma_Cercana * Accion3 = new Nodo_RAlarma_Cercana;
    
    NodoSuperior->addHijo(Accion1);
    NodoSuperior->addHijo(Accion2);
    NodoSuperior->addHijo(Accion3);
    
    return NodoSuperior;
    
}

Nodo_base * Behaviour_tree2::ConstruirRamaMantenimiento(){
    Nodo_SecuenciaPlus * NodoSuperior = new Nodo_SecuenciaPlus;
    
    Nodo_base * Accion1 = ConstruirSubRamaCuracion();
    Nodo_base * Accion2 = ConstruirSubRamaAlimentacion();
    Nodo_base * Accion3 = ConstruirSubRamaHidratacion();
    
    NodoSuperior->addHijo(Accion1);
    NodoSuperior->addHijo(Accion2);
    NodoSuperior->addHijo(Accion3);
    
    return NodoSuperior;
    
}

Nodo_base * Behaviour_tree2::ConstruirRamaRuido(){
    Nodo_QRuido * NodoSuperior = new Nodo_QRuido;
    
    Nodo_Mover * Accion1 = new Nodo_Mover;
    Nodo_ARudio * Accion2 = new Nodo_ARudio;
    Nodo_RRuido * Accion3 = new Nodo_RRuido;
    
    NodoSuperior->addHijo(Accion1);
    NodoSuperior->addHijo(Accion2);
    NodoSuperior->addHijo(Accion3);
    
    return NodoSuperior;
}

Nodo_base * Behaviour_tree2::ConstruirSubRamaCuracion(){
    Nodo_QCurarse * NodoSuperior = new Nodo_QCurarse;
    
    Nodo_Mover * Accion1 = new Nodo_Mover;
    Nodo_ACurarse * Accion2 = new Nodo_ACurarse;
    
    NodoSuperior->addHijo(Accion1);
    NodoSuperior->addHijo(Accion2);
    
    return NodoSuperior;
}

Nodo_base * Behaviour_tree2::ConstruirSubRamaAlimentacion(){
    Nodo_QAlimentarse * NodoSuperior = new Nodo_QAlimentarse;
    
    Nodo_Mover * Accion1 = new Nodo_Mover;
    Nodo_AAlimentarse * Accion2 = new Nodo_AAlimentarse;
    
    NodoSuperior->addHijo(Accion1);
    NodoSuperior->addHijo(Accion2);
    
    return NodoSuperior;
}

Nodo_base * Behaviour_tree2::ConstruirSubRamaHidratacion(){
    Nodo_QHidratarse * NodoSuperior = new Nodo_QHidratarse;
    
    Nodo_Mover * Accion1 = new Nodo_Mover;
    Nodo_AHidratarse * Accion2 = new Nodo_AHidratarse;
    
    NodoSuperior->addHijo(Accion1);
    NodoSuperior->addHijo(Accion2);
    
    return NodoSuperior;
}

Nodo_base * Behaviour_tree2::ConstruirRamaPorDefecto(){
    Nodo_SecuenciaPlus * NodoSuperior = new Nodo_SecuenciaPlus;
    
    Nodo_base * Accion1 = ConstruirSubRamaHablar();
    Nodo_base * Accion2 = ConstruirSubRamaVigilar();
    Nodo_base * Accion3 = ConstruirSubRamaPatrullar();
    
    NodoSuperior->addHijo(Accion1);
    NodoSuperior->addHijo(Accion2);
    NodoSuperior->addHijo(Accion3);
    
    return NodoSuperior;
    
}

Nodo_base * Behaviour_tree2::ConstruirSubRamaHablar(){
    Nodo_QHablar * NodoSuperior = new Nodo_QHablar;
    
    Nodo_AHablar * Accion1 = new Nodo_AHablar;
    
    NodoSuperior->addHijo(Accion1);
    
    return NodoSuperior;
}


Nodo_base * Behaviour_tree2::ConstruirSubRamaVigilar(){
    Nodo_QVigilar * NodoSuperior = new Nodo_QVigilar;
    
    Nodo_Mover * Accion1 = new Nodo_Mover;
    Nodo_AVigilar * Accion2 = new Nodo_AVigilar;
    
    NodoSuperior->addHijo(Accion1);
    NodoSuperior->addHijo(Accion2);
    
    return NodoSuperior;
}

Nodo_base * Behaviour_tree2::ConstruirSubRamaPatrullar(){
    Nodo_QPatrullar * NodoSuperior = new Nodo_QPatrullar;
    
    Nodo_Mover * Accion1 = new Nodo_Mover;
    Nodo_APatrullar * Accion2 = new Nodo_APatrullar;
    
    NodoSuperior->addHijo(Accion1);
    NodoSuperior->addHijo(Accion2);
    
    return NodoSuperior;
}

Behaviour_tree2::~Behaviour_tree2(){}

