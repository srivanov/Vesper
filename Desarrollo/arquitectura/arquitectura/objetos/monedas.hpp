
#ifndef monedas_hpp
#define monedas_hpp

#include <stdio.h>
#include "GameObject.hpp"
#include "../Dvector.hpp"

class monedas : public GameObject{
public:
    monedas();
    ~monedas();
    void update();
    void contacto(GameObject* g);
    bool const* getmuero();
private:
    bool muero;
};
#endif /* monedas_hpp */
