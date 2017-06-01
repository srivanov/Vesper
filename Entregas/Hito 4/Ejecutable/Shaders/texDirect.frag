
#version 330 core

in VS_OUT {
	vec2 TexCoord;
	vec3 FragPos;
	vec3 Normal;
	vec4 FragPosLightSpace;
	mat3 TBN;
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
uniform vec3 viewPos;
uniform int normales;

// COLORES
float colores[5] = float[](0.3,0.4,0.5,0.6,0.7);
float intensidad[5] = float[](0.05,0.25,0.5,0.75,0.9);

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

float toon(float c){
//	if(c < colores[0])
//		return colores[0];
//	else if(c < colores[1])
//		return colores[1];
//	else if(c < colores[2])
//		return colores[2];
//	else if(c < colores[3])
//		return colores[3];
//	else if(c < colores[4])
//		return colores[4];
	for (int i=0; i<5; i++) {
		if (c < intensidad[i])
			return colores[i];
	}
	return colores[4];
}

vec3 cartoonColor(float intensity, vec3 prevColor){
	vec3 color;
	
	color = vec3(toon(prevColor.r), toon(prevColor.g), toon(prevColor.b));
	
	return color;
}

void main()
{
	vec3 tex = vec3(texture(texture_diffuse1, fs_in.TexCoord));
	
	vec3 normal = vec3(0,0,0);
	if(normales == 1){
		normal = texture(texture_normal1, fs_in.TexCoord).rgb;
		normal = normalize(normal * 2.0 - 1.0);
		normal = normalize(fs_in.TBN * normal);
	}else
		normal = normalize(fs_in.Normal);
	
	// luz ambiente
	vec3 ambient = light.ambient * tex;
	// luz difusa
	vec3 lightDir = normalize(-light.direction);
	float diff = max(dot(normal, lightDir), 0.0);
	vec3 diffuse = light.diffuse * diff * tex;
	
	// luz specular
	vec3 viewDir = normalize(viewPos - fs_in.FragPos);
	vec3 reflectDir = reflect(-lightDir, normal);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);
	vec3 specular = light.specular * spec * tex;
	
	// Sombras
	float shadow = ShadowCalculation(fs_in.FragPosLightSpace);
	vec3 lighting = (ambient + (1.0 - shadow) * (diffuse + specular)) * tex;
    /*
    if(shadow >= 0.5)
        lighting = vec3(0.0);
    else
        lighting = vec3(1.0);
    */
	FragColor = vec4(lighting, 1.0f);
}


