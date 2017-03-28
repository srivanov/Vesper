//
//  NpcLibrary.hpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 10/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef NpcLibrary_hpp
#define NpcLibrary_hpp

#include "Types.h"
#include "../Dvector.hpp"
#include "../Tools/EasyMath.hpp"
#include "../PathFinding/PathPlanning.hpp"
#include <vector>
#include "../tiempo.h"
#include <stdlib.h>
#include <map>

class Eventos;
class NpcBook;

class NpcLibrary{
    NpcLibrary();
    std::map<int,NpcBook*> libros;
    std::map<int,NpcBook*>::iterator it;
public:
    ~NpcLibrary();
    static NpcLibrary * instancia();
    NpcBook * add_book(const int&,dvector3D*);
    bool remove_book(const int&);
    NpcBook * recover_book(const int&);
    
};

struct Eventos{
    Eventos(int& ,const Prioridades&, dvector3D*);
    Eventos(int& ,const Prioridades&, std::vector<dvector3D*>);
    ~Eventos();
    int m_ID;
    tiempo m_time;
    std::vector<dvector3D*> m_posiciones;
};

class NpcBook{
    dvector3D * PosicionPropia;
    std::vector<dvector3D*> PosicionesDestino;
    std::map<Prioridades,Eventos*> pila;
    std::map<Prioridades,Eventos*>::iterator it;
    void valueObjective(const Prioridades&);
    void changeObjective();
public:
    int getMoral();
    void remove_EventsByType(const Prioridades&);
    bool Enemigo , Aviso , Ruido, Alarma , Evento , Alerta ;
    int m_ID;
    void resetVectorMovimiento();
    NpcBook(const int&,dvector3D*);
    void notify(int,const Prioridades,dvector3D *);
    void notify(int,const Prioridades,std::vector<dvector3D*>);
    dvector3D * getPosition() const {return PosicionPropia;}
    dvector3D * lastPosition() const;
    void updateBook();
    bool updateObjetivo();
    bool ExistEventByType(const Prioridades&);
    ~NpcBook();
    dvector3D * VectorMovimiento;
    int salud;
    int hambre;
    int sed;
    int estado;
    
};

#endif /* NpcLibrary_hpp */
