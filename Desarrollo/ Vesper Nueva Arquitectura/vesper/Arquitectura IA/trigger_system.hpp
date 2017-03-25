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

#include "NpcLibrary.hpp"


struct triggers{
    Prioridades _type;
    int _idTrigger;
    int  _idSource;
    dvector3D *_pos;
    float _radio;
    time_t _duration;
    triggers(const Prioridades& type, unsigned int idTrigger, int idSource, dvector3D * pos, float radio, float duration);
    ~triggers();
};


class trigger_system {
public:
    static trigger_system * instance();
    void add_trigger(const Prioridades& type, int id, dvector3D * pos, float radio, int duration);
    void update_trigger();
    void update();
    virtual ~trigger_system();
    bool ExistTrigger(const Prioridades& type, int& ID);
    void subs(NpcBook* npc);
private:
    trigger_system();
    void clear();
    std::vector<triggers*> TRIGGER_VECTOR;
    std::vector<NpcBook*> AGENTS;
    unsigned int IDcont;
};

#endif /* TRIGGER_SYSTEM_HPP */

