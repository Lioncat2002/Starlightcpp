#pragma once
namespace Starlight {
	class RawModel
	{
	private:
		unsigned int VaoId;
		unsigned int VertexCount;
	public:
		RawModel(unsigned int VaoID,unsigned int vertexCount);
		unsigned int getVaoId();
		unsigned int getVertexCount();
	
	};
}


