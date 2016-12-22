
#ifndef Fps_hpp
#define Fps_hpp

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

class Fps {
	
public:
	static Fps* Instance();
	
	// Update
	void update();
	
	// Get fps
	unsigned int get() const;
	
protected:
	time_t begin_time;
	unsigned int m_fps;
	unsigned int m_fpscount;
	
	Fps();
	
private:
	static Fps* pinstance;
};

#endif /* Fps_hpp */
