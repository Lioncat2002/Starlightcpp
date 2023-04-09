#include "RawModel.h"

namespace Starlight {
	RawModel::RawModel(unsigned int VaoID, unsigned int vertexCount) {
		VaoId = VaoID;
		VertexCount = vertexCount;
	}
	unsigned int RawModel::getVaoId() {
		return VaoId;
	}
	unsigned int RawModel::getVertexCount() {
		return VertexCount;
	}
}