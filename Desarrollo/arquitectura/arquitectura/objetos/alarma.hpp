
#ifndef alarma_hpp
#define alarma_hpp

#include <time.h>
#include <stdio.h>
#include "GameObject.hpp"
#include "../Dvector.hpp"

class alarma : public GameObject{
public:
    alarma(int &ID);
    ~alarma();
    void update();
private:
    void gestorTiempo();
    int ID;
    bool activado;
    bool rota;
    bool NPCKnows;
    time_t _time;
};
#endif /* alarma_hpp */
