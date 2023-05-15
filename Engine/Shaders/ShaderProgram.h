#pragma once
#include <iostream>
#include "glad/glad.h"
namespace Starlight {
	class ShaderProgram
	{
	private:
		int programID;
		int vertexShaderID;
		int fragmentShaderID;

		static int loadShader(std::string filename, int type);
	};

}