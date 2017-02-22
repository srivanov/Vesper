//
//  Nodo_Avisado.hpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Nodo_Avisado_hpp
#define Nodo_Avisado_hpp

#include "Nodo.hpp"


class Nodo_Avisado : public Nodo {
public:
    ~Nodo_Avisado();
    Nodo_Avisado();
    short run(int &id);
    void reset(){}
private:
    // Estado de la Alarma (CAMBIA ESTADO) //TO DO:
};

#endif /* Nodo_Avisado_hpp */
