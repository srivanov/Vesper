//
//  TRecurso.hpp
//  motor
//
//  Created by Stoycho Ivanov Atanasov on 15/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef TRecurso_hpp
#define TRecurso_hpp

#include <string>

enum typeRecurso{
	tNO_TYPE = -1,
	tRMalla,
	tRTextura
};

class TRecurso{
public:
	TRecurso(){}
	virtual ~TRecurso(){}
	std::string GetNombre(){ return nombre; }
	void SetNombre(std::string n){ nombre = n; }
	virtual void cargarFichero(std::string name)=0;
	void setType(typeRecurso t){type = t;}
	typeRecurso getType(){return type;}
private:
	std::string nombre;
	typeRecurso type;
};

#endif /* TRecurso_hpp */
