
#include <iostream>
#include <math.h>

#define GLEW_STATIC
#include <GL/glew.h>

#include <GLFW/glfw3.h>

// dimensiones de la ventana
const GLuint WIDTH = 800, HEIGHT = 600;

// Shaders
const GLchar* vertexShaderSource = "#version 330 core\n"
	"layout (location = 0) in vec3 position;\n"
	"layout (location = 1) in vec3 color;\n"
	"out vec3 ourColor;\n"
	"void main()\n"
	"{\n"
	"gl_Position = vec4(position, 1.0);\n"
	"ourColor = color;\n"
	"}\0";

const GLchar* fragmentShaderSource = "#version 330 core\n"
	"in vec3 ourColor;\n"
	"out vec4 color;\n"
	"void main()\n"
	"{\n"
	"color = vec4(ourColor, 1.0f);\n"
	"}\0";


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	// detectamos la pulsacion de la tecla
	if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		// hacemos que se salga del bucle
		glfwSetWindowShouldClose(window, GL_TRUE);
	
	if(key == GLFW_KEY_D && action == GLFW_PRESS)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	
	if(key == GLFW_KEY_F && action == GLFW_PRESS)
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
	
	//creamos un vertex shader y recogemos su ID
	GLuint vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	
	//compilamos el vertex shader
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);
	
	//comprobamos si se ha compilado con exito
	GLint success;
	GLchar infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	
	if(!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	
	//compilamos el fragment shader
	GLuint fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	
	//comprobamos si se ha compilado con exito
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	
	if(!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	
	//creamos el programa de shaders
	GLuint shaderProgram;
	shaderProgram = glCreateProgram();
	
	//linkamos los shaders al programa y activamos este para que se use en el render
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	
	//comprobamos que se ha linkado con exito
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if(!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINK_FAILED\n" << infoLog << std::endl;
	}
	
	//borramos los shader ya que no los vamos a utilizar mas
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	
	
	
	
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
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		
		//activamos el programa para renderizar
		glUseProgram(shaderProgram);
		
		//variamos el color de la variable ourColor en el fragment shader, es una variable uniform (es global) podemos acceder a ella desde cualquier sitio del codigo
		//cogemos el tiempo actual
		GLfloat timeValue = glfwGetTime();
		//variamos el color verde entre 0.0 y -1.0
		GLfloat greenValue = (sin(timeValue) / 2) + 0.5;
		GLint vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
		glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
		
		
		
		
		//linkamos el VAO
		glBindVertexArray(VAO);
		
//		//dibuja el array de vertices
//		glDrawArrays(GL_TRIANGLES, 0, 3);

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		
		
		//deslinkamos el VAO por seguridad
		glBindVertexArray(0);
		
		// Swap the screen buffers
		glfwSwapBuffers(window);
	}
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	// Terminate GLFW, clearing any resources allocated by GLFW.
	glfwTerminate();
	
	return 0;
}


