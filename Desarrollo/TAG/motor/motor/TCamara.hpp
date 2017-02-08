//
//  TCamara.hpp
//  motor
//
//  Created by Stoycho Ivanov Atanasov on 7/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef TCamara_hpp
#define TCamara_hpp

#include <stdio.h>
#include "TEntidad.hpp"

class TCamara : public TEntidad{
public:
	TCamara();
	~TCamara();
	void setPerspectiva();
	void setParalela();
	void setNearValue(float n);
	void setFarValue(float f);
	
	void beginDraw();
	void endDraw();
private:
	bool esPerspectiva;
	float nearV, farV;
};

#endif /* TCamara_hpp */
