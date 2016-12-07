//
//  estados.cpp
//  vesper
//
//  Created by Julia Martínez Valera on 1/12/16.
//  Copyright © 2016 Skyscrapers. All rights reserved.
//

#define ESTANDAR 0
#define ALERTA 1
#define COMBATE 2
#define ASUSTADO 3

#define ACCIONES_GENERALES_ESTANDAR 3
#define BUSCAR_RUIDO_ESTANDAR 2
#define INGERIR_ESTANDAR 2

#include "estados.hpp"


// QUE MOVER HABRA PUERTAS

estados::estados(){
    
    estado_act = ESTANDAR;
    
    //GENERALES
    NodoVigilar * vigilar = new NodoVigilar;
    NodoPatrullar * patrullar = new NodoPatrullar;
    
    Nodo_PuertaAbierta * _hay_puerta = new Nodo_PuertaAbierta;
    NodoMover * moverse = new NodoMover;
    
    //CONSTRUCCION ARBOL ESTANDAR
    _estandar = new NodoSecuenciaPositiva;
    
    //CAMBIAR ESTADO AGRESIVO
    Nodo_VerJugador * agresivo = new Nodo_VerJugador;
    _estandar->anyadirHijo(agresivo);
    
    //CAMBIAR ESTADO ALERTA
    Nodo_SuenaAlarma * alerta = new Nodo_SuenaAlarma;
    _estandar->anyadirHijo(alerta);
    
    //BUSCAR RUIDO
    NodoSecuenciaPositiva * _buscar_ruido = new NodoSecuenciaPositiva;
    
    
    for (int i=0; i<BUSCAR_RUIDO_ESTANDAR; i++) {
        
        if (i==0) {// CUANDO HAY PUERTA
            NodoSecuencia * sin_puerta = new NodoSecuencia;
            sin_puerta->anyadirHijo(_hay_puerta);
            sin_puerta->anyadirHijo(moverse);
            _buscar_ruido->anyadirHijo(sin_puerta);
        }
        else if(i==1){// SIN PUERTA
            NodoSecuencia * con_puerta = new NodoSecuencia;
            con_puerta->anyadirHijo(moverse);
            NodoAbrirPuerta * abrir_puerta = new NodoAbrirPuerta;
            con_puerta->anyadirHijo(abrir_puerta);
            con_puerta->anyadirHijo(moverse);
            _buscar_ruido->anyadirHijo(con_puerta);
        }
        else{cout << "ERROR - BUSCAR RUIDO ESTANDAR SIN DEFINIR" << endl;}
        
    }
    
    _estandar->anyadirHijo(_buscar_ruido);
    
    // IR A BOTIQUIN - ESTANDAR
    NodoSecuencia * _ir_botiquin = new NodoSecuencia;
    Nodo_VidaBaja * vida_baja = new Nodo_VidaBaja;
    Nodo_HayBotiquin * hay_botiquin = new Nodo_HayBotiquin;
    NodoCurarse * curarse = new NodoCurarse;
    
    _ir_botiquin->anyadirHijo(vida_baja);
    _ir_botiquin->anyadirHijo(hay_botiquin);
    _ir_botiquin->anyadirHijo(moverse);
    _ir_botiquin->anyadirHijo(curarse);
    
    _estandar->anyadirHijo(_ir_botiquin);
    
    // INGERIR
    
    NodoSecuenciaPositiva * _ingerir = new NodoSecuenciaPositiva;
    
    for (int i=0; i<INGERIR_ESTANDAR; i++) {
        if(i==0){//COMER
                NodoSecuencia * comer = new NodoSecuencia;
                Nodo_TengoHambre * tengo_hambre = new Nodo_TengoHambre;
                comer->anyadirHijo(tengo_hambre);
                comer->anyadirHijo(moverse);
                NodoComer * comiendo = new NodoComer;
                comer->anyadirHijo(comiendo);
                _ingerir->anyadirHijo(comer);
        }else if(i==1){//BEBER
                NodoSecuencia * beber = new NodoSecuencia;
                Nodo_TengoSed * tengo_sed = new Nodo_TengoSed;
                beber->anyadirHijo(tengo_sed);
                beber->anyadirHijo(moverse);
                NodoBeber * bebiendo = new NodoBeber;
                beber->anyadirHijo(bebiendo);
                _ingerir->anyadirHijo(beber);
        }
        else{cout << "ERROR - FALTA RUTINA DE INGERIR - ESTANDAR" << endl;}
    }
    
    // ACCIONES - ESTANDAR
    NodoSecuenciaPositiva * _acciones = new NodoSecuenciaPositiva;
    
    for (int i=0; i<ACCIONES_GENERALES_ESTANDAR; i++) {
        if(i==0) {// HABLAR
                NodoSecuencia * _hablar = new NodoSecuencia;
                Nodo_HayParaHablar * _se_puede = new Nodo_HayParaHablar;
                NodoHablar * hablamos = new NodoHablar;
                _hablar->anyadirHijo(_se_puede);
                _hablar->anyadirHijo(hablamos);
                _acciones->anyadirHijo(_hablar);
        }else if(i==1){// VIGILAR
                _acciones->anyadirHijo(vigilar);
        }else if(i==2){// PATRULLAR
                _acciones->anyadirHijo(patrullar);
        }else{cout << "ERROR - ACCION ESTANDAR SIN DEFINIR" << endl;break;}
    }

    // CONSTRUCCION DE ARBOL ALERTA
    _alerta = new NodoSecuenciaPositiva;
    
    //CAMBIAR ESTADO A COMBATE
    _alerta->anyadirHijo(agresivo);
    
    //BUSCAR RUIDO
    _alerta->anyadirHijo(_buscar_ruido);
    
    //CAMBIAR ESTADO ESTANDAR
    Nodo_TiempoInactivo * estandar = new Nodo_TiempoInactivo;
    _alerta->anyadirHijo(estandar);
    
    //ALARMA ACTIVA
    Nodo_AlarmaCerca * alarm_cerca = new Nodo_AlarmaCerca;
    NodoRecorreZonaCercana * recorrer_zona = new NodoRecorreZonaCercana; // NODO SIN DEFINIR
    NodoSecuenciaPositiva * _alarma_activa = new NodoSecuenciaPositiva;
    _alarma_activa->anyadirHijo(alarm_cerca);
    _alarma_activa->anyadirHijo(moverse);
    _alarma_activa->anyadirHijo(recorrer_zona);
    _alerta->anyadirHijo(_alarma_activa);
    
    // VIGILAR
    _alerta->anyadirHijo(vigilar);
    
    //PATRULLAR
    _alerta->anyadirHijo(patrullar);
    
    //CONSTRUYE EL ARBOL DE COMBATE
    _combate = new NodoSecuenciaPositiva;
    //CAMBIAR ESTADO A ASUSTADO
    Nodo_EstasAsustado * estar_asustado = new Nodo_EstasAsustado;
    _combate->anyadirHijo(estar_asustado);
    
    //PEDIR AYUDA
    Nodo_HayAlguienCerca * alguien_cerca = new Nodo_HayAlguienCerca;
    Nodo_HayAlguienRadio * alguien_radio = new Nodo_HayAlguienRadio;
    NodoSecuencia * ayuda_cercana = new NodoSecuencia;
    NodoSecuencia * ayuda_radio = new NodoSecuencia;
    NodoSecuencia * ayuda_alarma = new NodoSecuencia;
    Nodo_AlarmaCerca * alarma_cerca = new Nodo_AlarmaCerca;
    ayuda_alarma->anyadirHijo(alarma_cerca);
    ayuda_alarma->anyadirHijo(moverse);
    ayuda_cercana->anyadirHijo(alguien_cerca);
    ayuda_radio->anyadirHijo(alguien_radio);
    NodoAvisar * avisar = new NodoAvisar;
    NodoSecuencia * _pedir_ayuda = new NodoSecuencia;
    ayuda_alarma->anyadirHijo(avisar);
    ayuda_cercana->anyadirHijo(moverse);
    ayuda_cercana->anyadirHijo(avisar);
    ayuda_radio->anyadirHijo(avisar);
    _pedir_ayuda->anyadirHijo(ayuda_cercana);
    _pedir_ayuda->anyadirHijo(ayuda_radio);
    _combate->anyadirHijo(_pedir_ayuda);
    
    //COMBATIR
    NodoSecuenciaPositiva * _combatir = new NodoSecuenciaPositiva;
    NodoSecuencia * _cubrir = new NodoSecuencia;
    NodoSecuenciaPositiva * _ataques = new NodoSecuenciaPositiva;
    NodoSecuencia * _distancia_jugador = new NodoSecuencia; //comprueba a la distancia que estas del jugador para elegir el tipo de ataque
    NodoSecuencia * _cuerpo_cuerpo = new NodoSecuencia;
    NodoSecuencia * _a_distancia = new NodoSecuencia;
    
    Nodo_EstasCercaJugador * cerca_jug = new Nodo_EstasCercaJugador;
    Nodo_EstasLejosJugador * lejos_jug = new Nodo_EstasLejosJugador;
    NodoAtaqueCuerpo * ataque_cuerpo = new NodoAtaqueCuerpo;
    NodoAtaqueDistancia * ataque_distancia = new NodoAtaqueDistancia;
    NodoCubrirse * cubrirse = new NodoCubrirse; //NODO SIN DEFINIR
    
    _cubrir->anyadirHijo(cubrirse);
    _combatir->anyadirHijo(_cubrir);
    _combatir->anyadirHijo(_ataques);
    _ataques->anyadirHijo(_distancia_jugador);
    _distancia_jugador->anyadirHijo(lejos_jug);
    _distancia_jugador->anyadirHijo(moverse);
    _ataques->anyadirHijo(_cuerpo_cuerpo);
    _cuerpo_cuerpo->anyadirHijo(cerca_jug);
    _cuerpo_cuerpo->anyadirHijo(moverse);
    _cuerpo_cuerpo->anyadirHijo(ataque_cuerpo);
    _ataques->anyadirHijo(_a_distancia);
    _a_distancia->anyadirHijo(ataque_distancia);
    _combate->anyadirHijo(_combatir);
    
    //CAMBIAR ESTADO A ALERTA
    _combate->anyadirHijo(vigilar);
    
    //CONSTRUCCION DEL ARBOL ASUSTADO
    _asustado = new NodoSecuenciaPositiva;
    
    //CAMBIAR ESTADO ESTANDAR
    _asustado->anyadirHijo(estandar);
    
    //PEDIR AYUDA
    _asustado->anyadirHijo(_pedir_ayuda);

    //CAMBIAR ESTADO ALERTA
    _asustado->anyadirHijo(alerta);
    
    //HUIR
    NodoHuir * huir = new NodoHuir;
    _asustado->anyadirHijo(huir);
    
}

estados::~estados(){
    
}

void estados::run(datos NPCinfo){
    NPC = &NPCinfo;
    switch (estado_act) {
        case ESTANDAR:estandar();break;
        case ALERTA:alerta();break;
        case COMBATE:combate();break;
        case ASUSTADO:asustado();break;
        default:cout << "NO EXISTE ESTADO" << endl;break;
    }
}

void estados::estandar(){
    _estandar->run(*NPC);
}

void estados::alerta(){
    _alerta->run(*NPC);
}

void estados::combate(){
    _combate->run(*NPC);
}

void estados::asustado(){
    _asustado->run(*NPC);
}

