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
		RawModel loadToVAO(int length,float *positions);
	private:
		unsigned int createVAO();
		void storeDataInAttributeList(int attributeNumber,int length, float *data);
		void unbindVAO();
	
	};
}


