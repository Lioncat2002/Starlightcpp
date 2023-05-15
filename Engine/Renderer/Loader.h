#pragma once
#include "../Models/RawModel.h"
#include <vector>
namespace Starlight {
	class Loader
	{
	public:
		
		std::vector<unsigned int> vaos;
		std::vector<unsigned int> vbos;
		Loader();
		~Loader();
		RawModel loadToVAO(const int positions_length, const float *positions, const int indices_length, const int* indices);
	private:
		unsigned int createVAO();
		void bindIndicesBuffer(int length,const int* indices);
		void storeDataInAttributeList(int attributeNumber,int length,const float *data);
		void unbindVAO();
	
	};
}


