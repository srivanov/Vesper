//
//  Behaviour_tree2.hpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 23/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Behaviour_tree2_hpp
#define Behaviour_tree2_hpp

#include "Nodos de Pregunta/Nodo_QAvisado.hpp"
#include "Nodos de Pregunta/Nodo_QAyudar.hpp"
#include "Nodos de Pregunta/Nodo_QEnemigo_QAlarma.hpp"
#include "Nodos de Pregunta/Nodo_QAlarma_Cercano.hpp"
#include "Nodos de Pregunta/Nodo_QRuido.hpp"
#include "Nodos de Pregunta/Nodo_QVigilar.hpp"
#include "Nodos de Pregunta/Nodo_QPedir_Ayuda.hpp"
#include "Nodos de Pregunta/Nodo_QCombatir.hpp"
#include "Nodos de Pregunta/Nodo_Qhuir.hpp"
#include "Nodos de Pregunta/Nodo_QCurarse.hpp"
#include "Nodos de Pregunta/Nodo_QHidratarse.hpp"
#include "Nodos de Pregunta/Nodo_QAlimentarse.hpp"
#include "Nodos de Pregunta/Nodo_QHablar.hpp"
#include "Nodos de Pregunta/Nodo_QPatrullar.hpp"


#include "Nodos de Reset/Nodo_RAvisado.hpp"
#include "Nodos de Reset/Nodo_RAlarma_Cercana.hpp"
#include "Nodos de Reset/Nodo_RRuido.hpp"


#include "Nodo de Secuencia/Nodo_SecuenciaPlus.hpp"


#include "Nodos de Accion/Nodo_AAyudar.hpp"
#include "Nodos de Accion/Nodo_AVigilar.hpp"
#include "Nodos de Accion/Nodo_AAlarma_Cercano.hpp"
#include "Nodos de Accion/Nodo_AHuir.hpp"
#include "Nodos de Accion/Nodo_ARuido.hpp"
#include "Nodos de Accion/Nodo_ACurarse.hpp"
#include "Nodos de Accion/Nodo_AHidratarse.hpp"
#include "Nodos de Accion/Nodo_AAlimentarse.hpp"
#include "Nodos de Accion/Nodo_AHablar.hpp"
#include "Nodos de Accion/Nodo_APatrullar.hpp"


#include "Nodos de Accion/Nodo_Mover.hpp"


enum RamasArbol{
    R_ACCION = 0,
    R_AYUDAR,
    R_ALARMA_CERCANA,
    R_RUIDO,
    R_MANTENIMIENTO,
    R_DEFECTO
};

//TO DO :
/*
 NODOS FINALES DE ACCION SIN PROGRAMAR
 
 AAyudar
 AAlarma_Cerca
 ARuido
 AHablar
 AVigilar
 APatrullar
 
 NODOS PERTENECIENTES A LAS SIGUIENTES RAMAS
 
 Pedir_Ayuda
 Combate
 */



class Behaviour_tree2 {
    
    Behaviour_tree2(){}
    ~Behaviour_tree2();
    
    Nodo_base * ConstruirRamaAccion();
    Nodo_base * ConstruirSubRamaHuir();
    
    Nodo_base * ConstruirRamaAyudar();
    
    Nodo_base * ConstruirRamaAlarmaCercana();
    
    Nodo_base * ConstruirRamaRuido();
    
    Nodo_base * ConstruirRamaMantenimiento();
    Nodo_base * ConstruirSubRamaCuracion();
    Nodo_base * ConstruirSubRamaHidratacion();
    Nodo_base * ConstruirSubRamaAlimentacion();
    
    Nodo_base * ConstruirRamaPorDefecto();
    Nodo_base * ConstruirSubRamaHablar();
    Nodo_base * ConstruirSubRamaVigilar();
    Nodo_base * ConstruirSubRamaPatrullar();
    
    
    static Behaviour_tree2 * constructor;
public:
    static Behaviour_tree2 * instancia();
    
    Nodo_base * ArbolPorDefecto();
    
    Nodo_base * ConstruirRama(const RamasArbol);
};


#endif /* Behaviour_tree2_hpp */
