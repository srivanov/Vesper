//
//  GameObject.hpp
//  arquitectura
//
//  Created by Nerea Castellanos Rodríguez on 29/11/16.
//  Copyright © 2016 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef GameObject_hpp
#define GameObject_hpp

#include <stdio.h>
#include <map>
//#include "component.hpp"

#include "armasArrojadizas.hpp"
#include "armasDisparo.hpp"
#include "ataque.hpp"
#include "blindada.hpp"
#include "bloqueada.hpp"
#include "chirriante.hpp"
#include "conAlarma.hpp"
#include "conLlave.hpp"
#include "conPuzzle.hpp"
#include "destructiva.hpp"
#include "habilidadEspecial.hpp"
#include "hambre.hpp"
#include "IACamara.hpp"
#include "IAEnemigos.hpp"
//#include "input.hpp"
#include "martilloDeJuguete.hpp"
#include "transform3D.hpp"
#include "pala.hpp"
#include "Physics.hpp"
#include "piedra.hpp"
#include "render.hpp"
#include "salud.hpp"
#include "sed.hpp"

using namespace std;

class component;

class GameObject{
public:
    GameObject();
    ~GameObject();
    void insertComponent(char* nombre, component comp);
    void eraseComponent(char* nombre);
    bool findComponent(char* nombre);
private:
	map <char*, component> components;
};

#endif /* GameObject_hpp */
