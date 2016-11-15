//
//  state.hpp
//  Sistema de Decision
//
//  Created by Gaspar Rodriguez Valero on 8/11/16.
//  Copyright © 2016 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Vstate_hpp
#define Vstate_hpp

#include <stdint.h>
#include <cstdlib>
#include <time.h>

using namespace std;

class Vstate{
public:
    Vstate();
    Vstate (bool miedo,bool cabreo,int tipo);
    int getLife() const {return _life;}
    int getThirst() const{return _thirst;}
    int getHungry() const{return _hungry;}
    void drink();
    void eat();
    void heal();
    int calculate();
    void  setNpcs(int value){_npcs=value;}
    void  updateVstate();
private:
    uint8_t _life;
    uint8_t _npcs;
    uint8_t _typeM;
    bool _fear;
    bool _anger;
    uint8_t _thirst;
    uint8_t _hungry;
    
};
#endif /* state_hpp */
