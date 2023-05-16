#pragma once
#include "../Models/RawModel.h"
#include "glad/glad.h"
#include <iostream>
namespace Starlight {
	class Renderer
	{
	public:
		void init();
		void render(RawModel model);

	};
}


