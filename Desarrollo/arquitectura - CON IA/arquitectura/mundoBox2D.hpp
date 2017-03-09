
#ifndef mundoBox2D_hpp
#define mundoBox2D_hpp

#include <stdio.h>
#include <Box2D/Box2D.h>

class ContactListener : public b2ContactListener{
	void BeginContact(b2Contact* contact);
	void EndContact(b2Contact* contact);
};

class mundoBox2D{
public:
	b2World* getWorld();
	static mundoBox2D* Instance();
	~mundoBox2D();
	void update();

protected:
	mundoBox2D();

private:
	b2World* world;
	static mundoBox2D* pinstance;
	float32 timeStep;      //the length of time passed to simulate (seconds)
	int32 velocityIterations;   //how strongly to correct velocity
	int32 positionIterations;   //how strongly to correct position
	ContactListener contacto;
};

#endif /* mundoBox2D_hpp */
