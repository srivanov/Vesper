
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
    void render(float &interpolation);
	void shoot();
	void changeGun();
    void insertarArma(int a);
    void eliminarArma(std::vector<gun*>::iterator iter);
    typeArma getArmaActual();
    unsigned int getMunicion() { return (*seleccionada)->getMunicion(); }
    unsigned int getCarga() { return (*seleccionada)->getCarga(); }
    
private:
//	armaInterface* aux;
	std::vector<gun*>::iterator seleccionada, aux;
	std::vector<gun*> interfaz;
};

#endif /* armas_hpp */
