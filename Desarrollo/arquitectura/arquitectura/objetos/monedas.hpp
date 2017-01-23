
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
};
#endif /* monedas_hpp */
