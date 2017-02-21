//
//  NodoCurarse.hpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef NodoCurarse_hpp
#define NodoCurarse_hpp

#include "Nodo.hpp"


class NodoCurarse : public Nodo {
public:
    ~NodoCurarse();
    NodoCurarse();
    short run(int &id);
    void reset(){}
private:
};
#endif /* NodoCurarse_hpp */
