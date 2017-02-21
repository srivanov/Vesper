//
//  TRecursoTextura.hpp
//  motor
//
//  Created by Stoycho Ivanov Atanasov on 21/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef TRecursoTextura_hpp
#define TRecursoTextura_hpp

#include <assimp/scene.h>
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <SOIL/SOIL.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "TRecurso.hpp"
//#include "Mesh.hpp"

class TRecursoTextura : public TRecurso{
public:
	TRecursoTextura();
	~TRecursoTextura();
	void cargarFichero(std::string name);
private:
	
};

#endif /* TRecursoTextura_hpp */
