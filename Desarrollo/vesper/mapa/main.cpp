
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
	
	interfaceIrr->_createDevice(640, 480, 18, true, false, false, true);
	nodeMesh* player = interfaceIrr->_getNode("../../../modelos3D/sphere.3ds");
	nodeMesh* bala = NULL;

	interfaceIrr->_setMaterialFlag(player, 0, false);
    
	
	
	interfaceIrr->_setMaterialTexture(player, "../../../modelos3D/texture.png");
    
	player->_setNodePosition(new float[3]{0,0,0});
 
    
	interfaceIrr->_createCamera(new float[3]{0,0,0}, player->_getNodePosition(), new float[3]{0,0,0});
	fisicas->Footest();
	float *vel = new float[3], *pos = new float[3], *posmouseFinal = new float[3], *posicion_bala = new float[3];
	int *posmouse = new int[3];
	int* posmouse2 = new int[3];
	vel[2]=0;pos[2]=0;posmouseFinal[2]=0;posicion_bala[2]=0;posmouse[2]=0;posmouse2[2]=0;
    
    //variables para la posicion de la camara
    float posXCamara = 0;
    float posYCamara = -5; //-5
    float posZCamara = -10; //-10
    float incZ = 0, incY =0, incX =0;
//    uint32_t cont = 0;
    interfaceIrr->_setFarValue(20);
	interfaceIrr->_setNearValue(1);

	
    interfaceIrr->_setCamPosition(new float[3]{player->_getNodePosition()[0]+posXCamara, player->_getNodePosition()[1]+posYCamara, player->_getNodePosition()[2]+posZCamara});
    interfaceIrr->_setCamTarget(new float[3]{player->_getNodePosition()[0],player->_getNodePosition()[1],player->_getNodePosition()[2]});
	
    interfaceIrr->loadMap();
    
    float time;
    bool cerca = false;
    
    while(interfaceIrr->_Run()){
		fisicas->update();
		fisicas->Step(vel,pos, posmouseFinal, posmouse2);
		player->_setNodePosition(pos);
		
        if(cerca){
            time = 0.6;
        }else{
            time = 1.5;
        }
        
		incX = ((player->_getNodePosition()[0]+posXCamara)-interfaceIrr->_getCamPosition()[0])/(time*60);
		incY = ((player->_getNodePosition()[1]+posYCamara)-(interfaceIrr->_getCamPosition()[1]))/(time*60);
		incZ = ((player->_getNodePosition()[2]+posZCamara)-(interfaceIrr->_getCamPosition()[2]))/(time*60);
		
        
        
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
			vel[1] =  1;
		}
		if(interfaceIrr->isKeyDown('S')){
			vel[1] = -1;
            
		}
		if(interfaceIrr->isKeyDown('A')){
			vel[0] = -1;
		}
		if(interfaceIrr->isKeyDown('D')){
			vel[0] =  1;
		}
        if(interfaceIrr->isKeyDown('O')){ //zoom lejos
			posYCamara = -5;
			posZCamara = -10;
            cerca=false;
//			cont = 0;
        }
        if(interfaceIrr->isKeyDown('P')){ //zoom cerca
			posYCamara = -2.5;
			posZCamara = -5;
            cerca = true;
//			cont = 0;

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
        
//        if(cont < 120){
            interfaceIrr->_setCamPosition(new float[3]{interfaceIrr->_getCamPosition()[0] + incX,interfaceIrr->_getCamPosition()[1] + incY, interfaceIrr->_getCamPosition()[2] + incZ});
//            interfaceIrr->_setCamTarget(new float[3]{player->_getNodePosition()[0],player->_getNodePosition()[1],player->_getNodePosition()[2]});
			interfaceIrr->_setCamTarget(new float[3]{interfaceIrr->_getCamPosition()[0], (float)(interfaceIrr->_getCamPosition()[1]+2.5), interfaceIrr->_getCamPosition()[2]+5});
//            posXCamara = interfaceIrr->_getCamPosition()[0] - player->_getNodePosition()[0];
//            posYCamara = interfaceIrr->_getCamPosition()[1] - player->_getNodePosition()[1];
//            posZCamara = interfaceIrr->_getCamPosition()[2] - player->_getNodePosition()[2];
//            cont++;
//        }else{
//            para que la camara se mueva en funcion de las teclas pulsadas
//
//            interfaceIrr->_setCamPosition(new float[3]{player->_getNodePosition()[0]+posXCamara, player->_getNodePosition()[1]+posYCamara, player->_getNodePosition()[2]+posZCamara});
//            interfaceIrr->_setCamTarget(new float[3]{player->_getNodePosition()[0],player->_getNodePosition()[1],player->_getNodePosition()[2]});
//        }
    }
    interfaceIrr->_deviceClose();
}

