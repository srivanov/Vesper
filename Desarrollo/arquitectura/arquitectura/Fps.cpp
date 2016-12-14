
#include "Fps.hpp"

Fps* Fps::pinstance = 0;

Fps* Fps::Instance()
{
	if(pinstance == 0)
		pinstance = new Fps();
	return pinstance;
}

// Constructor
Fps::Fps(){
	m_fps = 0;
	m_fpscount = 0;
	begin_time = time(NULL);
}

Fps::~Fps() {
	delete pinstance;
}

// Update
void Fps::update()
{
	// increase the counter by one
	m_fpscount++;
	
	// one second elapsed? (= 1000 milliseconds)
	if (difftime(time(NULL), begin_time) >= 1.0)
	{
		// save the current counter value to m_fps
		m_fps         = m_fpscount;
		
		// reset the counter and the interval
		m_fpscount    = 0;
		begin_time = time(NULL);
	}
}

// Get fps
unsigned int Fps::get() const
{
	return m_fps;
}
