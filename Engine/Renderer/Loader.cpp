#include "Loader.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
namespace Starlight {
	Loader::Loader() {

	}
	unsigned int Loader::loadTexture(const char* fileName) {
		unsigned int textureID;
		glGenTextures(1, &textureID);
		glBindTexture(GL_TEXTURE_2D, textureID);
		//set the texture wrapping/filtering options
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		
		//load and generate the texture
		int width, height, nrChannels;
		unsigned char* data = stbi_load(fileName, &width, &height, &nrChannels, 0);
		if (data) {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else {
			std::cout << "Failed to load texture\n";
		}
		
		textures.push_back(textureID);
		stbi_image_free(data);
		return textureID;
	}
	RawModel Loader::loadToVAO(const int positions_length,const float *positions,const int indices_length,const int *indices,const int tex_length,const float *texture) {
		unsigned int vaoID = createVAO();
		bindIndicesBuffer(indices_length,indices);
		storeDataInAttributeList(0,positions_length, positions);
		storeDataInAttributeList(1,tex_length,texture);
		unbindVAO();
		return RawModel(vaoID,indices_length);
	}
	unsigned int Loader::createVAO() {
		unsigned int vaoID;
		glGenVertexArrays(1,&vaoID);
		vaos.push_back(vaoID);
		glBindVertexArray(vaoID);
		return vaoID;
	}
	void Loader::bindIndicesBuffer(int length,const int* indices) {
		unsigned int vboID;
		glGenBuffers(1, &vboID);
		vbos.push_back(vboID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, length * sizeof(int), indices, GL_STATIC_DRAW);
	}
	void Loader::storeDataInAttributeList(int attributeNumber,int length,const float *data) {
		unsigned int vboID;
		glGenBuffers(1, &vboID);
		vbos.push_back(vboID);
		glBindBuffer(GL_ARRAY_BUFFER, vboID);
		glBufferData(GL_ARRAY_BUFFER, length * sizeof(float), data, GL_STATIC_DRAW);
		glVertexAttribPointer(attributeNumber,3,GL_FLOAT,GL_FALSE,0,NULL);
	}
	void Loader::unbindVAO() {
		glBindVertexArray(0);
	}
	Loader::~Loader() {
		for (unsigned int vao:vaos) {
			glDeleteVertexArrays(1, &vao);
		}
		for (unsigned int vbo : vbos) {
			glDeleteBuffers(1, &vbo);
		}
		for (unsigned int tex : textures) {
			glDeleteTextures(1, &tex);
		}
	}
}