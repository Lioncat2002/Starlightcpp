#pragma once
#include <iostream>
#include "ShaderProgram.h"
namespace Starlight {
	class StaticShader :public ShaderProgram
	{
	private:
		std::string VERTEX_FILE = "Engine//Shaders//vertex.shader";
		std::string FRAGMENT_FILE = "Engine//Shaders//fragment.shader";
	protected:
		void bindAttributes() override;
	public:
		StaticShader();
	};
}


