
#define GLEW_STATIC
#include <GL/glew.h>
#include <iostream>
#include <math.h>
//libreria para leer imagenes
#include <SOIL/SOIL.h>
#include <GLFW/glfw3.h>
//libreria para trabajar con matrices
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Shader.h"
//#include "camera.hpp"
//#include "TModelo.hpp"
#include "TEscena.hpp"

//// dimensiones de la ventana
//const GLuint WIDTH = 800, HEIGHT = 600;

//ultima posicion del raton, inicializada al centro de la pantalla
GLfloat lastX = WIDTH/2, lastY = HEIGHT/2;

//camera camara(glm::vec3(0.0f, 0.0f, 3.0f));

//primer movimiento del raton
bool firstMouse = true;

//array con las teclas
bool keys[1024];

// Time between current frame and last frame
GLfloat deltaTime = 0.0f;

// Time of last frame
GLfloat lastFrame = 0.0f;

//movimiento de la camara
glm::vec3 mov_cursor;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if(action == GLFW_PRESS)
		keys[key] = true;
	else if(action == GLFW_RELEASE)
		keys[key] = false;
	
	// detectamos la pulsacion de la tecla ESCAPE
	if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		// hacemos que se salga del bucle
		glfwSetWindowShouldClose(window, GL_TRUE);
	
	if(key == GLFW_KEY_G && action == GLFW_PRESS)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	
	if(key == GLFW_KEY_H && action == GLFW_PRESS)
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void movimiento(TEscena* escena){
//	if(keys[GLFW_KEY_W])
//		camara.ProcessKeyboard(FORWARD, deltaTime);
//	if(keys[GLFW_KEY_S])
//		camara.ProcessKeyboard(BACKWARD, deltaTime);
//	if(keys[GLFW_KEY_A])
//		camara.ProcessKeyboard(LEFT, deltaTime);
//	if(keys[GLFW_KEY_D])
//		camara.ProcessKeyboard(RIGHT, deltaTime);
	
	glm::vec3 mov;
	
	if (keys[GLFW_KEY_UP])
		mov.z = -0.2f;
	if (keys[GLFW_KEY_DOWN])
		mov.z = 0.2f;
	if (keys[GLFW_KEY_RIGHT])
		mov.x = 0.2f;
	if (keys[GLFW_KEY_LEFT])
		mov.x = -0.2f;
	
	escena->mover(mov);
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos){
	
	//inicialmente es TRUE
	if(firstMouse){
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}
	
	GLfloat xoffset = xpos - lastX;
	
	//le damos la vuelta ya que el eje Y empieza desde abajo
	GLfloat yoffset = lastY - ypos;
	lastX = xpos;
	lastY = ypos;
	mov_cursor = glm::vec3(yoffset, xoffset, 0);
//	camara.ProcessMouseMovement(xoffset, yoffset);
//	escena.girar(m);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset){
//	camara.ProcessMouseScroll(yoffset);
}

int main(int argc, const char * argv[]) {

	glfwInit();
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	
	// creamos una ventana con glfw
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "TAGengine", nullptr, nullptr);
	if (window == nullptr){
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	
	//seleccionamos window para que se haga la gestion sobre esta ventana
	glfwMakeContextCurrent(window);
	
	//definimos la funcion que llamaremos cuando se pulse una tecla
	glfwSetKeyCallback(window, key_callback);
	
	//definimos la funcion que llamaremos cuando se mueva el raton
	glfwSetCursorPosCallback(window, mouse_callback);
	
	//definimos la funcion cuando hacemos scroll
	glfwSetScrollCallback(window, scroll_callback);
	
	//ocultamos el raton en la aplicacion y capturamos su posicion
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	
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
	
	//creamos la clase Shader y compilamos los shaders
	Shader miShader("../Shaders/texLight.vs", "../Shaders/texLight.frag");
	
//	TModelo modelo("../Models/microwave.obj");
//	modelo.imprimirDatos();
//	modelo.setTexture("../Textures/awesomeface.png");
//	modelo.setRotation(glm::vec3(0.0f, 0.0f, 0.0f));
//	modelo.setRotation(glm::vec3(90.0f, 90.0f, 0.0f));
//	TModelo modelo2("../Models/cube.obj");
//	modelo2.imprimirDatos();
//
//	TModelo modelo3("../Models/nanosuit/nanosuit.obj");
//	modelo3.imprimirDatos();
	
	TEscena escena;
	
	GLuint modelLoc, viewLoc, projectionLoc;
	
	// Bucle principal
	while (!glfwWindowShouldClose(window))
	{
		GLfloat currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
		
		// comprueba los eventos de entrada (teclado, raton...)
		glfwPollEvents();
		
		//funcion de movimiento
		movimiento(&escena);
		
		//limpia la pantalla asignando un color de fondo
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		//limpiamos el buffer de color y Z-buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
//		//activamos el programa para renderizar
//		glUseProgram(shaderProgram);
		miShader.Use();
		
//		glActiveTexture(GL_TEXTURE0);
//		
//		//linkamos la textura para dibujarla
//		glBindTexture(GL_TEXTURE_2D, texture1);
//		
//		// asignamos al uniform ourTexture1 el sampler2D
//		glUniform1i(glGetUniformLocation(miShader.Program, "ourTexture1"), 0);
//		
//		//hacemos lo mismo con la textura2
//		glActiveTexture(GL_TEXTURE1);
//		glBindTexture(GL_TEXTURE_2D, texture2);
//		glUniform1i(glGetUniformLocation(miShader.Program, "ourTexture2"), 1);
//		
//		//model matrix
//		glm::mat4 model;
//		model = glm::rotate(model, (GLfloat)glfwGetTime() * 1.0f, glm::vec3(0.5f, 1.0f, 0.0f));
//		
//		//rotando la camara en un radio
//		GLfloat radius = 10.0f;
//		GLfloat camX = sin(glfwGetTime()) * radius;
//		GLfloat camZ = cos(glfwGetTime()) * radius;
		
		
		/*_______________________________________
		GLint lightPosLoc = glGetUniformLocation(miShader.Program, "light.position");
		GLint viewPosLoc  = glGetUniformLocation(miShader.Program, "viewPos");
		glUniform3f(lightPosLoc, 3.0f, 2.0f, 3.0f);
//		glUniform3f(viewPosLoc,  camara.Position.x, camara.Position.y, camara.Position.z);
		
		//propiedades de la luz
		glUniform3f(glGetUniformLocation(miShader.Program, "light.ambient"),   0.5f, 0.5f, 0.5f);
		glUniform3f(glGetUniformLocation(miShader.Program, "light.diffuse"),   1.5f, 1.5f, 1.5f);
		glUniform3f(glGetUniformLocation(miShader.Program, "light.specular"),  4.0f, 4.0f, 4.0f);
		glUniform1f(glGetUniformLocation(miShader.Program, "light.constant"),  1.0f);
		glUniform1f(glGetUniformLocation(miShader.Program, "light.linear"),    0.09);
		glUniform1f(glGetUniformLocation(miShader.Program, "light.quadratic"), 0.032);
		
		__________________________________________*/
		/*
		// luz 2
		GLint lightPosLoc2 = glGetUniformLocation(miShader.Program, "light2.position");
		glUniform3f(lightPosLoc2, -5.0f, 5.0f, -3.0f);
		
		// propiedades de la luz
		glUniform3f(glGetUniformLocation(miShader.Program, "light2.ambient"),   0.2f, 0.2f, 0.2f);
		glUniform3f(glGetUniformLocation(miShader.Program, "light2.diffuse"),   1.7f, 1.7f, 1.7f);
		glUniform3f(glGetUniformLocation(miShader.Program, "light2.specular"),  3.3f, 3.3f, 3.3f);
		glUniform1f(glGetUniformLocation(miShader.Program, "light2.constant"),  1.0f);
		glUniform1f(glGetUniformLocation(miShader.Program, "light2.linear"),    0.1f);
		glUniform1f(glGetUniformLocation(miShader.Program, "light2.quadratic"), 0.032);
		
		// brillantez del material
		glUniform1f(glGetUniformLocation(miShader.Program, "shininess"), 32.0f);
		
		*/
		//view matrix
//		glm::mat4 view;
		
		// para la camara trasladamos la escena entera en la direccion contraria a donde queremos movernos
		// en este caso queremos movernos hacia atras con lo cual movemos la escena en el eje Z negativamente
//		view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
		
//		view = camara.GetViewMatrix();
		
		//projection matrix
//		glm::mat4 projection;
		
		/*
		 * primer parametro es FOV (Field of view), cambiando este valor conseguimos efecto de zoom
		 * el segundo es el aspect ratio, tiene que actualizarse si se cambia el tamaño de la ventana
		 * el tercero es el near value
		 * el cuarto es el far value
		 */
//		projection = glm::perspective(glm::radians(camara.Zoom), (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f, 1000.0f);
//		glUniformMatrix4fv(glGetUniformLocation(miShader.Program, "view"), 1, GL_FALSE, glm::value_ptr(view));
//		glUniformMatrix4fv(glGetUniformLocation(miShader.Program, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
		
//		glm::mat4 model;
//		model = glm::translate(model, glm::vec3(0.0f, -2.0f, 0.0f));
//		model = glm::scale(model, glm::vec3(0.3f, 0.3f, 0.3f));
//		glUniformMatrix4fv(glGetUniformLocation(miShader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
//		modelo.Draw(miShader);
//		
//		glm::mat4 model2;
//		model2 = glm::translate(model2, glm::vec3(3.0f, -2.0f, 0.0f));
//		model2 = glm::scale(model2, glm::vec3(0.5f, 0.5f, 0.5f));
//		glUniformMatrix4fv(glGetUniformLocation(miShader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model2));
//		modelo2.Draw(miShader);
//
//		glm::mat4 model3;
//		model3 = glm::translate(model3, glm::vec3(-2.0f, -2.0f, 0.0f));
//		model3 = glm::scale(model3, glm::vec3(0.2f, 0.2f, 0.2f));
//		glUniformMatrix4fv(glGetUniformLocation(miShader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model3));
//		modelo3.Draw(miShader);
		
		escena.girar(mov_cursor);
		mov_cursor = glm::vec3();
		escena.Draw();
		
//		//linkamos el VAO
//		glBindVertexArray(VAO);
//		
//		// bucle para dibujar los 10 cubos
//		for(GLuint i = 0; i < 10; i++)
//		{
//			//model matrix propia de cada cubo
//			glm::mat4 model;
//			
//			//hacemos la traslacion a su posicion
//			model = glm::translate(model, cubePositions[i]);
//			
//			//definimos un angulo de rotacion
//			GLfloat angle = 20.0f * i;
//			model = glm::rotate(model, angle, glm::vec3(1.0f, 0.3f, 0.5f));
//			glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//			
//			//dibuja el array de vertices
//			glDrawArrays(GL_TRIANGLES, 0, 36);
//		}
//		//dibuja los elementos que indican el indice de los vertices a pintar
//		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//		
//		//deslinkamos el VAO por seguridad
//		glBindVertexArray(0);
//		
		// intercambiamos los buffers, sino no pinta NADA
		glfwSwapBuffers(window);
	}
	
//	//liberamos la memoria de los buffers y array por seguridad
//	glDeleteVertexArrays(1, &VAO);
//	glDeleteBuffers(1, &VBO);
//	glDeleteBuffers(1, &EBO);
	
	// terminamos con GLFW y borramos todos los recursos asociados a el
	glfwTerminate();
	return 0;
}

