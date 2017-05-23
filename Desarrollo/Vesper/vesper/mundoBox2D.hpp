
#ifndef mundoBox2D_hpp
#define mundoBox2D_hpp

#include <stdio.h>
#include "Dvector.hpp"
#include <Box2D/Box2D.h>

class PhysicObject;

class ContactListener : public b2ContactListener{
	void BeginContact(b2Contact* contact);
	void EndContact(b2Contact* contact);
	void contacta(PhysicObject* p1, PhysicObject* p2);
	void atarlos(PhysicObject* p1, b2Body* bod);
	void esSensor(PhysicObject* g1s, PhysicObject* g2);
};

class mundoBox2D{
public:
	b2World* getWorld();
	static mundoBox2D* Instance();
	~mundoBox2D();
	void update(const long &timePerFrame);
	void cleanWorld();
    bool raycastContact(dvector3D posIni, dvector3D posFin);
protected:
	mundoBox2D();

private:
	b2World* world;
	int32 velocityIterations;   //how strongly to correct velocity
	int32 positionIterations;   //how strongly to correct position
	ContactListener contacto;
};

class MyRayCastCallback : public b2RayCastCallback
{
public:
    MyRayCastCallback()
    {
        m_fixture = NULL;
    }
    
    float32 ReportFixture(b2Fixture* fixture, const b2Vec2& point,
                          const b2Vec2& normal, float32 fraction)
    {
        m_fixture = fixture;
        m_point = point;
        m_normal = normal;
        m_fraction = fraction;
        return 1;
    }
    
    b2Fixture* m_fixture;
    b2Vec2 m_point;
    b2Vec2 m_normal;
    float32 m_fraction;
};

#endif /* mundoBox2D_hpp */
