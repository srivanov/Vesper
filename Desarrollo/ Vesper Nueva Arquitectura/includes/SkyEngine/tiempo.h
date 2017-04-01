
#ifdef __APPLE__

#ifndef tiempo_h
#define tiempo_h

#include <sys/time.h>

#define MILLON	1000000L
#define MILI	1000L

struct tiempo {
	
	long start(){ gettimeofday(&st, NULL); return (st.tv_sec*MILLON + st.tv_usec)/MILI; }
	
	bool tTranscurrido(float sec) {
		long diff = difference(), s = (long)(sec * MILLON);
		if(diff >= s)
			return true;
		return false;
	}
	
	long getTiempo() {
		return difference()/MILI;
	}
	
	long getActual() { gettimeofday(&actual, NULL); return (actual.tv_sec*MILLON + actual.tv_usec)/MILI; }
	
	void reset(){ start(); }
private:
	long difference(){
		gettimeofday(&fn, NULL);
		return (fn.tv_sec * MILLON + fn.tv_usec)-(st.tv_sec * MILLON + st.tv_usec);
	}
	
	struct timeval st, fn, actual;
};

#endif /* tiempo_h */

#else
//#ifdef __MINGW32__ || __MINGW64__

#ifndef tiempo_h
#define tiempo_h

#include <windows.h>

#define MILLON	1000000L
#define MILI	1000L

struct tiempo {
	
	long start(){
		GetSystemTime(&st);
		return (st.wSecond*MILi + st.wMiliseconds);
	}
	
	bool tTranscurrido(float sec) {
		long diff = difference();
		if(diff >= ((long)sec * MILI))
			return true;
		return false;
	}
	
	long getTiempo() { return difference(); }
	
	long getActual() { GetSystemTime(&actual); return (actual.tv_sec*MILI + actual.wMilliseconds); }
	
	void reset(){ start(); }
private:
	long difference(){
		GetSystemTime(&fn);
		return ((LONG)fn.wSecond * MILI + (LONG)fn.wMilliseconds)-((LONG)st.wSecond * MILI + (LONG)st.wMilliseconds);
		return 0;
	}
	
	SYSTEMTIME st, fn, actual;
};

#endif /* tiempo_h */

#endif
