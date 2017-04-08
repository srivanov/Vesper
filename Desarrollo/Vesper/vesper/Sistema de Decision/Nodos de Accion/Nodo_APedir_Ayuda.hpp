//
//  Nodo_APedir_Ayuda.hpp
//  vesper
//
//  Created by Gaspar Rodriguez Valero on 8/4/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Nodo_APedir_Ayuda_hpp
#define Nodo_APedir_Ayuda_hpp

#include "../Nodo_base.hpp"
#include "../../Arquitectura IA/gestor_eventos.hpp"
#include "../../Arquitectura IA/NpcLibrary.hpp"

class Nodo_APedir_Ayuda : public Nodo_base {
    bool primera_ayuda;
    bool segunda_ayuda;
    bool alarma;
public:
    short run(const int& ID);
    void reset(){}
    Nodo_APedir_Ayuda(){primera_ayuda = segunda_ayuda = alarma = false;}
    ~Nodo_APedir_Ayuda(){}
};

#endif /* Nodo_APedir_Ayuda_hpp */
