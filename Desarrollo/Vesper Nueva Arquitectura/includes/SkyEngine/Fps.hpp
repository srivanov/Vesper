
#ifndef Fps_hpp
#define Fps_hpp

#include "tiempo.h"

class Fps {
	
public:
	static Fps* Instance() { static Fps inst; return &inst; }
	
	// Update
	void update() {
		// increase the counter by one
		m_fpscount++;
		// one second elapsed? (= 1000 milliseconds)
		if (temp.tTranscurrido(1.0f))
			restart();
	}
	
	// Get fps
	unsigned int get() const { return m_fps; }
private:
	Fps() {
		m_fps = 0;
		m_fpscount = 0;
		temp.start();
	}
	
	void restart() {
		// save the current counter value to m_fps
		m_fps = m_fpscount;
		// reset the counter and the interval
		m_fpscount = 0;
		temp.reset();
	}
	
	tiempo temp;
	unsigned int m_fps;
	unsigned int m_fpscount;
};

#endif /* Fps_hpp */
