//
//  Camera.hpp
//  Arquitectura
//
//  Created by Gaspar Rodriguez Valero on 16/3/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#ifndef Camera_hpp
#define Camera_hpp

#include "GameObject.hpp"
#include <iostream>

class Camera : public GameObject{
private:
    void calculateAutoPosition();
    
    dvector3D * m_objective, copy_objective, posCamara;
    dvector3D offSet , incremento;
    float m_scale;
    bool autoCamera;
    dvector3D m_speed;
    class render * render_component;
public:
    void resetScale(){m_scale=1;}
    void setScale(float& scale);
    dvector3D * getCameraPosition();
    void DisableAutoCamera();
    Camera(dvector3D speed = dvector3D(1,1,1));
    ~Camera();
    void EnableAutoCamera(dvector3D* pos_player);
    void setCameraSpeed(float x, float y, float z);
    void setOffSet(float x,float y, float z);
    void setCameraSpeed(dvector3D&);
    void setOffSet(dvector3D&);
    void update();
};

#endif /* Camera_hpp */
