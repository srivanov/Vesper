/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Dvector.hpp
 * Author: Gaspar
 *
 * Created on 24 de diciembre de 2016, 20:11
 */

#ifndef DVECTOR_HPP
#define DVECTOR_HPP


struct vector3D {
    float x,y,z;
    vector3D() : x(0), y(0), z(0){};
    vector3D(const vector3D &p);
    virtual ~vector3D();
    vector3D& operator=(const vector3D &p);
    vector3D& operator+(const vector3D &p);
    vector3D& operator-(const vector3D &p);
    vector3D& operator*(const vector3D &p);
    vector3D& operator/(const vector3D &p);
    bool operator==(const vector3D &p) const {return this->x == p.x && this->y == p.y && this->z == p.z;};
};

#endif /* DVECTOR_HPP */

