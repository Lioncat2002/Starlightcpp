#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "glad/glad.h"
namespace Starlight {
	class ShaderProgram
	{
	
	protected:
		virtual void bindAttributes();
		void bindAttribute(int attribute,std::string variable);
	private:
		int programID;
		int vertexShaderID;
		int fragmentShaderID;

		static int loadShader(std::string filename, int type);
	public:
		ShaderProgram(std::string VERTEXFILE, std::string FRAGMENTFILE);
		void init();
		void dispose();
		void clean();
	};

}