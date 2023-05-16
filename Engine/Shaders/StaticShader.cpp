#include "StaticShader.h"
namespace Starlight {
	void StaticShader::bindAttributes()
	{
		bindAttribute(0, "position");
	}
	StaticShader::StaticShader()
	{
		ShaderProgram(VERTEX_FILE,FRAGMENT_FILE);
	}

}
