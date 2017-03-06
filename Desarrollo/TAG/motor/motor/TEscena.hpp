
#ifndef TEscena_hpp
#define TEscena_hpp

#include "TNodo.hpp"
#include "SkyEngine.hpp"
#include "ShaderManager.hpp"

// dimensiones de la ventana
const GLuint WIDTH = 800, HEIGHT = 600;

class TEscena {
public:
	TEscena();
	~TEscena();
	void Draw();
	void cambiar(glm::vec3 mov);
//	
//	TNodo* getActiveCamera();
private:
	SkyEngine motor;
//	TNodo *root, *uno, *dos, *tres, *cuarto, *quinto, *sexto, *septimo;
//	TGestorRecursos* gestor;
//	TMalla t, t2;
//	TTransform tr, tr2, trCam, troot;
//	TCamara cam;
//	TLuz luz;
};

#endif /* TEscena_hpp */
