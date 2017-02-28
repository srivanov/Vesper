
#ifndef TEscena_hpp
#define TEscena_hpp

#include "TNodo.hpp"
#include "TMalla.hpp"
#include "TTransform.hpp"
#include "TCamara.hpp"
#include "TLuz.hpp"

// dimensiones de la ventana
const GLuint WIDTH = 800, HEIGHT = 600;

class TEscena {
public:
	TEscena(Shader &shader);
	~TEscena();
	void Draw();
	void cambiar(glm::vec3 mov);
	
	TNodo* getActiveCamera();
private:
	TNodo *root, *uno, *dos, *tres, *cuarto, *quinto, *sexto, *septimo;
	TGestorRecursos* gestor;
	TMalla t, t2;
	TTransform tr, tr2, trCam;
	TCamara cam;
	TLuz luz;
};

#endif /* TEscena_hpp */
