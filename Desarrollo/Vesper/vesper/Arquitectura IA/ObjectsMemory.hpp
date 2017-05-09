//
//  ObjectsMemory.hpp
//  vesper
//
//  Created by Gaspar Rodriguez Valero on 9/5/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef ObjectsMemory_hpp
#define ObjectsMemory_hpp

#include "../objetos/PhysicObjects/World/world.hpp"
#include <vector>

#define CADUCIDAD 4.f

enum Evalue{
    NEW = 0,
    NORMAL,
    CHANGED,
    NO_VALUABLE
};

struct Objecto {
    Objecto() {t.start();state = false;}
    ~Objecto(){}
    ObjectType m_tipo;
    dvector3D m_pos;
    bool state;
    tiempo t;
};

class MemoryObjects {
    std::vector<Objecto*> Objectos;
    size_t it, end;
    void addObject(PhysicObject *m_new);
    bool ExtractState(PhysicObject *m_new);
    bool FindObject(PhysicObject *other);
public:
    void update();
    Evalue evalue(PhysicObject * other);
};

#endif /* ObjectsMemory_hpp */
