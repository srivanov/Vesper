//
//  mundoBox2D.hpp
//  prob2
//
//  Created by Stoycho Ivanov Atanasov on 4/11/16.
//  Copyright © 2016 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef mundoBox2D_hpp
#define mundoBox2D_hpp

#include <stdio.h>
#include <Box2D/Box2D.h>


class mundoBox2D {
	public:
		mundoBox2D();
	
	private:
		b2World* world;
		int i;
};

#endif /* mundoBox2D_hpp */
