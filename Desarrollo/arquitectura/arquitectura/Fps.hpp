
#ifndef Fps_hpp
#define Fps_hpp

//#include <stdio.h>
#include <time.h>
#include <stdlib.h>

class Fps
{
protected:
	time_t begin_time = time(NULL);
	unsigned int m_fps;
	unsigned int m_fpscount;

	
public:
	// Constructor
	Fps() : m_fps(0), m_fpscount(0)
	{
	}
	
	// Update
	void update()
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
			
		}
	}
	
	// Get fps
	int get() const
	{
		printf("%d",m_fps);
		return 1;
	}
};

#endif /* Fps_hpp */
