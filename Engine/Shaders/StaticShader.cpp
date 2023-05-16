#include "StaticShader.h"
namespace Starlight {
	void StaticShader::bindAttributes()
	{
		bindAttribute(0, "position");
	}
	StaticShader::StaticShader(std::string VERTEX_FILE, std::string FRAGMENT_FILE)
		:ShaderProgram(VERTEX_FILE, FRAGMENT_FILE)
	{
		
	}

}
