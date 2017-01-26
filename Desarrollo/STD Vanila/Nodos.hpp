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
#include <math.h>

using namespace std;

/*###################
 CLASES GENERALES
 ###################*/
class Nodo {
public:
    Nodo(){}
    virtual short run(int &id) = 0;
    virtual ~Nodo(){}
    virtual void reset() = 0;
protected:
    bool borrable; // TO DO:
};

class NodoSecuencia : public Nodo {
public:
    NodoSecuencia();
    ~NodoSecuencia();
    short run(int &id);
    void reset();
    void anyadirHijo(Nodo * hijo);
private:
    vector<Nodo*> m_hijos;
    size_t hijo;
};
class NodoSecuenciaPositiva : public Nodo{
public:
    NodoSecuenciaPositiva();
    ~NodoSecuenciaPositiva();
    short run(int &id);
    void anyadirHijo(Nodo * hijo);
    void reset();
private:
    vector<Nodo*> m_hijos;
    size_t hijo = -1;
};
class NodoMover : public Nodo {
public:
    ~NodoMover();
    NodoMover();
    short run(int &id);
    void reset(){}
private:
    float CalcularDistancia(dvector3D a, dvector3D b);
    float aux = -1;
    float xABS, yABS;
    dvector3D * _movement;
};

class Nodo_VerJugador : public Nodo {
public:
    ~Nodo_VerJugador();
    Nodo_VerJugador();
    short run(int &id);
    void reset(){}
private:
};
class Nodo_HayRuido : public Nodo {
public:
    ~Nodo_HayRuido();
    Nodo_HayRuido();
    short run(int &id);
    void reset(){}
private:
};
class Nodo_SuenaAlarma : public Nodo {
public:
    ~Nodo_SuenaAlarma();
    Nodo_SuenaAlarma();
    short run(int &id);
    void reset(){}
private:
};

class NodoVigilar : public Nodo {
public:
    ~NodoVigilar();
    NodoVigilar();
    short run(int &id);
private:
    void reset(){}
    time_t _time;
};
class NodoPatrullar : public Nodo {
public:
    ~NodoPatrullar();
    NodoPatrullar();
    short run(int &id);
    void reset(){}
private:
};
class Nodo_TiempoInactivo : public Nodo {
public:
    ~Nodo_TiempoInactivo();
    Nodo_TiempoInactivo();
    short run(int &id);
    void reset(){}
private:
};

class NodoDarAlarma : public Nodo {
public:
    ~NodoDarAlarma();
    NodoDarAlarma();
    short run(int &id);
    void reset(){}
private:
};

class Nodo_TengoVigilar : public Nodo {
    time_t _time;
public:
    Nodo_TengoVigilar();
    ~Nodo_TengoVigilar();
    short run(int &id);
    void reset(){}
};

class Nodo_Avisado : public Nodo {
public:
    ~Nodo_Avisado();
    Nodo_Avisado();
    short run(int &id);
    void reset(){}
private:
    // Estado de la Alarma (CAMBIA ESTADO)
};
/*###################
 CLASES ESTANDAR
 ###################*/

class Nodo_VidaBaja : public Nodo {
public:
    ~Nodo_VidaBaja();
    Nodo_VidaBaja();
    short run(int &id);
    void reset(){}
private:
};

class Nodo_NecesitoAyuda : public Nodo {
public:
    Nodo_NecesitoAyuda();
    ~Nodo_NecesitoAyuda();
    short run(int &id);
    void reset(){}
private:
    
};

class Nodo_HayBotiquin : public Nodo {
public:
    ~Nodo_HayBotiquin();
    Nodo_HayBotiquin();
    short run(int &id);
    void reset(){}
private:
    
};

class NodoCurarse : public Nodo {
public:
    ~NodoCurarse();
    NodoCurarse();
    short run(int &id);
    void reset(){}
private:
};
class Nodo_TengoHambre : public Nodo {
public:
    ~Nodo_TengoHambre();
    Nodo_TengoHambre();
    short run(int &id);
    void reset(){}
private:
};
class Nodo_TengoSed : public Nodo {
public:
    ~Nodo_TengoSed();
    Nodo_TengoSed();
    short run(int &id);
    void reset(){}
private:
};
class NodoComer : public Nodo {
public:
    ~NodoComer();
    NodoComer();
    short run(int &id);
    void reset(){}
private:
};
class NodoBeber : public Nodo {
public:
    ~NodoBeber();
    NodoBeber();
    short run(int &id);
    void reset(){}
private:
};
class Nodo_TieneAgua : public Nodo {
public:
    ~Nodo_TieneAgua();
    Nodo_TieneAgua();
    short run(int &id);
    void reset(){}
private:
};
class Nodo_HayParaHablar : public Nodo {
public:
    ~Nodo_HayParaHablar();
    Nodo_HayParaHablar();
    short run(int &id);
    void reset(){}
private:
    
};
class NodoHablar : public Nodo {
public:
    ~NodoHablar();
    NodoHablar();
    short run(int &id);
    void reset(){}
private:
};
/*###################
 CLASES ALERTA
 ###################*/

class Nodo_AlarmaCerca : public Nodo {
public:
    ~Nodo_AlarmaCerca();
    Nodo_AlarmaCerca();
    short run(int &id);
    void reset(){}
private:
};

class NodoRecorreZonaCercana : public Nodo {
public:
    ~NodoRecorreZonaCercana();
    NodoRecorreZonaCercana();
    short run(int &id);
    void reset(){}
private:
};

/*###################
 CLASES COMBATE
 ###################*/

class Nodo_PuedoAtacarDistancia : public Nodo {
public:
    ~Nodo_PuedoAtacarDistancia();
    Nodo_PuedoAtacarDistancia();
    short run(int &id);
    void reset(){}
private:
};

class Nodo_EstasAsustado : public Nodo {
public:
    ~Nodo_EstasAsustado();
    Nodo_EstasAsustado();
    short run(int &id);
    void reset(){}
private:
};
class Nodo_HayAlguienCerca : public Nodo {
public:
    ~Nodo_HayAlguienCerca();
    Nodo_HayAlguienCerca();
    short run(int &id);
    void reset(){}
private:
};
class Nodo_HayAlguienRadio : public Nodo {
public:
    ~Nodo_HayAlguienRadio();
    Nodo_HayAlguienRadio();
    short run(int &id);
    void reset(){}
private:
    time_t time;
};

class NodoAvisar : public Nodo {
public:
    ~NodoAvisar();
    NodoAvisar();
    short run(int &id);
    void reset(){}
private:
};
class Nodo_EstasCercaJugador : public Nodo {
public:
    ~Nodo_EstasCercaJugador();
    Nodo_EstasCercaJugador();
    short run(int &id);
    void reset(){}
private:
};
class Nodo_AlarmaRota : public Nodo {
public:
    Nodo_AlarmaRota();
    ~Nodo_AlarmaRota();
    short run(int &id);
    void reset(){}
private:
};
class Nodo_EstasLejosJugador : public Nodo {
public:
    ~Nodo_EstasLejosJugador();
    Nodo_EstasLejosJugador();
    short run(int &id);
    void reset(){}
private:
};
class NodoAtaqueCuerpo : public Nodo {
public:
    ~NodoAtaqueCuerpo();
    NodoAtaqueCuerpo();
    short run(int &id);
    void reset(){}
private:
};
class NodoAtaqueDistancia : public Nodo {
public:
    ~NodoAtaqueDistancia();
    NodoAtaqueDistancia();
    short run(int &id);
    void reset(){}
private:
};
class NodoCubrirse : public Nodo {
public:
    ~NodoCubrirse();
    NodoCubrirse();
    short run(int &id);
    void reset(){}
private:
};

/*###################
 CLASES ASUTADO
 ###################*/

class NodoHuir : public Nodo {
public:
    NodoHuir();
    ~NodoHuir();
    short run(int &id);
    void reset(){}
private:
};


#endif /* Nodos_hpp */
