/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   trigger_system.hpp
 * Author: Gaspar
 *
 * Created on 24 de diciembre de 2016, 19:42
 */

#ifndef TRIGGER_SYSTEM_HPP
#define TRIGGER_SYSTEM_HPP

#include <time.h>
#include <vector>
#include "Dvector.hpp"
#include "enemigos.hpp"

enum TypeEvents{
    E_none = -1,
    E_ruido,
    E_aviso,
    E_hablar,
    E_puerta,
    E_alarma,
    E_near_alarma,
    E_radio
};


struct triggers{
    TypeEvents _type;
    unsigned int _idTrigger;
    int * _idSource;
    dvector3D _pos;
    float _radio;
    time_t _duration;
    triggers(TypeEvents& type, unsigned int& idTrigger, int* idSource, dvector3D* pos, float radio, float duration);
    ~triggers();
};


class trigger_system {
public:
    static trigger_system * _instance();
    unsigned long add_trigger(TypeEvents type, int* id, dvector3D* pos, float radio, float duration);
    void remove_trigger(unsigned long id);
    void update();
    virtual ~trigger_system();
    bool ExistTrigger(TypeEvents& type, int& ID);
    void subs(enemigos* npc);
private:
    trigger_system();
    float CalcularDistancia(dvector3D a, dvector3D b);
    void clear();
    static trigger_system * _TSinstance;
    std::vector<triggers*> TRIGGER_VECTOR;
    std::vector<enemigos*> AGENTS;
    unsigned int IDcont;
};

#endif /* TRIGGER_SYSTEM_HPP */

