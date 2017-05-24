//
//  SkyWindow.cpp
//  motor
//
//  Created by Stoycho Ivanov Atanasov on 20/3/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "SkyWindow.hpp"

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

SkyWindow::SkyWindow(){
	i = InputManager::Instance();
}

int SkyWindow::crearWindow(dvector2D wh, bool vsync, bool fullscreen){
	glfwInit();
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	glfwWindowHint(GLFW_SAMPLES, 4);
	
	// creamos una ventana con glfw
    if(fullscreen)
        window = glfwCreateWindow(wh.x, wh.y, "TAGengine", glfwGetPrimaryMonitor(), nullptr);
    else
        window = glfwCreateWindow(wh.x, wh.y, "TAGengine", nullptr, nullptr);
	if (window == nullptr){
		std::cout << "Failed to create GLFW window" << std::endl;
//		glfwTerminate();
		return 0;
	}
	
	size = wh;
	
	//seleccionamos window para que se haga la gestion sobre esta ventana
	glfwMakeContextCurrent(window);
	
	//definimos la funcion que llamaremos cuando se pulse una tecla
	glfwSetKeyCallback(window, key_callback);
	
	
	//definimos la funcion que llamaremos cuando se mueva el raton
	glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);
	
	
	//definimos la funcion cuando hacemos scroll
	glfwSetScrollCallback(window, scroll_callback);
	
	
	// activamos esto para que GLEW pueda trabajar con punteros de forma moderna, algo asi
	glewExperimental = GL_TRUE;
	
	// inicializamos GLEW
	if (glewInit() != GLEW_OK){
		std::cout << "Failed to initialize GLEW" << std::endl;
		return -1;
	}
	
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);
	
	// activamos el Z-buffer
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glEnable(GL_MULTISAMPLE);
	
	toggleVSync(vsync);
	
	return 1;
}

void SkyWindow::beginDraw(){
	glfwMakeContextCurrent(window);
	// comprueba los eventos de entrada (teclado, raton...)
	glfwPollEvents();
	//limpia la pantalla asignando un color de fondo
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	//limpiamos el buffer de color y Z-buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void SkyWindow::endDraw(){
	// intercambiamos los buffers, sino no pinta NADA
	glfwSwapBuffers(window);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if(action != GLFW_RELEASE)
		InputManager::Instance()->keys[key] = true;
	else // GLFW_RELEASE
		InputManager::Instance()->keys[key] = false;
}
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods){
    if(action != GLFW_RELEASE)
        InputManager::Instance()->keys[button] = true;
    else // GLFW_RELEASE
        InputManager::Instance()->keys[button] = false;
    
}
void mouse_callback(GLFWwindow* window, double xpos, double ypos){
	//guardar la posicion en el inputManager
	int w,h;
	glfwGetWindowSize(window, &w, &h);
	InputManager::Instance()->mousePos = dvector2D(xpos-w*0.5,h*0.5-ypos);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset){
//	if(yoffset < 0)
//		printf("ABAJO ");
//	else if (yoffset > 0)
//		printf("ARRIBA ");
//	else
//		printf("___");
// NO SE EJECUTA SI NO HAY SCROLL, se descarta la opcion de guardar el scroll porque no se quitara nunca
}

