
#version 330 core

//estructura de una luz
struct Light {
	vec3 position;
	
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	
	float constant;
	float linear;
	float quadratic;
};


in vec2 TexCoord;
in vec3 FragPos;
in vec3 Normal;

out vec4 color;

uniform sampler2D texture_diffuse1;
uniform sampler2D texture_specular1;
uniform Light light;
uniform Light light2;
uniform float shininess;
uniform vec3 viewPos;

void main()
{
	
	// luz ambiente
	vec3 ambient = light.ambient * vec3(texture(texture_diffuse1, TexCoord));
	
	// luz difusa
	vec3 norm = normalize(Normal);
	vec3 lightDir = normalize(light.position - FragPos);
	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = light.diffuse * diff * vec3(texture(texture_diffuse1, TexCoord));
	
	vec3 diffuse2 = light2.diffuse * max(dot(norm, normalize(light2.position - FragPos)), 0.0) * vec3(texture(texture_diffuse1, TexCoord));
	
	// luz specular
	vec3 viewDir = normalize(viewPos - FragPos);
	vec3 reflectDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);
	vec3 specular = light.specular * spec * vec3(texture(texture_diffuse1, TexCoord));
	
	vec3 specular2 = light2.specular * pow(max(dot(viewDir, reflect(-normalize(light2.position - FragPos), norm)), 0.0), shininess) * vec3(texture(texture_diffuse1, TexCoord));
	
	// atenuacion
	float distance = length(light.position - FragPos);
	float attenuation = 1.0f / (light.constant + light.linear * distance + light.quadratic * (distance * distance));
	
	diffuse  *= attenuation;
	diffuse2  *= attenuation;
//	ambient  *= attenuation;
	specular  *= attenuation;
	specular2  *= attenuation;
	
	color = vec4(diffuse + diffuse2 + ambient + specular + specular2, 1.0f);
}
