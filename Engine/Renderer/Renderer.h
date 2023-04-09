#pragma once
#include "../Models/RawModel.h"
#include "glad/glad.h"
namespace Starlight {
	class Renderer
	{
	public:
		void init();
		void render(RawModel model);

	};
}


