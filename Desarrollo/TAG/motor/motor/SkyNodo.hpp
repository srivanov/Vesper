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
	virtual void rotar(dvector3D &vector) { Trans[0]->rotar(vector); }
	virtual void escalar(dvector3D &vector) { Trans[1]->escalar(vector); }
	
	virtual void transladar(dvector3D &vector) {
		Trans[2]->trasladar(vector);
		posicion += vector;
	}
	virtual void setPosicion(dvector3D &vector) {
		Trans[2]->setPosicion(vector);
		posicion = vector;
	}
	
	virtual void setRotacion(dvector3D &vector) {
		Trans[0]->setRotacion(vector);
		rotacion = vector;
	}
	
	virtual dvector3D* getPosicion() { return &posicion; }
	virtual dvector3D* getRotacion() { return &rotacion; }
	
	virtual ~SkyNodo() { if(TransNodos[2]) delete TransNodos[2]; }
	
	//************METODOS DEBUG************
	virtual void imprimePos(){ printf("%.1f %.1f %.1f\n", posicion.x, posicion.y, posicion.z); }
	
protected:
	/*	
	 	2 - Rotar
		1 - Escalar
		0 - Trasladar
	 */
	TTransform *Trans[3];
	TNodo *TransNodos[3], *nodo;
	dvector3D posicion, rotacion;
	
	void buildTransform(){
		for (int i=0; i<3; i++) {
			TransNodos[i] = new TNodo;
			Trans[i] = new TTransform;
			TransNodos[i]->setEntidad(Trans[i]);
			if(i==0) continue;
			TransNodos[i]->addHijo(TransNodos[i-1]);
		}
	}
	
	void buildTransformStatic(){
		TransNodos[0] = new TNodo;
		Trans[0] = new TTransform;
		TransNodos[0]->setEntidad(Trans[0]);
		TransNodos[1] = TransNodos[2] = TransNodos[0];
		Trans[1] = Trans[2] = Trans[0];
	}
	
	
};

#endif /* SkyNodo_hpp */
