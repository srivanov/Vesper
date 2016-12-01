
#include <stdio.h>
//#include <irrlicht.h>
#include "engineInterface.hpp"
#include "physicsController.hpp"
#include "nodeMesh.hpp"
#include "Nodos.hpp"

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
 
    
	interfaceIrr->_createCamera(new float[3]{0,-10,0}, player->_getNodePosition(), new float[3]{0,0,0});
	fisicas->Footest();
	float *vel = new float[3], *pos = new float[3], *posmouseFinal = new float[3], *posicion_bala = new float[3];
	int *posmouse = new int[3];
	int* posmouse2 = new int[3];
	vel[2]=0;pos[2]=0;posmouseFinal[2]=0;posicion_bala[2]=0;posmouse[2]=0;posmouse2[2]=0;
    
    //variables para la posicion de la camara
    float posXCamara = 0;
    float posYCamara = -5; //-5
    float posZCamara = -10; //-10
    
    //interfaceIrr->_setNearValue(2);
    interfaceIrr->_setFarValue(20);
    
    //*****************TRAZADO DE SUPERRAYOS*****************
    ISceneCollisionManager* collMan = interfaceIrr->getSceneCollisionManager();
    
    
    interfaceIrr->loadMap();
    while(interfaceIrr->_Run()){
		fisicas->update();
		fisicas->Step(vel,pos, posmouseFinal, posmouse2);
		player->_setNodePosition(pos);
//		interfaceIrr->_setCamTarget(player->_getNodePosition()); //////
		if(bala != NULL){
			fisicas->getBulletPosition(posicion_bala);
			bala->_setNodePosition(posicion_bala);
		}
        interfaceIrr->_beginScene(true, true);
        interfaceIrr->_drawAll();
        interfaceIrr->_endScene();
        
        //me creo el rayo
//        line3d<float> rayo;
//        rayo.start = vector3df(player2->_getNodePosition()[0],player2->_getNodePosition()[1],player2->_getNodePosition()[2]);
//        rayo.end = vector3df(player->_getNodePosition()[0],player->_getNodePosition()[1],player->_getNodePosition()[2]);

        vector3df intersection;
        triangle3df hitTriangle;
//        ISceneNode* selectedNodeScene = collMan->getSceneNodeAndCollisionPointFromRay(rayo, intersection, hitTriangle);
		
		vel[0] = 0; vel[1] = 0;
		if(interfaceIrr->isKeyDown('Q')){
			interfaceIrr->_deviceClose();
		}
		if(interfaceIrr->isKeyDown('W')){
			vel[1] =  10;
//            posYCamara = player->_getNodePosition()[1]-5; //si pulso W se mueve en la y
            
		}
		if(interfaceIrr->isKeyDown('S')){
			vel[1] = -10;
//            posYCamara = player->_getNodePosition()[1]-5;
		}
		if(interfaceIrr->isKeyDown('A')){
			vel[0] = -10;
//            posXCamara = player->_getNodePosition()[0];
		}
		if(interfaceIrr->isKeyDown('D')){
			vel[0] =  10;
//            posXCamara = player->_getNodePosition()[0];
        
           // printf("****CAM2D: x%f, y%f, z%f \n", posXCamara, posYCamara, posZCamara);
//                printf("******** 3 CAMRA (t, rot): bx: %f, by: %f, rt%f, rt%f, rt%f \n", player->_getNodePosition()[0], player->_getNodePosition()[1], player->_getNodeRotation()[0], player->_getNodeRotation()[1], player->_getNodeRotation()[2]);
//
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
        //para que la camara se mueva en funcion de las teclas pulsadas
        interfaceIrr->_setCamPosition(new float[3]{player->_getNodePosition()[0]+posXCamara, player->_getNodePosition()[1]+posYCamara, player->_getNodePosition()[2]+posZCamara});
        interfaceIrr->_setCamTarget(new float[3]{player->_getNodePosition()[0],player->_getNodePosition()[1],player->_getNodePosition()[2]});
    }
    interfaceIrr->_deviceClose();
}

