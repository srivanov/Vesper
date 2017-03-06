//
//  SkyNodo.hpp
//  motor
//
//  Created by Stoycho Ivanov Atanasov on 5/3/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef SkyNodo_hpp
#define SkyNodo_hpp

#include "TNodo.hpp"
#include "TTransform.hpp"
#include "Dvector.hpp"


class SkyNodo {
public:
	virtual void rotar(dvector3D* vector) { Trans[2]->rotar(glmConverter(vector)); }
	virtual void escalar(dvector3D* vector) { Trans[1]->escalar(glmConverter(vector)); }
	virtual void transladar(dvector3D* vector) { Trans[0]->trasladar(glmConverter(vector)); }
	virtual void setPosicion(dvector3D* vector) { Trans[0]->setPosicion(glmConverter(vector)); }
	virtual ~SkyNodo() { if(TransNodos[2]) delete TransNodos[2]; }
	
protected:
	/*	
	 	2 - Rotar
		1 - Escalar
		0 - Trasladar
	 */
	TTransform *Trans[3];
	TNodo *TransNodos[3], *nodo;
	
	void builTransform(){
		for (int i=0; i<3; i++) {
			TransNodos[i] = new TNodo;
			Trans[i] = new TTransform;
			TransNodos[i]->setEntidad(Trans[i]);
			if(i==0) continue;
			TransNodos[i]->addHijo(TransNodos[i-1]);
		}
	}
	
	virtual glm::vec3 glmConverter(const dvector3D &d) { return glm::vec3(d.x, d.y, d.z); }
	virtual glm::vec3 glmConverter(const dvector3D *d) { return glm::vec3(d->x, d->y, d->z); }
};

#endif /* SkyNodo_hpp */
