
#ifdef __APPLE__

#ifndef tiempo_h
#define tiempo_h

#include <sys/time.h>

#define MILLON 1000000L

struct tiempo {
	
	float start(){ gettimeofday(&st, NULL); return ((float)st.tv_usec/(float)MILLON); }
	
	bool tTranscurrido(float sec) {
		long diff = difference(), s = (long)(sec * MILLON);
		if(diff >= s)
			return true;
		return false;
	}
	
	float getTiempo() {
		return ((float)difference() / (float)MILLON);
	}
	
	void reset(){ start(); }
private:
	long difference(){
		gettimeofday(&fn, NULL);
		return (fn.tv_sec * MILLON + fn.tv_usec)-(st.tv_sec * MILLON + st.tv_usec);
	}
	
	struct timeval st, fn;
};

#endif /* tiempo_h */

#else
//#ifdef __MINGW32__ || __MINGW64__

#ifndef tiempo_h
#define tiempo_h

#include <windows.h>

#define MILLON 1000000L

struct tiempo {
	
	float start(){
		GetSystemTime(&st);
		return ((float)st.wSecond/(float)MILLON);
	}
	
	bool tTranscurrido(float sec) {
		long diff = difference();
		if(diff >= ((long)sec * MILLON))
			return true;
		return false;
	}
	
	float getTiempo() { return ((float)difference() / (float)MILLON); }
	
	void reset(){ start(); }
private:
	long difference(){
		GetSystemTime(&fn);
		return ((LONG)fn.wSecond * MILLON + (LONG)fn.wMilliseconds)-((LONG)st.wSecond * MILLON + (LONG)st.wMilliseconds);
		return 0;
	}
	
	SYSTEMTIME st, fn;
};

#endif /* tiempo_h */

#endif
