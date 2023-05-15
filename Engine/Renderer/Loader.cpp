#include "Loader.h"
#include "glad/glad.h"
#include <iostream>

namespace Starlight {
	Loader::Loader() {

	}
	RawModel Loader::loadToVAO(const int positions_length,const float *positions,const int indices_length,const int *indices) {
		unsigned int vaoID = createVAO();
		bindIndicesBuffer(indices_length,indices);
		storeDataInAttributeList(0,positions_length, positions);

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
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, length * sizeof(float), indices, GL_STATIC_DRAW);
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
	}
}