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
    offSet = dvector3D(0,-5,-10);
    m_scale = 1;
    render_component = static_cast<class render*>(componentes.find(RENDER)->second) ;
    posCamara = dvector3D(0,-5,-10);
    render_component->addCamera(posCamara, copy_objective);
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
        printf("| Camera Objective Changed |");
    m_objective = position;
    copy_objective = *position;
    autoCamera = true;
    std::cout << "OBJECTIVO :" << m_objective->x << "|" << m_objective->y << "|" << m_objective->z << std::endl;
    std::cout << "OBJECTIVO :" << render_component->getCamPos()->x << "|" << render_component->getCamPos()->y << "|" << render_component->getCamPos()->z << std::endl;
    printf("| AutoCamera - enabled |");
}
void Camera::DisableAutoCamera(){
    if(!autoCamera) {
        printf("\n ### ERROR - NOT DISABLE NO ACTIVE FUNCTION ###\n");
        return;
    }
    
    autoCamera = !autoCamera;
    m_objective = nullptr;
    
    printf("| AutoCamera - disabled |");
    
}

dvector3D * Camera::getCameraPosition(){
    return getPosition();
}

void Camera::calculateAutoPosition(){
    
    if(*m_objective==copy_objective) return;
    
    copy_objective=*m_objective;
    
    dvector3D * renderPos = render_component->getCamPos();
    incremento = ((*m_objective+offSet*m_scale) - renderPos)/ (m_speed*60.0);
    
    
    //dvector3D aux1(*renderPos+incremento);
    //dvector3D aux2(*renderPos-offSet);
    
    dvector3D aux1(copy_objective+offSet);
    
    render_component->setCamPos(aux1);
    render_component->setCamTarget(copy_objective);
}

void Camera::update(){
    
    if(autoCamera)
        calculateAutoPosition();
    
    
    GameObject::update();
    return;
    
}
