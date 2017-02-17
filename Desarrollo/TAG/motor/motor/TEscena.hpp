
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
	
private:
	TNodo *root, *uno, *dos, *tres;
	TMalla t;
	TTransform tr, tr2;
};

#endif /* TEscena_hpp */
