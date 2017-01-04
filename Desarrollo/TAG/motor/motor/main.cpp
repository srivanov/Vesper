
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
	
	// activamos el Z-buffer
	glEnable(GL_DEPTH_TEST);
	
	//creamos la clase Shader y compilamos los shaders
	Shader miShader("../Shaders/basico.vs", "../Shaders/basico.frag");
	
	
	GLfloat vertices[] = {
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
		0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
		
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		
		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		
		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
		0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
	};
	
	GLuint indices[] = {  // Note that we start from 0!
		0, 1, 3,   // First Triangle
		1, 2, 3    // Second Triangle
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
	
	//linkamos el array de elementos al EBO
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	
	//copiamos los indices en el array de elementos
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	
	/*
	* aqui le decimos a OpenGL como interpretar el buffer de vertices cuando tenga que dibujar
	* el primer parametro es el indice del vertice que queremos configurar
	* el segundo es el numero de ejes que contiene cada vertice, 1 2 3 o 4
	* el tercero especifica el tipo de dato que vamos a manejar
	* el cuarto indica si queremos normalizar los valores o no
	* el quinto especifica el tamaño de que tiene cada vertice en el buffer, ahora son 3 floats
	* el sexto es un puntero a la posicion que queremos empezar la figura, esto sirve para cuando tengamos mas de uno
	* en la otra funcion activamos los atributos de vertices ya que estan desactivados por defecto
	*/
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	
//	// atributos del color
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3* sizeof(GLfloat)));
//	glEnableVertexAttribArray(1);
	
	// atributos de las texturas
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);
	
	//linkamos el buffer por su ID
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	
	//deslinkamos el VAO por seguridad
	glBindVertexArray(0);
	
	//cargamos la imagen desde el archivo
	int tex_width, tex_height;
	unsigned char* image = SOIL_load_image("../Textures/container.jpg", &tex_width, &tex_height, 0, SOIL_LOAD_RGB);
	
	//generamos la textura, se pueden crear varias a la vez cambiando el primer parametro de la funcion
	GLuint texture1;
	glGenTextures(1, &texture1);
	
	//linkamos la textura al objeto en el primer parametro
	glBindTexture(GL_TEXTURE_2D, texture1);
	
	// Set our texture parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// Set texture wrapping to GL_REPEAT
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// Set texture filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
	/*
	 * asignamos la imagen a la textura de OpenGL
	 * el primer argumento especifica a que textura queremos asignar la imagen
	 * el segundo indica el nivel de mipmap, se pone a 0 porque las generamos automaticamente en la siguiente linea
	 * el tercero indica el tipo en el que queremos almacenar la textura
	 * el quinto y sexto indica el ancho y alto de la imagen
	 * el siguiente siempre tiene que ser 0
	 * el septimo y octavo especifican el tipo y el formato de la imagen fuente cargada
	 * el ultimo es la imagen
	 */
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, tex_width, tex_height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	
	//hacemos que OpenGL genere el mipmap de la textura automaticamente
	glGenerateMipmap(GL_TEXTURE_2D);
	
	//liberamos la memoria de la imagen y deslinkamos el objeto de textura
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);
	
	//segunda textura
	GLuint texture2;
	glGenTextures(1, &texture2);
	glBindTexture(GL_TEXTURE_2D, texture2);
	image = SOIL_load_image("../Textures/awesomeface.png", &tex_width, &tex_height, 0, SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, tex_width, tex_height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);
	
	glm::mat4 trans;
	GLuint transformLoc, modelLoc, viewLoc, projectionLoc;
	
	// Bucle principal
	while (!glfwWindowShouldClose(window))
	{
		// comprueba los eventos de entrada (teclado, raton...)
		glfwPollEvents();
		
		//limpia la pantalla asignando un color de fondo
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		//limpiamos el buffer de color y Z-buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
//		//activamos el programa para renderizar
//		glUseProgram(shaderProgram);
		miShader.Use();
		
		glActiveTexture(GL_TEXTURE0);
		
		//linkamos la textura para dibujarla
		glBindTexture(GL_TEXTURE_2D, texture1);
		
		// asignamos al uniform ourTexture1 el sampler2D
		glUniform1i(glGetUniformLocation(miShader.Program, "ourTexture1"), 0);
		
		//hacemos lo mismo con la textura2
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, texture2);
		glUniform1i(glGetUniformLocation(miShader.Program, "ourTexture2"), 1);
		/*
			//inicializo la matriz
			trans = glm::mat4();
			
			//aplico traslacion
			trans = glm::translate(trans, glm::vec3(0.5f, -0.5f, 0.0f));
			
			//aplico rotacion
			trans = glm::rotate(trans, (GLfloat)glfwGetTime() * 50.0f, glm::vec3(0.0f, 0.0f, 1.0f));
			
			//recojo el ID del uniform
			transformLoc = glGetUniformLocation(miShader.Program, "transform");
			
			//le asigno al uniform el valor de la matriz 'trans'
			glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));
		*/
		
		//model matrix
		glm::mat4 model;
		model = glm::rotate(model, (GLfloat)glfwGetTime() * 1.0f, glm::vec3(0.5f, 1.0f, 0.0f));
		
		//view matrix
		glm::mat4 view;
		
		// para la camara trasladamos la escena entera en la direccion contraria a donde queremos movernos
		// en este caso queremos movernos hacia atras con lo cual movemos la escena en el eje Z negativamente
		view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
		
		//projection matrix
		glm::mat4 projection;
		
		/*
		 * primer parametro es FOV (Field of view), cambiando este valor conseguimos efecto de zoom
		 * el segundo es el aspect ratio, tiene que actualizarse si se cambia el tamaño de la ventana
		 * el tercero es el near value
		 * el cuarto es el far value
		 */
		projection = glm::perspective(45.0f, (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f, 100.0f);
		
		modelLoc = glGetUniformLocation(miShader.Program, "model");
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		viewLoc = glGetUniformLocation(miShader.Program, "view");
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		projectionLoc = glGetUniformLocation(miShader.Program, "projection");
		glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
		
		
		//linkamos el VAO
		glBindVertexArray(VAO);
		
		//dibuja el array de vertices
		glDrawArrays(GL_TRIANGLES, 0, 36);

//		//dibuja los elementos que indican el indice de los vertices a pintar
//		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		
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

