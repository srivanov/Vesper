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
#include <math.h>
#include "Dvector.hpp"

using namespace std;

/*###################
    CLASES GENERALES
 ###################*/
class Nodo {
public:
    virtual short run(int &id) = 0;
protected:
    //float CalcularDistancia(vector3D a, vector3D b);
};

class NodoSecuencia : public Nodo {
public:
    NodoSecuencia();
    short run(int &id);
    void anyadirHijo(Nodo * hijo);
private:
    vector<Nodo*> m_hijos;
    size_t hijo = -1;
};
class NodoSecuenciaPositiva : public Nodo{
public:
    NodoSecuenciaPositiva();
    short run(int &id);
    void anyadirHijo(Nodo * hijo);
private:
    vector<Nodo*> m_hijos;
    size_t hijo = -1;
};
class NodoMover : public Nodo {
public:
    NodoMover();
    short run(int &id);
private:
    int f = 0;
    float aux = -1;
    float xABS, yABS;
};

class Nodo_VerJugador : public Nodo {
public:
    Nodo_VerJugador();
    short run(int &id);
private:
    // Sensor
};
class Nodo_HayRuido : public Nodo {
public:
    Nodo_HayRuido();
    short run(int &id);
private:
    // Sensor
};
class Nodo_SuenaAlarma : public Nodo {
public:
    Nodo_SuenaAlarma();
    short run(int &id);
private:
    // Alarma Activa
};

class NodoVigilar : public Nodo {
public:
    NodoVigilar();
    short run(int &id);
private:
    // Iniciar Tiempo
};
class NodoPatrullar : public Nodo {
public:
    NodoPatrullar();
    short run(int &id);
private:
    //float aux = -1;
    //float xABS, yABS;
};
class Nodo_TiempoInactivo : public Nodo {
public:
    Nodo_TiempoInactivo();
    short run(int &id);
private:
    // Tiempo
};

class NodoDarAlarma : public Nodo {
public:
    NodoDarAlarma();
    short run(int &id);
private:
    // Estado de la Alarma (CAMBIA ESTADO)
};
class Nodo_Avisado : public Nodo {
public:
    Nodo_Avisado();
    short run(int &id);
private:
    // Estado de la Alarma (CAMBIA ESTADO)
};
/*###################
 CLASES ESTANDAR
 ###################*/

class Nodo_VidaBaja : public Nodo {
public:
    Nodo_VidaBaja();
    short run(int &id);
private:
    // VIDA DEL NPC
};

class Nodo_NecesitoAyuda : public Nodo {
public:
    Nodo_NecesitoAyuda();
    short run(int &id);
private:
    
};

class Nodo_HayBotiquin : public Nodo {
public:
    Nodo_HayBotiquin();
    short run(int &id);
private:
    //vector3D * MasCercano(vector<vector3D*>& objetos,datos * NPCinfo);
    // BOTIQUINES (BLACKBOARD)
};

class NodoCurarse : public Nodo {
public:
    NodoCurarse();
    short run(int &id);
private:
    // VIDA
    // CUANTO CURA
};
class Nodo_TengoHambre : public Nodo {
public:
    Nodo_TengoHambre();
    short run(int &id);
private:
    //vector3D * MasCercano(vector<vector3D*>& objetos,datos * NPCinfo);
    //int hambre;
    // HAMBRE
};
class Nodo_TengoSed : public Nodo {
public:
    Nodo_TengoSed();
    short run(int &id);
private:
    //vector3D * MasCercano(vector<vector3D*>& objetos,datos * NPCinfo);
    //int sed;
    // SED
};
class NodoComer : public Nodo {
public:
    NodoComer();
    short run(int &id);
private:
    // HAMBRE
    
};
class NodoBeber : public Nodo {
public:
    NodoBeber();
    short run(int &id);
private:
    // SED
};
class Nodo_TieneAgua : public Nodo {
public:
    Nodo_TieneAgua();
    short run(int &id);
private:
    // ESTADO FUENTE
};
class Nodo_HayParaHablar : public Nodo {
public:
    Nodo_HayParaHablar();
    short run(int &id);
private:
    // NPC + CERCANO
    
};
class NodoHablar : public Nodo {
public:
    NodoHablar();
    short run(int &id);
private:
    //  TEMAS RAMDOM
};
/*###################
 CLASES ALERTA
 ###################*/

class Nodo_AlarmaCerca : public Nodo {
public:
    Nodo_AlarmaCerca();
    short run(int &id);
private:
    //vector3D * posAlarma;
    //vector3D * MasCercano(vector<vector3D*>& objetos,datos * NPCinfo);
    // POSICION ALARMA + CERCANA
};

class NodoRecorreZonaCercana : public Nodo {
public:
    NodoRecorreZonaCercana();
    short run(int &id);
private:
    //
};

/*###################
 CLASES COMBATE
 ###################*/

class Nodo_PuedoAtacarDistancia : public Nodo {
public:
    Nodo_PuedoAtacarDistancia();
    short run(int &id);
private:
    //  TEMAS RAMDOM
};

class Nodo_EstasAsustado : public Nodo {
public:
    Nodo_EstasAsustado();
    short run(int &id);
private:
    // VIDA , HAMBRE Y SED
};
class Nodo_HayAlguienCerca : public Nodo {
public:
    Nodo_HayAlguienCerca();
    short run(int &id);
    //float CalcularDistancia(vector3D a, vector3D b);
private:
    // COORDENADAS NPC + CERCANO
};
class Nodo_HayAlguienRadio : public Nodo {
public:
    Nodo_HayAlguienRadio();
    short run(int &id);
private:
    // COORDENADAS DE NPC DENTRO DE RANGO DE RADIO ,
    // CUANTOS AVISA: COMBATE SOLO 1 , ASUSTADO 3 NPCS
};

class NodoAvisar : public Nodo {
public:
    NodoAvisar();
    short run(int &id);
private:
    // COORDENADAS PROPIAS
};
class Nodo_EstasCercaJugador : public Nodo {
public:
    Nodo_EstasCercaJugador();
    short run(int &id);
private:
    // COORDENADAS DEL JUGADOR
};
class Nodo_AlarmaRota : public Nodo {
public:
    Nodo_AlarmaRota();
    short run(int &id);
private:
    // COORDENADAS DEL JUGADOR
};
class Nodo_EstasLejosJugador : public Nodo {
public:
    Nodo_EstasLejosJugador();
    short run(int &id);
private:
    // COORDENADAS DEL JUGADOR
};
class NodoAtaqueCuerpo : public Nodo {
public:
    NodoAtaqueCuerpo();
    short run(int &id);
private:
};
class NodoAtaqueDistancia : public Nodo {
public:
    NodoAtaqueDistancia();
    short run(int &id);
private:
};
class NodoCubrirse : public Nodo {
public:
    NodoCubrirse();
    short run(int &id);
private:
    // OBJETOS DONDE CUBRISE, EL + CERCANO
};

/*###################
 CLASES ASUTADO
 ###################*/

class NodoHuir : public Nodo {
public:
    NodoHuir();
    short run(int &id);
private:
    // COORDENADAS DEL JUGADOR
};


#endif /* Nodos_hpp */
