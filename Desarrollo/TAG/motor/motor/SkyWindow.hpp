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
#include "Dvector.hpp"
#include "InputManager.h"

class SkyWindow {
public:
	static SkyWindow* Instance(){ static SkyWindow pinstance; return &pinstance; }
	int crearWindow(dvector2D wh = dvector2D(800,600), bool vsync = true, bool fullscreen = false);
	bool isRunning() { return !glfwWindowShouldClose(window); }
	void beginDraw();
	void endDraw();
	// terminamos con GLFW y borramos todos los recursos asociados a el
	void terminate() { glfwTerminate(); }
	void toggleVSync(bool t) { glfwSwapInterval(t); }
	const dvector2D* getSIZE() { return &size; }
	void resetViewport() { glViewport(0,0, width, height); }
	void ocultarRaton(bool p) {
		if(p) //ocultamos el raton en la aplicacion
			glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		else
			glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	}
	void setWindowTitle(char* c) { glfwSetWindowTitle(window, c); }
	void activateClipping(bool p);
	bool getClippingState();
private:
	SkyWindow();
	GLFWwindow* window;
	dvector2D size;
	// definimos el viewport, sera el area en el que dibujamos
	int width, height;
	InputManager* i;
};

#endif /* SkyWindow_hpp */
