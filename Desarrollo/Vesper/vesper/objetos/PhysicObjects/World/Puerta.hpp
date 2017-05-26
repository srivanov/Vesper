//
//  Puerta.hpp
//  Arquitectura
//
//  Created by Gaspar Rodriguez Valero on 16/3/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#ifndef Puerta_hpp
#define Puerta_hpp

#include "../PhysicObject.hpp"
#include "../../../Arquitectura IA/gestor_eventos.hpp"

//crear enum para el tipo de la puerta
enum tipoPuerta{
    psimple = 0,
    palarma,
    pdestructiva,
    pbloqueada
};

class Puerta : public PhysicObject {
    int key;
public:
    bool EstaAbierta(){return abierta;}
	void setKey(int k){key=k;}
    Puerta();
    ~Puerta(){}
    void inicializar(int id, const tipoPuerta p);
    void contacto(PhysicObject *g);
    void contactoEnd(PhysicObject *g){}
    const tipoPuerta getPuerta() {return pu;}
    bool abrir(int llave);
private:
    bool abierta;
    tipoPuerta pu;
    void activarAlarma();
};

#endif /* Puerta_hpp */
