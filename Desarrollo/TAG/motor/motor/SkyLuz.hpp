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
	
	void Draw() { m_luz->Draw(nodo);}
private:
	TLuz *m_luz;
};

#endif /* SkyLuz_hpp */
