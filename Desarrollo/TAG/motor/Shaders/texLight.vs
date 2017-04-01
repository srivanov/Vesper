
#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texCoord;

out vec2 TexCoord;
out vec3 FragPos;
out vec3 Normal;

uniform mat4 model;
//uniform mat4 view;
//uniform mat4 projection;
uniform mat4 MVP;

void main()
{
	gl_Position = MVP * vec4(position, 1.0);
	
	//asignamos las coordenadas de las texturas dando la vuelta al eje Y
	TexCoord = vec2(texCoord.x, 1.0f - texCoord.y);
//	Normal = normalize(transpose(inverse(mat3(model))) * normal);
	Normal = normal;
	//posicion en coordenadas del mundo del fragment
	FragPos = vec3(model * vec4(position, 1.0f));
}
