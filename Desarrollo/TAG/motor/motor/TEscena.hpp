
#ifndef TEscena_hpp
#define TEscena_hpp

#include <stack>
#include <glm/glm.hpp>

#include "TNodo.hpp"
#include "TMalla.hpp"

class TEscena {
public:
	TEscena();
	~TEscena();
	
	std::stack<glm::mat4> pila;
private:
	TNodo *root, *uno, *dos;
	
};

#endif /* TEscena_hpp */
