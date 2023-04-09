#include "Loader.h"
#include "glad/glad.h"
#include <iostream>

namespace Starlight {
	Loader::Loader() {

	}
	RawModel Loader::loadToVAO(int length,float *positions) {
		unsigned int vaoID = createVAO();
		std::cout << length;
		storeDataInAttributeList(0,length, positions);

		unbindVAO();
		return RawModel(vaoID,length/3);
	}
	unsigned int Loader::createVAO() {
		unsigned int vaoID;
		glGenVertexArrays(1,&vaoID);
		vaos.push_back(vaoID);
		glBindVertexArray(vaoID);
		return vaoID;
	}
	void Loader::storeDataInAttributeList(int attributeNumber,int length, float *data) {
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