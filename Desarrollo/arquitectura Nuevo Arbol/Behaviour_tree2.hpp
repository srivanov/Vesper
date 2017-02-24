//
//  Behaviour_tree2.hpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 23/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Behaviour_tree2_hpp
#define Behaviour_tree2_hpp

#include "Nodo_QAvisado.hpp"
#include "Nodo_QAyudar.hpp"
#include "Nodo_QEnemigo_QAlarma.hpp"
#include "Nodo_QAlarma_Cercano.hpp"
#include "Nodo_QRuido.hpp"
#include "Nodo_QVigilar.hpp"
#include "Nodo_QPedir_Ayuda.hpp"
#include "Nodo_QCombatir.hpp"
#include "Nodo_Qhuir.hpp"
#include "Nodo_QCurarse.hpp"
#include "Nodo_QHidratarse.hpp"
#include "Nodo_QAlimentarse.hpp"
#include "Nodo_QHablar.hpp"
#include "Nodo_QPatrullar.hpp"


#include "Nodo_RAvisado.hpp"
#include "Nodo_RAlarma_Cercana.hpp"
#include "Nodo_RRuido.hpp"


#include "Nodo_SecuenciaPlus.hpp"


#include "Nodo_AAyudar.hpp"
#include "Nodo_AVigilar.hpp"
#include "Nodo_AAlarma_Cercano.hpp"
#include "Nodo_AHuir.hpp"
#include "Nodo_ARuido.hpp"
#include "Nodo_ACurarse.hpp"
#include "Nodo_AHidratarse.hpp"
#include "Nodo_AAlimentarse.hpp"
#include "Nodo_AHablar.hpp"
#include "Nodo_APatrullar.hpp"


#include "Nodo_Mover.hpp"


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
    
    Nodo_base * SingleTree;
    static Behaviour_tree2 * constructor;
public:
    static Behaviour_tree2 * instancia();
    Nodo_base * getSingleTree();
    
    Nodo_base * ArbolPorDefecto();
    
    Nodo_base * ConstruirRama(const RamasArbol);
};


#endif /* Behaviour_tree2_hpp */
