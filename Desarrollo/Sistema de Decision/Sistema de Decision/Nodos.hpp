//
//  Nodos.hpp
//  Sistema de Decision
//
//  Created by Gaspar Rodriguez Valero on 29/11/16.
//  Copyright © 2016 Gaspar Rodriguez Valero. All rights reserved.
//
/* */
#ifndef Nodos_hpp
#define Nodos_hpp

#include <vector>
#include <iostream>
#include "datos.hpp"
#include "BlackBoard.hpp"
using namespace std;

/*###################
    CLASES GENERALES
 ###################*/
class Nodo {
public:
    virtual short run(datos NPCinfo) = 0;
    bool getRunning(){return running;}
protected:
    bool running = false;
};

class NodoSecuencia : public Nodo {
public:
    NodoSecuencia();
    short run(datos NPCinfo);
    void anyadirHijo(Nodo * hijo);
private:
    vector<Nodo*> m_hijos;
};
class NodoSecuenciaPositiva : public Nodo{
public:
    NodoSecuenciaPositiva();
    short run(datos NPCinfo);
    void anyadirHijo(Nodo * hijo);
private:
    vector<Nodo*> m_hijos;
};
class NodoMover : public Nodo {
public:
    NodoMover();
    short run(datos NPCinfo);
private:
    //Posicion Inicial X e Y;
    //Posicion Final X e Y;
};
class Nodo_PuertaAbierta : public Nodo {
public:
    Nodo_PuertaAbierta();
    short run(datos NPCinfo);
private:
    // Estado de la puerta
    // Tipo de puerta
};
class NodoAbrirPuerta : public Nodo {
public:
    NodoAbrirPuerta();
    short run(datos NPCinfo);
private:
    // Estado de la puerta
    // Tipo de puerta
    // Si tiene llave
};
class Nodo_VerJugador : public Nodo {
public:
    Nodo_VerJugador();
    short run(datos NPCinfo);
private:
    // Sensor
};
class Nodo_SuenaAlarma : public Nodo {
public:
    Nodo_SuenaAlarma();
    short run(datos NPCinfo);
private:
    // Alarma Activa
};
class NodoHayRuido : public Nodo {
public:
    NodoHayRuido();
    short run(datos NPCinfo);
private:
    // Ruido de objeto
};

class NodoVigilar : public Nodo {
public:
    NodoVigilar();
    short run(datos NPCinfo);
private:
    // Iniciar Tiempo
};
class NodoPatrullar : public Nodo {
public:
    NodoPatrullar();
    short run(datos NPCinfo);
private:
    // Patrulla
};
class Nodo_TiempoInactivo : public Nodo {
public:
    Nodo_TiempoInactivo();
    short run(datos NPCinfo);
private:
    // Tiempo
};

class NodoDarAlarma : public Nodo {
public:
    NodoDarAlarma();
    short run(datos NPCinfo);
private:
    // Estado de la Alarma (CAMBIA ESTADO)
};

/*###################
 CLASES ESTANDAR
 ###################*/

class Nodo_VidaBaja : public Nodo {
public:
    Nodo_VidaBaja();
    short run(datos NPCinfo);
private:
    // VIDA DEL NPC
};

class Nodo_HayBotiquin : public Nodo {
public:
    Nodo_HayBotiquin();
    short run(datos NPCinfo);
private:
    // BOTIQUINES (BLACKBOARD)
};

class NodoCurarse : public Nodo {
public:
    NodoCurarse();
    short run(datos NPCinfo);
private:
    // VIDA
    // CUANTO CURA
};
class Nodo_TengoHambre : public Nodo {
public:
    Nodo_TengoHambre();
    short run(datos NPCinfo);
private:
    // HAMBRE
};
class Nodo_TengoSed : public Nodo {
public:
    Nodo_TengoSed();
    short run(datos NPCinfo);
private:
    // SED
};
class NodoComer : public Nodo {
public:
    NodoComer();
    short run(datos NPCinfo);
private:
    // HAMBRE
};
class NodoBeber : public Nodo {
public:
    NodoBeber();
    short run(datos NPCinfo);
private:
    // SED
};
class Nodo_TieneAgua : public Nodo {
public:
    Nodo_TieneAgua();
    short run(datos NPCinfo);
private:
    // ESTADO FUENTE
};
class Nodo_HayParaHablar : public Nodo {
public:
    Nodo_HayParaHablar();
    short run(datos NPCinfo);
private:
    // NPC + CERCANO
    
};
class NodoHablar : public Nodo {
public:
    NodoHablar();
    short run(datos NPCinfo);
private:
    //  TEMAS RAMDOM
};
/*###################
 CLASES ALERTA
 ###################*/

class Nodo_AlarmaCerca : public Nodo {
public:
    Nodo_AlarmaCerca();
    short run(datos NPCinfo);
private:
    // POSICION ALARMA + CERCANA
};

class NodoRecorreZonaCercana : public Nodo {
public:
    NodoRecorreZonaCercana();
    short run(datos NPCinfo);
private:
    //
};

/*###################
 CLASES COMBATE
 ###################*/
class Nodo_EstasAsustado : public Nodo {
public:
    Nodo_EstasAsustado();
    short run(datos NPCinfo);
private:
    // VIDA , HAMBRE Y SED
};
class Nodo_HayAlguienCerca : public Nodo {
public:
    Nodo_HayAlguienCerca();
    short run(datos NPCinfo);
private:
    // COORDENADAS NPC + CERCANO
};
class Nodo_HayAlguienRadio : public Nodo {
public:
    Nodo_HayAlguienRadio();
    short run(datos NPCinfo);
private:
    // COORDENADAS DE NPC DENTRO DE RANGO DE RADIO ,
    // CUANTOS AVISA: COMBATE SOLO 1 , ASUSTADO 3 NPCS
};

class NodoAvisar : public Nodo {
public:
    NodoAvisar();
    short run(datos NPCinfo);
private:
    // COORDENADAS PROPIAS
};
class Nodo_EstasCercaJugador : public Nodo {
public:
    Nodo_EstasCercaJugador();
    short run(datos NPCinfo);
private:
    // COORDENADAS DEL JUGADOR
};
class Nodo_EstasLejosJugador : public Nodo {
public:
    Nodo_EstasLejosJugador();
    short run(datos NPCinfo);
private:
    // COORDENADAS DEL JUGADOR
};
class NodoAtaqueCuerpo : public Nodo {
public:
    NodoAtaqueCuerpo();
    short run(datos NPCinfo);
private:
};
class NodoAtaqueDistancia : public Nodo {
public:
    NodoAtaqueDistancia();
    short run(datos NPCinfo);
private:
};
class NodoCubrirse : public Nodo {
public:
    NodoCubrirse();
    short run(datos NPCinfo);
private:
    // OBJETOS DONDE CUBRISE, EL + CERCANO
};

/*###################
 CLASES ASUTADO
 ###################*/

class NodoHuir : public Nodo {
public:
    NodoHuir();
    short run(datos NPCinfo);
private:
    // COORDENADAS DEL JUGADOR
};


#endif /* Nodos_hpp */
