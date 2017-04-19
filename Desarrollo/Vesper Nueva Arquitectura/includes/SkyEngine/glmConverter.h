//
//  glmConverter.h
//  motor
//
//  Created by Stoycho Ivanov Atanasov on 2/4/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef glmConverter_h
#define glmConverter_h

#include "Dvector.hpp"
#include <glm/gtc/matrix_transform.hpp>

namespace glmConv {
	static glm::vec3 v3d2glm(const dvector3D &d) { return glm::vec3(d.x, d.y, d.z); }
	static glm::vec3 v3d2glm(const dvector3D *d) { return glm::vec3(d->x, d->y, d->z); }
}

#endif /* glmConverter_h */
