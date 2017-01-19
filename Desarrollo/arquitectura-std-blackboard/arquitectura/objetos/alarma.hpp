
#ifndef alarma_hpp
#define alarma_hpp
#include "Dvector.hpp"
#include <time.h>
#include <stdio.h>
#include "GameObject.hpp"

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
    dvector3D * posi;
    time_t _time;
};
#endif /* alarma_hpp */
