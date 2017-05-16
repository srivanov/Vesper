//
//  Camera.cpp
//  Arquitectura
//
//  Created by Gaspar Rodriguez Valero on 16/3/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#include "Camera.hpp"

Camera::Camera(dvector3D speed) : m_objective(nullptr){
    m_speed = speed;
    autoCamera = false;
    offSet = dvector3D(0,-4,-9);
    m_scale = 1;
    render_component = static_cast<class render*>(componentes.find(RENDER)->second) ;
    posCamara = dvector3D(0,0,0);
    copy_objective = dvector3D(0,0,0);
    render_component->addCamera(posCamara, copy_objective);
    map_width=0.f;
    map_height=0.f;
}
Camera::~Camera(){}

void Camera::setScale(float &scale){
    m_scale = scale;
}

void Camera::setCameraSpeed(float x, float y, float z){
    m_speed = dvector3D(x,y,z);
}
void Camera::setCameraSpeed(dvector3D &vector){m_speed = vector;}

void Camera::setOffSet(float x, float y, float z){
    offSet= dvector3D(x,y,z);
}
void Camera::setOffSet(dvector3D &vector){offSet = vector;}

void Camera::EnableAutoCamera(dvector3D* position){
    if(autoCamera)
        printf("| Camera Objective Changed |\n");
    else
        printf("| AutoCamera - enabled |\n");
    
    m_objective = position; ///////////////
    autoCamera = true;
    calculateAutoPosition();
    
}
void Camera::DisableAutoCamera(){
    if(!autoCamera) {
        printf("\n ### ERROR - NOT DISABLE NO ACTIVE FUNCTION ###\n");
        return;
    }
    
    autoCamera = !autoCamera;
    m_objective = nullptr;
    
    printf("| AutoCamera - disabled |\n");
    
}

dvector3D * Camera::getCameraPosition(){
    return getPosition();
}

void Camera::calculateAutoPosition(){
    
    if(*m_objective==copy_objective) return;
    
    copy_objective=*m_objective;
    
    //LIMITACIONES CAMARA CON MAPA
    if(copy_objective.x > map_width-10) copy_objective.x = map_width-10; //DERECHA
    if(copy_objective.y > map_height-13) copy_objective.y  = map_height-13;//arriba
    if(copy_objective.y < 6) copy_objective.y = 6;//abajo
    if(copy_objective.x < 10) copy_objective.x = 10; //izquierda
    
    
    dvector3D * renderPos = render_component->getCamPos();
    //incremento = ((*m_objective+offSet*m_scale) - renderPos)/ (m_speed*60.0);
	
    
    dvector3D aux1(copy_objective+offSet);
    
//    if(aux1.x > map_width-15){ //arriba derecha
//        aux1.x = map_width-15;
//    }
    
    
   // if(aux1.x > map_width-15 ){
        render_component->setCamPos(aux1); /////////
   // }
    
    //printf("MAPwdth: %.1f, MAPheight: %.1f", map_width, map_height);
//    printf("\n Pos_cam: %.1f, %.1f", aux1.x, aux1.y );
//    printf("\n Targ_cam: %.1f, YYYY: %.1f", copy_objective.x, copy_objective.y );
//    printf("\n offsetXYZ: %.1f,%.1f,%.1f", offSet.x,offSet.y,offSet.z);

    render_component->setCamTarget(copy_objective);/////////
}

void Camera::setCoordsMap(float m_width, float m_height){
    map_width = m_width;
    map_height = m_height;
}

void Camera::update(){
    if(autoCamera){
        calculateAutoPosition();
    }
    GameObject::update();
    
}
