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
#include "Dvector.hpp"
#include "EasyMath.hpp"
#include "PathPlanning.hpp"
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <map>

class Eventos;
class NpcBook;

class NpcLibrary{
    NpcLibrary();
    static NpcLibrary * library;
    std::map<int,NpcBook*> libros;
    std::map<int,NpcBook*>::iterator it;
public:
    ~NpcLibrary();
    static NpcLibrary * instancia();
    NpcBook * add_book(int&,dvector3D*);
    bool remove_book(int&);
    NpcBook * recover_book(int&);
    
};

struct Eventos{
    Eventos(int& ,const Prioridades&, dvector3D*);
    Eventos(int& ,const Prioridades&, std::vector<dvector3D*>);
    ~Eventos();
    int m_ID;
    Prioridades m_tipo;
    time_t m_time;
    std::vector<dvector3D*> m_posiciones;
};

class NpcBook{
    dvector3D * PosicionPropia;
    std::vector<dvector3D*> PosicionesDestino;
    std::vector<Eventos*> pila;
    
    void add_Event(int&,const Prioridades& tipo, dvector3D * posicion);
    void add_Event(int&,const Prioridades& tipo, std::vector<dvector3D*> posicion);
    void changeObjective(const Prioridades&,int&);
    void changeObjective(const Prioridades&,dvector3D*);
    void remove_Events(int&);
    std::vector<dvector3D*> PathPlanning(dvector3D*);
public:
    bool Enemigo, Aviso, Ruido, Alarma,Evento;
    int * m_ID;
    void resetVectorMovimiento();
    NpcBook(int&,dvector3D*);
    void notify(int&,const Prioridades&,dvector3D *);
    void notify(int&,const Prioridades&,std::vector<dvector3D*>);
    dvector3D * getPosition() const {return PosicionPropia;}
    bool ExistEventByID(int& ID);
    dvector3D * lastPosition() const;
    void updateBook();
    bool updatePilaObjetivo();
    bool ExistEventByType(const Prioridades&);
    ~NpcBook();
    dvector3D * VectorMovimiento;
    int salud;
    int hambre;
    int sed;
    int estado;
    
};

#endif /* NpcLibrary_hpp */
