//
//  Vstate.cpp
//  Sistema de Decision
//
//  Created by Gaspar Rodriguez Valero on 8/11/16.
//  Copyright © 2016 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Vstate.hpp"
Vstate::Vstate(){
    Vstate::_life = 100;
    srand(time(NULL));
    Vstate::_hungry = rand()%21;
    Vstate::_thirst = rand()%21;
    Vstate::_npcs = 0; // CODIGO PARA CONOCER NPCS CERCANOS !!FALTA!!!
    switch (rand()%3) {
        case 0:_anger = true; _fear = false; break;
        case 1:_fear =true; _anger=false; break;
        default:_anger = _fear = false; break;
    }
    Vstate::_typeM = rand()%3;
}
Vstate::Vstate(bool miedo,bool cabreo, int tipo){
    Vstate::_life = 100;
    srand(time(NULL));
    Vstate::_hungry = rand()%21;
    Vstate::_thirst = rand()%21;
    Vstate::_npcs = 0; // CODIGO PARA CONOCER NPCS CERCANOS !!FALTA!!!
    Vstate::_anger = cabreo;
    Vstate::_fear = miedo;
    Vstate::_typeM = tipo;
}

int Vstate::calculate(){
    //CALCULARA MEDIANTE LA FORMULA PARA OBTENER SU VALOR ESTADO
    // FORMULA | ESTADO = life * 0.4 + npcs * 0.2 + miedo/cabreo * 0.1 + hambre * 0.125 + sed * 0.125 + tipo * 0.15;
    /*
     Variables	            Peso	Nº NPC		Valor	Tipos de monstruo	Valor	Miedo	       -100%
     Salud	                 40%	0		     25%	Lanzador de Fuego	 75%	Cabreo	        100%
     Nº de NPCs cercanos	 20%	1		     50%	Escupe Acido	     50%	Valor neutro	  0
     Miedo/Cabreo	         10%	2		     75%	Lanza Pinchos	     25%
     Hambre	                 13%	n>2		     100%	Luchador Físico	    100%
     Sed	                 13%
     Tipo	                 15%
     Total	110%
     */
    int estado;
    float component1,component2,component3,component4,component5,component6;
    component1 = Vstate::_life*0.4;
    switch (_npcs) {
        case 0:component2 = 25;break;
        case 1:component2 = 50;break;
        case 2:component2 = 75;break;
        default:component2 = 100;break;
    }component2 = component2*0.2;
    if (_anger) {component3 = 100;}
    else if(_fear){component3 = -100;}
    else{component3 = 0;}
    component3 = component3*0.1;
    component4 = (_hungry-100)*-1 * 0.125;
    component5 = (_thirst-100)*-1 * 0.125;
    switch (_typeM) {
        case 0:component6 = 75;break;
        case 1:component6 = 50;break;
        case 2:component6 = 25;break;
        default:component6 = 100;break;
    }
    component6 = component6*0.15;
    estado = (int)component1+component2+component3+component4+component5+component6;
    return estado;
}
void Vstate::updateVstate(){
    if(_hungry<100)++_hungry;
    if (_thirst<100)++_thirst;
    if (_hungry==100 && _thirst==100) _life-=2;
    else if ((_hungry==100 || _thirst==100) && _life<=0)--_life;
}
void Vstate::drink(){_thirst=0;}
void Vstate::eat(){_hungry=0;}
void Vstate::heal(){_life=100;}
