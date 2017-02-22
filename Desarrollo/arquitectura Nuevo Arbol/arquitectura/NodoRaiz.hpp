//
//  NodoRaiz.hpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 13/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef NodoRaiz_hpp
#define NodoRaiz_hpp

#include "Nodo.hpp"


class NodoRaiz : public Nodo {
public:
    NodoRaiz();
    ~NodoRaiz();
    short run(int &id);
    void reset();
    void anyadirHijo(Nodo * hijo);
private:
    vector<Nodo*> m_hijos;
};
#endif /* NodoSecuencia_hpp */

