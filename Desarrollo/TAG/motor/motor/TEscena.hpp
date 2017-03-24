
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
	void update();
	void girar(glm::vec3 mov);
	void imprime();
		
//	TNodo* getActiveCamera();
private:
	SkyEngine motor;
	SkyCamara* cam;
	SkyMalla* cubo, *cubo2;
};

#endif /* TEscena_hpp */
