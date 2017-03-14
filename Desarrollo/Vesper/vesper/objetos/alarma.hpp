
#ifndef alarma_hpp
#define alarma_hpp

#include <time.h>
#include <stdio.h>
#include <iostream>
#include "GameObject.hpp"
#include "LevelBlackBoard.hpp"

class alarma : public GameObject{
public:
    alarma();
    ~alarma();
    void update();
    void contacto(GameObject* g);
    void contactoEnd(GameObject* g);
    bool const* getmuero();
    void activar();
    bool estaActivado();
    void muere();
private:
    void gestorTiempo();
    bool activado;
    bool rota;
    bool NPCKnows;
    time_t _time;
    bool muero;
};
#endif /* alarma_hpp */
