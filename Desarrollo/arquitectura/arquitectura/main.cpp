//
//  main.cpp
//  arquitectura
//
//  Created by Stoycho Ivanov Atanasov on 29/11/16.
//  Copyright © 2016 Stoycho Ivanov Atanasov. All rights reserved.
//

#include <iostream>
#include "GameObject.hpp"
#include "components/ataque.hpp"
#include "player.hpp"

int main(int argc, const char * argv[]) {
	// insert code here...
	std::cout << "Hello, World!\n";
	GameObject *i = new GameObject();

    i->insertComponent((char*)"ataque", *new ataque());
	printf("%d\n",i->findComponent((char*)"ataque"));
	
    return 0;
}
