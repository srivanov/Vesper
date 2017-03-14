//
//  Nodo_QRuido.hpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 22/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Nodo_QRuido_hpp
#define Nodo_QRuido_hpp

#include "../Nodo de Secuencia/Nodo_Condicional_Secuencial.hpp"

class Nodo_QRuido : public Nodo_Condicional_Secuencial{
public:
    short run(const int&);
    Nodo_QRuido(){}
    ~Nodo_QRuido(){}
};

#endif /* Nodo_QRuido_hpp */
