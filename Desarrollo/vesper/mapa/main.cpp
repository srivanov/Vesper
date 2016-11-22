
#include <stdio.h>
//#include <irrlicht.h>
#include "engineInterface.hpp"
#include "physicsController.hpp"
#include "nodeMesh.hpp"

/*
using namespace irr;
using namespace core;
using namespace video;
using namespace io;
using namespace scene;
*/

int main(){
	engineInterface* interfaceIrr = engineInterface::Instance();
	physicsController *fisicas = new physicsController();
	
	interfaceIrr->_createDevice(640, 480, 18, false, false, false, true);
	nodeMesh* player = interfaceIrr->_getNode("../../../modelos3D/sphere.3ds");
	nodeMesh* bala = NULL;
	interfaceIrr->_setMaterialFlag(player, 0, false);
	
	
	interfaceIrr->_setMaterialTexture(player, "../../../modelos3D/texture.png");
	player->_setNodePosition(new float[3]{0,0,0});
	interfaceIrr->_createCamera(new float[3]{0,-5,-10}, player->_getNodePosition(), new float[3]{0,0,0});
	
	fisicas->Footest();
	float *vel = new float[3], *pos = new float[3], *posmouseFinal = new float[3], *posicion_bala = new float[3];
	int *posmouse = new int[3];
	int* posmouse2 = new int[3];
	vel[2]=0;pos[2]=0;posmouseFinal[2]=0;posicion_bala[2]=0;posmouse[2]=0;posmouse2[2]=0;
	
    interfaceIrr->loadMap();
    while(interfaceIrr->_Run()){
		fisicas->update();
		fisicas->Step(vel,pos, posmouseFinal, posmouse2);
		player->_setNodePosition(pos);
		interfaceIrr->_setCamTarget(player->_getNodePosition()); //////
		if(bala != NULL){
			fisicas->getBulletPosition(posicion_bala);
			bala->_setNodePosition(posicion_bala);
		}
        interfaceIrr->_beginScene(true, true);
        interfaceIrr->_drawAll();
        interfaceIrr->_endScene();
		
		vel[0] = 0; vel[1] = 0;
		if(interfaceIrr->isKeyDown('Q')){
			interfaceIrr->_deviceClose();
		}
		if(interfaceIrr->isKeyDown('W')){
			vel[1] =  10;
		}
		if(interfaceIrr->isKeyDown('S')){
			vel[1] = -10;
		}
		if(interfaceIrr->isKeyDown('A')){
			vel[0] = -10;
		}
		if(interfaceIrr->isKeyDown('D')){
			vel[0] =  10;

		}
		if(interfaceIrr->isKeyDown('L')){
			vel[0] = 0; vel[1] = 0;
			if(bala == NULL){
				bala = interfaceIrr->_getNode("../../../modelos3D/bala.3ds");
				interfaceIrr->_setMaterialFlag(bala, 0, false);
				fisicas->dispararBala();
				bala->_setNodePosition(posicion_bala);
			}
		}
    }
    interfaceIrr->_deviceClose();
}

