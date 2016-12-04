//
//  transform3D.hpp
//  arquitectura
//
//  Created by Nerea Castellanos Rodríguez on 1/12/16.
//  Copyright © 2016 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef transform3D_hpp
#define transform3D_hpp

#include <stdio.h>
#include "component.hpp"
#include "GameObject.hpp"

class transform3D : public component{
public:
    transform3D(class GameObject* p);
    ~transform3D();
private:
	class GameObject* padre;
};
#endif /* transform3D_hpp */
