//
//  component.hpp
//  arquitectura
//
//  Created by Stoycho Ivanov Atanasov on 29/11/16.
//  Copyright © 2016 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef component_hpp
#define component_hpp

#include <stdio.h>

class GameObject;

class component{
public:
	component();
	void setFather(GameObject* p);
	~component();
private:
	GameObject* padre;
};

#endif /* component_hpp */
