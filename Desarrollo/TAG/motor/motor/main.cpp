
#include "stateMachine.hpp"
#include "SkyWindow.hpp"

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
	window->crearWindow(wh,true);
	
	stateMachine machine;
	machine.Init();
	GLuint modelLoc, viewLoc, projectionLoc;
	
	// Bucle principal
	while (window->isRunning())
	{

		machine.update();
		
		window->beginDraw();
			machine.render();
		window->endDraw();
		
		if(InputManager::Instance()->isPressed(SKY_KEY_9))
			states::Instance()->nextState = PLAYING;
		if(InputManager::Instance()->isPressed(SKY_KEY_8))
			states::Instance()->nextState = MENU;
	}
	window->terminate();
	return 0;
}

