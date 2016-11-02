#include <irrlicht.h>
#include <Box2D/Box2D.h>
#include <stdio.h>

using namespace irr;
using namespace core;
using namespace video;

#if defined(_MSC_VER)
#pragma comment(lib, "Irrlicht.lib")
#endif

class MyEventReceiver : public IEventReceiver
{
public:
	// This is the one method that we have to implement
	virtual bool OnEvent(const SEvent& event)
	{
		// Remember whether each key is down or up
		if (event.EventType == irr::EET_KEY_INPUT_EVENT)
			KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
		
		return false;
	}
	
	// This is used to check whether a key is being held down
	virtual bool IsKeyDown(EKEY_CODE keyCode) const
	{
		return KeyIsDown[keyCode];
	}
	
	MyEventReceiver()
	{
		for (u32 i=0; i<KEY_KEY_CODES_COUNT; ++i)
			KeyIsDown[i] = false;
	}
	
private:
	// We use this array to store the current state of each key
	bool KeyIsDown[KEY_KEY_CODES_COUNT];
};


int main()
{
	
	MyEventReceiver receiver;
	IrrlichtDevice* device = createDevice(EDT_OPENGL, dimension2d<u32>(640, 480), 16, false, false, false, &receiver);
	if (!device)
		return 1;
	IVideoDriver* driver = device->getVideoDriver();
	device->setWindowCaption(L"HOLA");
	
	
	// Define the gravity vector.
	b2Vec2 gravity(0.0f, -10.0f);
	
	// Construct a world object, which will hold and simulate the rigid bodies.
	b2World world(gravity);
	
	// Define the ground body.
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0.0f, -10.0f);
	
	// Call the body factory which allocates memory for the ground body
	// from a pool and creates the ground box shape (also from a pool).
	// The body is also added to the world.
	b2Body* groundBody = world.CreateBody(&groundBodyDef);
	
	// Define the ground box shape.
	b2PolygonShape groundBox;
	
	// The extents are the half-widths of the box.
	groundBox.SetAsBox(50.0f, 10.0f);
	
	// Add the ground fixture to the ground body.
	groundBody->CreateFixture(&groundBox, 0.0f);
	
	// Define the dynamic body. We set its position and call the body factory.
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(0.0f, 4.0f);
	b2Body* body = world.CreateBody(&bodyDef);
	
	// Define another box shape for our dynamic body.
	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(1.0f, 1.0f);
	
	// Define the dynamic body fixture.
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	
	// Set the box density to be non-zero, so it will be dynamic.
	fixtureDef.density = 1.0f;
	
	// Override the default friction.
	fixtureDef.friction = 0.3f;
	
	// Add the shape to the body.
	body->CreateFixture(&fixtureDef);
	
	// Prepare for simulation. Typically we use a time step of 1/60 of a
	// second (60Hz) and 10 iterations. This provides a high quality simulation
	// in most game scenarios.
	float32 timeStep = 1.0f / 60.0f;
	int32 velocityIterations = 6;
	int32 positionIterations = 2;
	
	// This is our little game loop.
	for (int32 i = 0; i < 60; ++i)
	{
		// Instruct the world to perform a single step of simulation.
		// It is generally best to keep the time step and iterations fixed.
		world.Step(timeStep, velocityIterations, positionIterations);
		
		// Now print the position and angle of the body.
		b2Vec2 position = body->GetPosition();
		float32 angle = body->GetAngle();
		
		printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
	}
	
	while (device->run())
	{
		driver->beginScene(true, true, SColor(255, 255, 255, 255));
		driver->endScene();
		
		if(receiver.IsKeyDown(irr::KEY_ESCAPE)){
			break;
		}
	}
	
	device->drop();
	return 0;
}
