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

SkyWindow::SkyWindow(){
	i = InputManager::Instance();
}

int SkyWindow::crearWindow(dvector2D wh, bool vsync){
	glfwInit();
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	
	// creamos una ventana con glfw
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
	
	/*
	//definimos la funcion cuando hacemos scroll
	glfwSetScrollCallback(window, scroll_callback);
	*/
	
	//ocultamos el raton en la aplicacion
//	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	
	// activamos esto para que GLEW pueda trabajar con punteros de forma moderna, algo asi
	glewExperimental = GL_TRUE;
	
	// inicializamos GLEW
	if (glewInit() != GLEW_OK){
		std::cout << "Failed to initialize GLEW" << std::endl;
		return -1;
	}
	
	// definimos el viewport, sera el area en el que dibujamos
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);
	
	// activamos el Z-buffer
	glEnable(GL_DEPTH_TEST);
	
	toggleVSync(vsync);
	
	return 1;
}

void SkyWindow::beginDraw(){
	// comprueba los eventos de entrada (teclado, raton...)
	glfwPollEvents();
	//limpia la pantalla asignando un color de fondo
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	//limpiamos el buffer de color y Z-buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	Fps::Instance()->update();
}

void SkyWindow::endDraw(){
	char c[5];
	sprintf(c, "%d",Fps::Instance()->get());
	glfwSetWindowTitle(window, c);
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

void mouse_callback(GLFWwindow* window, double xpos, double ypos){
	
//	//inicialmente es TRUE
//	if(firstMouse){
//		lastX = xpos;
//		lastY = ypos;
//		firstMouse = false;
//	}
//	
//	GLfloat xoffset = xpos - lastX;
//	
//	//le damos la vuelta ya que el eje Y empieza desde abajo
//	GLfloat yoffset = lastY - ypos;
//	lastX = xpos;
//	lastY = ypos;
//	mov_cursor = glm::vec3(yoffset, xoffset, 0);

	//guardar la posicion en el inputManager
	InputManager::Instance()->mousePos = dvector2D(xpos,ypos);
}

