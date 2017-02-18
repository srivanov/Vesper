//
//  TRecursoMalla.hpp
//  motor
//
//  Created by Stoycho Ivanov Atanasov on 18/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef TRecursoMalla_hpp
#define TRecursoMalla_hpp

#include "TRecurso.hpp"
#include "Mesh.hpp"

class TRecursoMalla : public TRecurso{
public:
	TRecursoMalla();
	~TRecursoMalla();
	void cargarFichero(char* name);
	void Draw();
private:
	std::vector<Mesh> meshes;
	
};

#endif /* TRecursoMalla_hpp */
