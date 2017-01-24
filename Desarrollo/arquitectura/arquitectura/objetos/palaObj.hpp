//
//  palaObj.hpp
//  arquitectura
//
//  Created by Stoycho Ivanov Atanasov on 22/1/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef palaObj_hpp
#define palaObj_hpp

#include <stdio.h>
#include "GameObject.hpp"
#include "../Dvector.hpp"

class palaObj : public GameObject{
public:
	palaObj();
	~palaObj();
	void update();
    void contacto(GameObject* g);
    bool const* getmuero();
private:
    bool muero;
};

#endif /* palaObj_hpp */
