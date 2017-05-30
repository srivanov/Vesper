//
//  Nodo_APedir_Ayuda2.hpp
//  vesper
//
//  Created by Gaspar Rodriguez Valero on 8/4/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Nodo_APedir_Ayuda2_hpp
#define Nodo_APedir_Ayuda2_hpp

#include "../Nodo_base.hpp"
#include "../../Arquitectura IA/LevelBlackBoard.hpp"
#include "../../Arquitectura IA/NpcLibrary.hpp"

class Nodo_APedir_Ayuda2 : public Nodo_base {
    tiempo t;
    bool no_alarmas;
public:
    Nodo_APedir_Ayuda2(){no_alarmas=false;}
    ~Nodo_APedir_Ayuda2(){}
    short run(const int &ID);
};

#endif /* Nodo_APedir_Ayuda2_hpp */
