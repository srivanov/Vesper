//
//  GameObject.hpp
//  Arquitectura
//
//  Created by Gaspar Rodriguez Valero on 15/3/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#ifndef GameObject_hpp
#define GameObject_hpp

#include "../components/ataque.hpp"
#include "../components/habilidadEspecial.hpp"
#include "../components/hambre.hpp"
#include "../components/input.hpp"
#include "../components/Physics.hpp"
#include "../components/render.hpp"
#include "../components/salud.hpp"
#include "../components/sed.hpp"
#include "../Dvector.hpp"
#include "../Tools/EasyMath.hpp"
#include <vector>
#include <map>

enum ComponentType{
    EMPTY = 0,
    RENDER,
    PHYSICS,
    ATAQUE,
    ARMAS,
    HABESPECIAL
};

enum ObjectType {
    tVOID = 0,
    MURO,
    ALARMA,
    MONEDAS,
    PLAYER,
    PALA,
    PIEDRA,
    ENEMIGOS,
    LLAVE,
    FUENTE,
    BOTIQUIN,
    PUERTA,
    COMIDA,
    CESPED,
    REHEN,
    ESCOPETA,
    SWEET_SHOOTER,
    GLOBO_AGUA,
    BUMMER_BOOM,
    BOMBA_HUMO,
    ARBUSTOS,
    BALA
};



class GameObject {
    GameObject(const GameObject&) = delete;
protected:
    dvector3D m_pos , m_rot ;
    std::map<const ComponentType,component*> componentes;
    std::map<const ComponentType,component*>::iterator it;
    int m_ID;
    bool eliminar;
    ObjectType m_tipo;
public:
    void setObjectType(const ObjectType tipo){m_tipo=tipo;}
    ObjectType getObjectType() const {return m_tipo;}
    GameObject();
    virtual ~GameObject();
    void addNodo(char* filename);
    void setTexture(char* filename);
    virtual void inicializar(int ID);
    virtual dvector3D * getPosition() {return &m_pos;}
    virtual dvector3D * getRotation() {return &m_rot;}
    virtual void setPosition(dvector3D&);
    virtual void setRotation(dvector3D&);
    virtual void update();
    virtual void render();
    bool Eliminable() const {return eliminar;}
};

#endif /* GameObject_hpp */
