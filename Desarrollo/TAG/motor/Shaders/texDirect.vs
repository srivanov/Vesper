
#version 330 core

// TEXTURAS CON LUZ DIRECCIONAL

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texCoord;
layout (location = 3) in vec3 tangent;
layout (location = 4) in vec3 bitangent;

out VS_OUT{
	vec2 TexCoord;
	vec3 FragPos;
	vec3 Normal;
	vec4 FragPosLightSpace;
	mat3 TBN;
} vs_out;


uniform mat4 model;
uniform mat4 MVP;
uniform mat4 lightspaceMatrix;

void main()
{
	gl_Position = MVP * vec4(position, 1.0);
	
	//asignamos las coordenadas de las texturas dando la vuelta al eje Y
	vs_out.TexCoord = vec2(texCoord.x, 1.0f - texCoord.y);
	
	//posicion en coordenadas del mundo del fragment
	vs_out.FragPos = vec3(model * vec4(position, 1.0f));
	
//		vs_out.Normal = normalize(transpose(inverse(mat3(model))) * normal);
	vs_out.Normal = normal;
	
	vs_out.FragPosLightSpace = lightspaceMatrix * vec4(vs_out.FragPos, 1.0);
	
	vec3 T = normalize(vec3(model * vec4(tangent,   0.0)));
	vec3 N = normalize(vec3(model * vec4(normal,    0.0)));
	// re-orthogonalize T with respect to N
	T = normalize(T - dot(T, N) * N);
	// then retrieve perpendicular vector B with the cross product of T and N
	vec3 B = cross(N, T);
	
	vs_out.TBN = mat3(T, B, N);
}

