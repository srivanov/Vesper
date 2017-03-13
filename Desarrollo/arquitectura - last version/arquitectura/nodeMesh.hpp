
#ifndef nodeMesh_hpp
#define nodeMesh_hpp

#include <stdio.h>
#include <irrlicht.h>
#include "Dvector.hpp"

using namespace irr;
using namespace core;
using namespace video;
//using namespace io;
using namespace scene;


class nodeMesh{
public:
    nodeMesh(ISceneNode* node);
    ~nodeMesh();
    ISceneNode* _getNode();
	void _setNode(ISceneNode* node);
	bool _setMaterialTexture(ITexture* tex);
	void _setNodePosition(dvector3D &posicion);
	void _setNodeRotation(dvector3D &rotacion);
	void _setMaterialFlag(video::E_MATERIAL_FLAG flag, bool trigger);
    void setPortatil(ISceneNode* node);
	
	dvector3D* _getNodePosition();
	dvector3D* _getNodeRotation();
	
private:
    ISceneNode* object, *gun;
    ITexture* texture;
    
};

#endif /* nodeMesh_hpp */
