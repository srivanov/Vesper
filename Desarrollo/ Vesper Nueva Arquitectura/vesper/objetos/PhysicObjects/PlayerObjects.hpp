//
//  Weapon.hpp
//  Arquitectura
//
//  Created by Gaspar Rodriguez Valero on 16/3/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#ifndef PlayerObjects_hpp
#define PlayerObjects_hpp

#include "PhysicObject.hpp"

class PlayerObjects : public PhysicObject {
public:
    PlayerObjects();
    ~PlayerObjects();
    void contacto(PhysicObject *);
    void contactoEnd(PhysicObject *);
    void inicializar(int& ID);
};

#endif /* Weapon_hpp */


/*
 
 obj_mapping mapping[] = {
 
 {	1		,	""					,		0		},
 {	3		,	"3d/moneda.jpg"		,	accion3		},
 {	4		,	"3d/texture.png"	,	accion4		},
 {	5		,	"3d/pala.jpg"		,	accion5		},
 {	6		,	"3d/piedra.jpg"		,	accion6		},
 {	7		,	"3d/naranja.jpg"	,	accion7		},
 {	8		,	"3d/llave.jpg"		,	accion8		},
 {	9		,	"3d/fuenten.jpg"	,	accion9		},
 {	10		,	"3d/botiquin.jpg"	,	accion10	},
 {	11		,	"3d/puerta.jpg"		,	accion11	},
 {	12		,	"3d/pizza.jpg"		,	accion12	},
 {	13		,	""					,		0		},
 {	14		,	"3d/rehen.jpg"		,	accion21	},
 {	15 		,	"3d/letraE.png"		,	accion15	},
 {	16 		,	"3d/letraL.png"		,	accion16	},
 {	17 		,	"3d/globoagua.png"	,	accion17	},
 {	18 		,	"3d/chicle.png"		,	accion18	},
 {	19 		,	"3d/bombahumo.png"	,	accion19	},
 {	20 		,	""                  ,       0       },
 {	0		,	""					,		0		}
 */
