
#version 330 core

in VS_OUT {
	vec2 TexCoord;
	vec3 FragPos;
	vec3 Normal;
	vec4 FragPosLightSpace;
	vec3 TangentLightPos;
	vec3 TangentViewPos;
	vec3 TangentFragPos;
} fs_in;

out vec4 FragColor;

uniform sampler2D texture_diffuse1;
uniform sampler2D texture_specular1;
uniform sampler2D texture_normal1;
uniform sampler2D shadowMap;

struct Light {
	vec3 position;
	
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	vec3 color;
	vec3 direction;
	
	float constant;
	float linear;
	float quadratic;
};

uniform Light light;
uniform float shininess;

float ShadowCalculation(vec4 fragPosLightSpace)
{
	// perform perspective divide
	vec3 projCoords = fragPosLightSpace.xyz / fragPosLightSpace.w;
	// Transform to [0,1] range
	projCoords = projCoords * 0.5 + 0.5;
	// Get closest depth value from light's perspective (using [0,1] range fragPosLight as coords)
	float closestDepth = texture(shadowMap, projCoords.xy).r;
	// Get depth of current fragment from light's perspective
	float currentDepth = projCoords.z;
	vec3 normal = normalize(fs_in.Normal);
	vec3 lightDir = normalize(-light.direction);
	float bias = 0.0001 * tan(acos(dot(normal, lightDir)));
	bias = clamp(bias, 0, 0.01);
	// Check whether current frag pos is in shadow
//	float bias = max(0.000005 * (dot(normal, lightDir)), 0.000002);
//    float bias = 0.00000002;
//	float shadow = currentDepth - bias > closestDepth  ? 1.0 : 0.0;
	
    // PCF
	float shadow = 0.0;
	vec2 texelSize = 1.0 / textureSize(shadowMap, 0);
	for(int x = -1; x <= 1; ++x)
	{
		for(int y = -1; y <= 1; ++y)
		{
			float pcfDepth = texture(shadowMap, projCoords.xy + vec2(x, y) * texelSize).r;
			shadow += currentDepth > pcfDepth  ? 1.0 : 0.0;
		}
	}
	shadow /= 9.0;
	
//    float shadow = currentDepth - bias > closestDepth  ? 1.0 : 0.0;
	
    //si se sale del plano de proyeccion de la luz
	if(projCoords.z > 1.0)
		shadow = 0.0;
	
	return shadow;
}

void main()
{
	vec3 tex = vec3(texture(texture_diffuse1, fs_in.TexCoord));

	vec3 normal = texture(texture_normal1, fs_in.TexCoord).rgb;
	normal = normalize(normal * 2.0 - 1.0);
	
	// luz ambiente
	vec3 ambient = light.ambient * tex;
	
	// luz difusa
	vec3 lightDir = normalize(fs_in.TangentLightPos - fs_in.TangentFragPos);
	float diff = max(dot(normal, lightDir), 0.0);
	vec3 diffuse = light.diffuse * diff * tex;
	
	// luz specular
	vec3 viewDir = normalize(fs_in.TangentViewPos - fs_in.TangentFragPos);
	vec3 reflectDir = reflect(-lightDir, normal);
	float spec = 0.0;
	
	spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);
	vec3 specular = light.specular * spec * tex;
	
	// Sombras
	float shadow = ShadowCalculation(fs_in.FragPosLightSpace);
	vec3 lighting = (ambient + (1.0 - shadow) * (diffuse + specular)) * tex;
	
	FragColor = vec4(lighting, 1.0f);
}


