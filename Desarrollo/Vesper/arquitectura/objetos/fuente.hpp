//
//  fuente.hpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 11/1/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef fuente_hpp
#define fuente_hpp

#include "GameObject.hpp"
#include "../Arquitectura IA/LevelBlackBoard.hpp"

class fuente : public GameObject{
public:
    fuente();
    ~fuente();
    void update();
    void contacto(GameObject* g);
    void contactoEnd(GameObject* g);
    bool const* getmuero();
    void muere();
private:
    int ID;
    bool rota, NPCKnows, muero;
};

#endif /* fuente_hpp */
