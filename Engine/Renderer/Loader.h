#pragma once
#include "../Models/RawModel.h"
#include <vector>
#include "glad/glad.h"
#include <iostream>



namespace Starlight {
	class Loader
	{
	public:
		
		std::vector<unsigned int> vaos;
		std::vector<unsigned int> vbos;
		std::vector<unsigned int> textures;
		Loader();
		~Loader();
		unsigned int loadTexture(const char* fileName);
		RawModel loadToVAO(const int positions_length, const float *positions, const int indices_length, const int* indices, const int tex_length, const float* texture);
	private:
		unsigned int createVAO();
		void bindIndicesBuffer(int length,const int* indices);
		void storeDataInAttributeList(int attributeNumber,int length,const float *data);
		void unbindVAO();
	
	};
}


