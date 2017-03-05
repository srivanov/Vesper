
#ifndef puerta_hpp
#define puerta_hpp

#include <stdio.h>
#include "GameObject.hpp"
#include "../components/puertaInterface.hpp"
#include "../components/blindada.hpp"
#include "../components/bloqueada.hpp"
#include "../components/chirriante.hpp"
#include "../components/conAlarma.hpp"
#include "../components/conLlave.hpp"
#include "../components/conPuzzle.hpp"
#include "../components/destructiva.hpp"

enum typePuerta{
	tBLINDADA = 0,
	tBLOQUEADA,
	tCHIRRIANTE,
	tCONALARMA,
	tCONLLAVE,
	tCONPUZZLE,
	tDESTRUCTIVA
};

class puerta : public GameObject{
public:
    puerta();
    ~puerta();
    void contacto(GameObject* g);
    void contactoEnd(GameObject* g);
    bool const getmuero();
	void abre();
	void cierra();
	bool estasAbierta();
	void update();
	void setTipo(typePuerta t);
private:
    bool muero, abierta;
	puertaInterface* door;
};
#endif /* puerta_hpp */
