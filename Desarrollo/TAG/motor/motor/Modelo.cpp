
#include "Modelo.hpp"

Modelo::Modelo(GLchar* ruta){
	loadModel(ruta);
}

void Modelo::Draw(Shader shader){
//	std::vector<Mesh>::iterator it = meshes.begin();
//	while(it != meshes.end()){
//		it->Draw(shader);
//		it++;
//	}
	
	for (GLuint i=0; i<this->meshes.size(); i++)
		this->meshes[i].Draw(shader);
}

void Modelo::loadModel(std::string ruta){
	Assimp::Importer importer;
	const aiScene* scene = importer.ReadFile(ruta, aiProcess_Triangulate);
	
	if(!scene || scene->mFlags == AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode){
		std::cout << "ERROR::ASSIMP::" << importer.GetErrorString() << std::endl;
	}
	this->directorio = ruta.substr(0, ruta.find_last_of('/'));
	this->processNode(scene->mRootNode, scene);
}

void Modelo::processNode(aiNode *node, const aiScene *scene){
	
	for (GLuint i=0; i<node->mNumMeshes; i++) {
		//cojo de la escena entera los meshes del nodo
		aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
		this->meshes.push_back(this->processMesh(mesh, scene));
	}
	
	for (GLuint i=0; i<node->mNumChildren; i++) {
		this->processNode(node->mChildren[i], scene);
	}
	
}

Mesh Modelo::processMesh(aiMesh *mesh, const aiScene *scene){
	
	std::vector<Vertex> vertices;
	std::vector<GLuint> indices;
	std::vector<Texture> texturas;
	
	for (GLuint i=0; i<mesh->mNumVertices; i++){
		Vertex vertex;
		
		// Process vertex positions, normals and texture coordinates
		glm::vec3 vector;
		vector.x = mesh->mVertices[i].x;
		vector.y = mesh->mVertices[i].y;
		vector.z = mesh->mVertices[i].z;
		vertex.Position = vector;
		
		vector.x = mesh->mNormals[i].x;
		vector.y = mesh->mNormals[i].y;
		vector.z = mesh->mNormals[i].z;
		
		if(mesh->mTextureCoords[0]){
			glm::vec2 vec;
			vec.x = mesh->mTextureCoords[0][i].x;
			vec.y = mesh->mTextureCoords[0][i].y;
			vertex.TexCoords = vec;
		}
		else
			vertex.TexCoords = glm::vec2(0.0f, 0.0f);
		
		vertices.push_back(vertex);
	}
	
	for(GLuint i = 0; i < mesh->mNumFaces; i++){
		aiFace face = mesh->mFaces[i];
		for (GLuint j=0; j<face.mNumIndices; j++)
			indices.push_back(face.mIndices[j]);
	}
	
	if(mesh->mMaterialIndex > 0)
	{
		aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];
		// We assume a convention for sampler names in the shaders. Each diffuse texture should be named
		// as 'texture_diffuseN' where N is a sequential number ranging from 1 to MAX_SAMPLER_NUMBER.
		// Same applies to other texture as the following list summarizes:
		// Diffuse: texture_diffuseN
		// Specular: texture_specularN
		// Normal: texture_normalN
		
		// 1. Diffuse maps
		std::vector<Texture> diffuseMaps = this->loadMaterialTextures(material, aiTextureType_DIFFUSE, "texture_diffuse");
		texturas.insert(texturas.end(), diffuseMaps.begin(), diffuseMaps.end());
		
		// 2. Specular maps
		std::vector<Texture> specularMaps = this->loadMaterialTextures(material, aiTextureType_SPECULAR, "texture_specular");
		texturas.insert(texturas.end(), specularMaps.begin(), specularMaps.end());
	}
	return Mesh(vertices, indices, texturas);
}

std::vector<Texture> Modelo::loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName){
	std::vector<Texture> textures;
	for(GLuint i = 0; i < mat->GetTextureCount(type); i++)
	{
		aiString str;
		mat->GetTexture(type, i, &str);
		Texture texture;
		texture.id = TextureFromFile(str.C_Str(), this->directorio);
		texture.type = typeName;
		texture.path = str.C_Str();
		textures.push_back(texture);
	}
	return textures;
}

GLuint Modelo::TextureFromFile(const char *ruta, std::string directorio){
	std::string filename = std::string(ruta);
	filename = directorio + '/' + filename;
	GLuint textureID;
	
	//generamos la textura en OpenGL
	glGenTextures(1, &textureID);
	int tex_width, tex_height;
	
	//cargamos la imagen desde el archivo
	unsigned char* image = SOIL_load_image(filename.c_str(), &tex_width, &tex_height, 0, SOIL_LOAD_RGB);
	
	//linkamos la textura al objeto en el primer parametro
	glBindTexture(GL_TEXTURE_2D, textureID);
	
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
	
	// poniendo ajustes para la textura si nos salimos para que se repita
	// o lo que queramos que haga
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	
	// Set texture filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);
	return textureID;
}




