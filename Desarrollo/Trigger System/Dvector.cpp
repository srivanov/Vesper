/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Dvector.cpp
 * Author: Gaspar
 * 
 * Created on 24 de diciembre de 2016, 20:11
 */

#include "Dvector.hpp"


vector3D::vector3D(const vector3D &p) {
    this->x = p.x;
    this->y = p.y;
    this->z = p.z;
}

vector3D::~vector3D() {
}

vector3D& vector3D::operator=(const vector3D &p){
    if(&p!=this){
        this->x = p.x;
        this->y = p.y;
        this->z = p.z;
    }
    return *this;
}
vector3D& vector3D::operator+(const vector3D &p){
    this->x+=p.x;
    this->y+=p.y;
    this->z+=p.z;
    return *this;
}
vector3D& vector3D::operator-(const vector3D &p){
    this->x-=p.x;
    this->y-=p.y;
    this->z-=p.z;
    return *this;
}
vector3D& vector3D::operator*(const vector3D &p){
    this->x*=p.x;
    this->y*=p.y;
    this->z*=p.z;
    return *this;
}
vector3D& vector3D::operator/(const vector3D &p){
    if(p.x != 0)this->x/=p.x;
    if(p.y != 0)this->y/=p.y;
    if(p.z != 0)this->z/=p.z;
    return *this;
}