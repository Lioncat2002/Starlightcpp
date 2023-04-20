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
		RawModel loadToVAO(int length,const float *positions);
	private:
		unsigned int createVAO();
		void storeDataInAttributeList(int attributeNumber,int length,const float *data);
		void unbindVAO();
	
	};
}


