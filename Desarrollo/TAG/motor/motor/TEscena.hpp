
#ifndef TEscena_hpp
#define TEscena_hpp

#include <stack>
#include <glm/glm.hpp>

#include "TNodo.hpp"
#include "TMalla.hpp"

class TEscena {
public:
	TEscena(Shader &shader);
	~TEscena();
	void Draw();
	
	std::stack<glm::mat4> pila;
private:
	TNodo *root, *uno, *dos;
	TMalla t;
};

#endif /* TEscena_hpp */
