
#include <iostream>
#include <math.h>
#include "Shader.h"

#define GLEW_STATIC
#include <GL/glew.h>

#include <GLFW/glfw3.h>

// dimensiones de la ventana
const GLuint WIDTH = 800, HEIGHT = 600;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	// detectamos la pulsacion de la tecla
	if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		// hacemos que se salga del bucle
		glfwSetWindowShouldClose(window, GL_TRUE);
	
	if(key == GLFW_KEY_D && action == GLFW_PRESS)
		// dibuja las figuras en wireframe
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	
	if(key == GLFW_KEY_F && action == GLFW_PRESS)
		//dibuja las figuras rellenas
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

int main(int argc, const char * argv[]) {

	glfwInit();
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	
	// creamos una ventana con glfw
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);
	if (window == nullptr)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	//seleccionamos window para que se haga la gestion sobre esta ventana
	glfwMakeContextCurrent(window);
	
	//definimos la funcion que llamaremos cuando se pulse una tecla
	glfwSetKeyCallback(window, key_callback);
	
	// activamos esto para que GLEW pueda trabajar con punteros de forma moderna, algo asi
	glewExperimental = GL_TRUE;
	
	// inicializamos GLEW
	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failed to initialize GLEW" << std::endl;
		return -1;
	}
	
	// definimos el viewport, sera el area en el que dibujamos
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);
	
	//creamos la clase Shader y compilamos los shaders
	Shader miShader("../Shaders/basico.vs", "../Shaders/basico.frag");
	
	
	GLfloat vertices[] = {
		// Positions         // Colors
		0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // Bottom Right
	   -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // Bottom Left
		0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // Top
		
	};
	GLuint indices[] = {  // Note that we start from 0!
		0, 1, 2//,   // First Triangle
		//1, 2, 3    // Second Triangle
	};
	
	//genera el vertex buffer
	GLuint VBO, VAO, EBO;
	//generamos el Vertex Array Object
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	//linkamos el VAO
	glBindVertexArray(VAO);
	
	//linkamos el buffer GL_ARRAY_BUFFER al puntero VBO
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	
	//copiamos los datos de los vertices a buffer GL_ARRAY_BUFFER
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	
	/* aqui le decimos a OpenGL como interpretar el buffer de vertices cuando tenga que dibujar
	 * el primer parametro es el indice del vertice que queremos configurar
	 * el segundo es el numero de ejes que contiene cada vertice, 1 2 3 o 4
	 * el tercero especifica el tipo de dato que vamos a manejar
	 * el cuarto indica si queremos normalizar los valores o no
	 * el quinto especifica el tamaño de que tiene cada vertice en el buffer, ahora son 3 floats
	 * el sexto es un puntero a la posicion que queremos empezar la figura, esto sirve para cuando tengamos
	 * mas de uno
	 *
	 * en la otra funcion activamos los atributos de vertices ya que estan desactivados por defecto
	 */
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	
	// atributos del color
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3* sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	
	//linkamos el buffer por su ID
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	
	//deslinkamos el VAO por seguridad
	glBindVertexArray(0);
	
	
	
	// Bucle principal
	while (!glfwWindowShouldClose(window))
	{
		// comprueba los eventos de entrada (teclado, raton...)
		glfwPollEvents();
		
		//limpia la pantalla asignando un color de fondo
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		
//		//activamos el programa para renderizar
//		glUseProgram(shaderProgram);
		miShader.Use();
		
		//linkamos el VAO
		glBindVertexArray(VAO);
		
//		//dibuja el array de vertices
//		glDrawArrays(GL_TRIANGLES, 0, 3);

		//dibuja los elementos que indican el indice de los vertices a pintar
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		
		//deslinkamos el VAO por seguridad
		glBindVertexArray(0);
		
		// intercambiamos los buffers, sino no pinta NADA
		glfwSwapBuffers(window);
	}
	
	//liberamos la memoria de los buffers y array por seguridad
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	
	// terminamos con GLFW y borramos todos los recursos asociados a el
	glfwTerminate();
	
	return 0;
}
