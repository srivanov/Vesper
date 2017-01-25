//
//  botiquin.hpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 11/1/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef botiquin_hpp
#define botiquin_hpp

#include "GameObject.hpp"
#include "Dvector.hpp"

class botiquin : public GameObject{
public:
    botiquin(int &ID);
    ~botiquin();
    void update();
    void contacto(GameObject* g);
    bool const* getmuero();
private:
    int ID;
    unsigned int usos;
    bool gastado;
    bool muero;
};

#endif /* botiquin_hpp */
