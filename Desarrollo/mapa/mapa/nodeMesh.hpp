//
//  nodeMesh.hpp
//  mapa
//
//  Created by Julia Martínez Valera on 17/11/16.
//  Copyright © 2016 Julia Martínez Valera. All rights reserved.
//

#ifndef nodeMesh_hpp
#define nodeMesh_hpp

#include <stdio.h>
#include <irrlicht.h>

using namespace irr;
using namespace core;
using namespace video;
using namespace io;
using namespace scene;


class nodeMesh{
public:
    nodeMesh(char* filename, char* texname);
    ~nodeMesh();
    IMesh* _getMesh();
    
private:
    IMesh* object;
    ITexture* texture;
    
};

#endif /* nodeMesh_hpp */
