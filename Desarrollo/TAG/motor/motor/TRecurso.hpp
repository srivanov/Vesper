//
//  TRecurso.hpp
//  motor
//
//  Created by Stoycho Ivanov Atanasov on 15/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef TRecurso_hpp
#define TRecurso_hpp

#include <GL/glew.h>

class TRecurso{
public:
	TRecurso();
	~TRecurso();
	GLchar* GetNombre(){ return nombre; }
	void SetNombre(GLchar* n){ nombre = n; }
	
private:
	GLchar* nombre;
};

#endif /* TRecurso_hpp */
