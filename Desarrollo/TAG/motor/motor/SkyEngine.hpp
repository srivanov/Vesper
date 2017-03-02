//
//  SkyEngine.hpp
//  motor
//
//  Created by Stoycho Ivanov Atanasov on 2/3/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef SkyEngine_hpp
#define SkyEngine_hpp

#include "TNodo.hpp"
#include "TMalla.hpp"
#include "TTransform.hpp"
#include "TCamara.hpp"
#include "TLuz.hpp"

struct dvector3D{
	float x;
	float y;
	float z;
};

class SkyEngine {
public:
	SkyEngine(){ root = new TNodo(); }
	~SkyEngine();
	TNodo* crearMalla(TNodo* padre);
	TNodo* crearCamara(TNodo* padre);
	TNodo* crearLuz(TNodo* padre);
	void Draw();
private:
	TNodo* root;
	TNodo* crearRama(TNodo* padre, TEntidad* ent);
};

class SkyNodo {
protected:
	/*	0 - Trasladar
		1 - Escalar
	 	2 - Rotar
	 */
	TTransform *Trans[3];
	TNodo *TransNodos[3];
	virtual void builTransform();
	virtual glm::vec3 glmConverter(const dvector3D &d) { return glm::vec3(d.x, d.y, d.z); }
	virtual glm::vec3 glmConverter(const dvector3D *d) { return glm::vec3(d->x, d->y, d->z); }
public:
	virtual void rotar(dvector3D* vector) { Trans[2]->rotar(glmConverter(vector)); }
	virtual void escalar(dvector3D* vector) { Trans[1]->escalar(glmConverter(vector)); }
	virtual void transladar(dvector3D* vector) { Trans[0]->trasladar(glmConverter(vector)); }
};
#endif /* SkyEngine_hpp */
