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
//using namespace io;
using namespace scene;


class nodeMesh{
public:
    nodeMesh(ISceneNode* mesh);
    ~nodeMesh();
    IMesh* _getMesh();
	bool _setMaterialTexture(ITexture* tex);
	void _setNodePosition(float* posicion);
	void _setNodeRotation(float* rotacion);
	void _setMaterialFlag(video::E_MATERIAL_FLAG flag, bool trigger);
	
	float* _getNodePosition();
	float* _getNodeRotation();
	
private:
    ISceneNode* object;
    ITexture* texture;
};

#endif /* nodeMesh_hpp */
