
#ifndef TEscena_hpp
#define TEscena_hpp

#include "TNodo.hpp"
#include "TMalla.hpp"
#include "TTransform.hpp"

class TEscena {
public:
	TEscena(Shader &shader);
	~TEscena();
	void Draw();
	void cambiar(glm::vec3 mov);
	
private:
	TNodo *root, *uno, *dos, *tres, *cuarto;
	TGestorRecursos* gestor;
	TMalla t, t2;
	TTransform tr, tr2;
};

#endif /* TEscena_hpp */
