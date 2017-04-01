//
//  Pila.hpp
//  motor
//
//  Created by Stoycho Ivanov Atanasov on 17/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Pila_h
#define Pila_h

#include <stack>
#include <glm/glm.hpp>

class Pila{
public:
	static Pila* Instance(){
		static Pila pinstance;
		return &pinstance;
	}
	virtual ~Pila(){}
	
	void push(glm::mat4 &m){
		pila.push(m);
	}
	
	glm::mat4* pop(){
		glm::mat4* p = &pila.top();
		pila.pop();
		return p;
	}
	
	glm::mat4* top(){
		return &pila.top();
	}
	
	void calculaMVP(){
		MVP = mProjection * mView * actual;
	}
	
	glm::mat4 actual, mView, mProjection, MVP;
protected:
	Pila(){}
private:
	std::stack<glm::mat4> pila;
};

#endif /* Pila_h */
