#pragma once
#include <iostream>
#include "ShaderProgram.h"
namespace Starlight {
	class StaticShader :public ShaderProgram
	{
	private:
		
	protected:
		void bindAttributes() override;
		
	public:
		StaticShader(std::string VERTEX_FILE, std::string FRAGMENT_FILE);
	};
}


