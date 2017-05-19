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
#include "Dvector.hpp"
#include "InputManager.h"

class SkyWindow {
public:
	static SkyWindow* Instance(){ static SkyWindow pinstance; return &pinstance; }
	int crearWindow(dvector2D wh = dvector2D(800,600), bool vsync = true);
	bool isRunning() { return !glfwWindowShouldClose(window); }
	void beginDraw();
	void endDraw();
	// terminamos con GLFW y borramos todos los recursos asociados a el
	void terminate() { glfwTerminate(); }
	void toggleVSync(bool t) { glfwSwapInterval(t); }
	const dvector2D* getSIZE() { return &size; }
	void resetViewport() { glViewport(0,0, width, height); }
private:
	SkyWindow();
	GLFWwindow* window;
	dvector2D size;
	// definimos el viewport, sera el area en el que dibujamos
	int width, height;
	InputManager* i;
};

#endif /* SkyWindow_hpp */
