//
//  SkyWindow.cpp
//  motor
//
//  Created by Stoycho Ivanov Atanasov on 20/3/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "SkyWindow.hpp"
#include "Dvector.hpp"
const GLuint WIDTH = 800, HEIGHT = 600;
SkyWindow::SkyWindow(){
	
}

int SkyWindow::crearWindow(dvector2D &wh){
	glfwInit();
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	
	// creamos una ventana con glfw
	window = glfwCreateWindow(WIDTH, HEIGHT, "TAGengine", nullptr, nullptr);
	if (window == nullptr){
		std::cout << "Failed to create GLFW window" << std::endl;
//		glfwTerminate();
		return 0;
	}
	
	//seleccionamos window para que se haga la gestion sobre esta ventana
	glfwMakeContextCurrent(window);
	
	//ocultamos el raton en la aplicacion y capturamos su posicion
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
	
//	glfwSwapInterval(0);
	
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



