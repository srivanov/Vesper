
#ifndef armas_hpp
#define armas_hpp

#include <stdio.h>
#include "component.hpp"
#include "gun.hpp"
#include <vector>
#include "Dvector.hpp"

class armas : public component {
public:
    armas();
    ~armas();
	void update() override;
    void render();
	void shoot();
	void changeGun();
    void insertarArma(int a);
    void eliminarArma(std::vector<gun*>::iterator iter);
    gun* getArmaActual();
	
private:
//	armaInterface* aux;
	std::vector<gun*>::iterator seleccionada;
	std::vector<gun*> interface;
};

#endif /* armas_hpp */
