//
//  SkyCamara.hpp
//  motor
//
//  Created by Stoycho Ivanov Atanasov on 5/3/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef SkyCamara_hpp
#define SkyCamara_hpp

#include "SkyNodo.hpp"
#include "TCamara.hpp"

class SkyCamara : public SkyNodo{
public:
	SkyCamara(TNodo* padre, int ID);
	~SkyCamara();
	
	void Draw() { m_camara->Draw(nodo); }
private:
	TCamara* m_camara;
};

#endif /* SkyCamara_hpp */
