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
public:
	SkyLuz(TNodo* padre, int ID);
	~SkyLuz();
	
	void Draw(bool shadow_pass) { shadow_pass ? m_luz->shadowDraw(nodo) : m_luz->Draw(nodo);}
	void clearScreen() { m_luz->ClearScreen(); }
	void debugDraw(Shader* s) { m_luz->DebugDraw(s); }
    
    void _setAmbient(float lamb){ m_luz->setAmbient(lamb);}
    float _getAmbient(){return m_luz->getAmbient();}
    
    void _setDiffuse(float ldif){m_luz->setDiffuse(ldif);}
    float _getDiffuse(){return m_luz->getDiffuse();}
    
    void _setSpecular(float lspec){ m_luz->setSpecular(lspec);}
    float _getSpecular(){return m_luz->getSpecular();}
    
private:
	TLuz *m_luz;
};

#endif /* SkyLuz_hpp */
