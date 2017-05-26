
#include "TEscena.hpp"
#include "SkyWindow.hpp"
#include <iostream>

//// dimensiones de la ventana
//const GLuint WIDTH = 800, HEIGHT = 600;

//ultima posicion del raton, inicializada al centro de la pantalla
GLfloat lastX = WIDTH/2, lastY = HEIGHT/2;

//camera camara(glm::vec3(0.0f, 0.0f, 3.0f));

//primer movimiento del raton
bool firstMouse = true;

//array con las teclas
bool keys[1024];

//movimiento de la camara
glm::vec3 mov_cursor;

int main(int argc, const char * argv[]) {
	SkyWindow* window = SkyWindow::Instance();
	dvector2D wh(800,600);

//	int n=0;
//	bool vsync = true, fullscreen = false;
//	std::cout << "Sincronizacion vertical: 0 o 1";
//	std::cin >> n;
//	if(n == 0)
//		vsync = false;
//	
//	std::cout << "Fullscreen: 0 o 1";
//	std::cin >> n;
//	if(n != 0)
//		fullscreen = true;
	
	window->crearWindow(wh, true);
	
	TEscena escena;
	
	GLuint modelLoc, viewLoc, projectionLoc;
	
	// Bucle principal
	while (window->isRunning())
	{
		window->beginDraw();

		mov_cursor = glm::vec3();
		escena.update();
		escena.Draw();
		
		window->endDraw();
	}
	window->terminate();
	return 0;
}

