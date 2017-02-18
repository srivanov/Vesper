//
//  TRecurso.hpp
//  motor
//
//  Created by Stoycho Ivanov Atanasov on 15/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef TRecurso_hpp
#define TRecurso_hpp

class TRecurso{
public:
	TRecurso(){}
	virtual ~TRecurso(){}
	char* GetNombre(){ return nombre; }
	void SetNombre(char* n){ nombre = n; }
	virtual void cargarFichero(char* name){}
private:
	char* nombre;
};

#endif /* TRecurso_hpp */
