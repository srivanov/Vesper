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
#include "Dvector.hpp"

class fuente : public GameObject{
public:
    fuente();
    ~fuente();
    void update();
    void contacto(GameObject* g);
    void contactoEnd(GameObject* g);
    bool const getmuero();
    void muere();
private:
    bool rota, NPCKnows, muero;
};

#endif /* fuente_hpp */
