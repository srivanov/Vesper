
#ifndef armas_hpp
#define armas_hpp

#include <stdio.h>
#include "component.hpp"
#include "armaInterface.hpp"
#include "pistola.hpp"
#include "escopeta.hpp"
#include "lanzaCaramelos.hpp"
#include "piedra.hpp"
#include "globoAgua.hpp"
#include "chicle.hpp"
#include "bombaHumo.hpp"
#include "martilloDeJuguete.hpp"
#include "pala.hpp"
#include <vector>

class armas : public component {
public:
    armas();
    ~armas();
	void update() override;
	void shoot();
	void changeGun();
    void insertarArma(int a);
    void eliminarArma(std::vector<armaInterface*>::iterator iter);
	
private:
//	armaInterface* aux;
	std::vector<armaInterface*>::iterator seleccionada;
	std::vector<armaInterface*> interface;
};

#endif /* armas_hpp */
