//
//  SkyWindow.hpp
//  motor
//
//  Created by Stoycho Ivanov Atanasov on 20/3/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef SkyWindow_hpp
#define SkyWindow_hpp

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Fps.hpp"

class dvector2D;

class SkyWindow {
public:
	static SkyWindow* Instance(){ static SkyWindow pinstance; return &pinstance; }
	int crearWindow(dvector2D &wh);
	bool isRunning() { return !glfwWindowShouldClose(window); }
	void beginDraw();
	void endDraw();
	void terminate() { // terminamos con GLFW y borramos todos los recursos asociados a el
		glfwTerminate(); }
private:
	SkyWindow();
	GLFWwindow* window;
};

#endif /* SkyWindow_hpp */
