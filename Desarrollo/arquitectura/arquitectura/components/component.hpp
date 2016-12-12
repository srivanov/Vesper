
#ifndef component_hpp
#define component_hpp

#include <stdio.h>

class GameObject;

class component{
public:
	component();
	void setFather(GameObject* p);
	GameObject* getFather();
	~component();
protected:
	GameObject* padre;
};

#endif /* component_hpp */
