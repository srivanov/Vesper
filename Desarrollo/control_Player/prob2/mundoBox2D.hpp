
#ifndef mundoBox2D_hpp
#define mundoBox2D_hpp

#include <stdio.h>
#include <Box2D/Box2D.h>


class mundoBox2D {
	public:
        b2World* getWorld();
        static mundoBox2D* Instance();
        virtual ~mundoBox2D();
    
    protected:
        mundoBox2D();
	
	private:
		b2World* world;
        static mundoBox2D* pinstance;
		
};

#endif /* mundoBox2D_hpp */
