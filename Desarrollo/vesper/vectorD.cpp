//
//  vectorD.cpp
//  vesper
//
//  Created by Gaspar Rodriguez Valero on 13/12/16.
//  Copyright © 2016 Skyscrapers. All rights reserved.
//

#include "vectorD.hpp"
bool vector3D::operator ==(const vector3D &p) const{
    return this->x==p.x && this->y==p.y && this->z==p.z;
    
}
vector3D& vector3D::operator=(const vector3D &p){
    if(this!=&p){
        if(p.x != 0 ) this->x = p.x;
        if(p.y != 0 ) this->y = p.y;
        if(p.z != 0 ) this->z = p.z;
    }
    return *this;
}
vector3D& vector3D::operator =(const vector3d<u32> &p){
    if(p.X != 0 ) this->x = p.X;
    if(p.Y != 0 ) this->y = p.Y;
    if(p.Z != 0 ) this->z = p.Z;
    return *this;
}
void vector3D::clear(){this->x=-1,this->y=-1,this->z=-1;}
