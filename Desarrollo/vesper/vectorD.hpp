//
//  vectorD.hpp
//  vesper
//
//  Created by Gaspar Rodriguez Valero on 13/12/16.
//  Copyright © 2016 Skyscrapers. All rights reserved.
//

#ifndef vectorD_hpp
#define vectorD_hpp


#include <irrlicht.h>
using namespace irr;
using namespace core;
using namespace video;
using namespace io;
using namespace scene;

class vector3D{
public:
    float x,y,z;
    bool operator ==(const vector3D &p) const;
    vector3D& operator =(const vector3D &p);
    vector3D(){x=0,y=0,z=0;}
    vector3D(float nx, float ny, float nz){x=nx;y=ny;z=nz;}
    //vector
    void clear();
    ~vector3D(){}
};


#endif /* vectorD_hpp */
