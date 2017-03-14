
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
	void mover(glm::vec3 mov);
	void girar(glm::vec3 mov);
	void imprime();
		
//	TNodo* getActiveCamera();
private:
	SkyEngine motor;
	SkyCamara* cam;
	SkyMalla* cubo, *cubo2;
//	TNodo *root, *uno, *dos, *tres, *cuarto, *quinto, *sexto, *septimo;
//	TGestorRecursos* gestor;
//	TMalla t, t2;
//	TTransform tr, tr2, trCam, troot;
//	TCamara cam;
//	TLuz luz;
};

#endif /* TEscena_hpp */
