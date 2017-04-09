//
//  state.hpp
//  estados
//
//  Created by Stoycho Ivanov Atanasov on 17/3/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef state_hpp
#define state_hpp

class states;

class state {
public:
	virtual void update() = 0;
	virtual void render() = 0;
protected:
	states* actualState;
};

#endif /* state_hpp */
