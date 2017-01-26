
#ifndef puerta_hpp
#define puerta_hpp

#include <stdio.h>
#include "GameObject.hpp"

class puerta : public GameObject{
public:
    puerta();
    ~puerta();
    void contacto(GameObject* g);
    void contactoEnd(GameObject* g);
    bool const* getmuero();
private:
    bool muero;
};
#endif /* puerta_hpp */
