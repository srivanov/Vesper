//
//  SkyLuz.hpp
//  motor
//
//  Created by Stoycho Ivanov Atanasov on 5/3/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef SkyLuz_hpp
#define SkyLuz_hpp

#include "SkyNodo.hpp"
#include "TLuz.hpp"

class SkyLuz : public SkyNodo{
	friend class SkyEngine;
public:
	SkyLuz(TNodo* padre, int ID);
	~SkyLuz();
	
	int getID() { return m_luz->getID(); }
	
	void Draw(bool shadow_pass) { shadow_pass ? m_luz->shadowDraw(nodo) : m_luz->Draw(nodo);}
	void clearScreen() { m_luz->ClearScreen(); }
	void debugDraw(Shader* s) { m_luz->DebugDraw(s); }
    
    void setAmbient(float lamb){ m_luz->setAmbient(lamb);}
	void setDiffuse(float ldif){m_luz->setDiffuse(ldif);}
	void setSpecular(float lspec){ m_luz->setSpecular(lspec);}
	
	float getAmbient(){return m_luz->getAmbient();}
    float getDiffuse(){return m_luz->getDiffuse();}
    float getSpecular(){return m_luz->getSpecular();}
	
	void setLightDirection(dvector3D d) {lightDir = d.normalize(); m_luz->setLightDirection(glmConv::v3d2glm(&lightDir)); }
	dvector3D getLightDirection() { return lightDir; }
    
private:
	TLuz *m_luz;
	dvector3D lightDir;
};

#endif /* SkyLuz_hpp */
