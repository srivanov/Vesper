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
#include "component.hpp"

using namespace std;

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
